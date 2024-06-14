module DCT_Component (
    input clk,
    input reset,
    input [3:0] address,
    input signed [31:0] writedata,
    input write,
    input read,
    input chipselect,
    output reg signed [31:0] readdata
);

    // Parameters for DCT coefficients and shift values
    parameter signed [31:0] c1 = 1420;
    parameter signed [31:0] c2 = 1338;
    parameter signed [31:0] c3 = 1204;
    parameter signed [31:0] c5 = 805;
    parameter signed [31:0] c6 = 554;
    parameter signed [31:0] c7 = 283;
    parameter s1 = 3;
    parameter s2 = 10;
    parameter s3 = 13; 

    // Registers for data storage
    reg signed [31:0] data1, data2, data3, data4, data5, data6, data7, data8;
    wire signed [31:0] result1, result2, result3, result4, result5, result6, result7, result8;
    wire signed [31:0] result1_, result2_, result3_, result4_, result5_, result6_, result7_, result8_;
    wire signed [31:0] x0, x1, x2, x3, x4, x5, x6, x7, x8;
    wire signed [31:0] x5_out, x8_out, x7_out;

    // Instantiate Stage Modules
    DCT_Stage1 stage1(
        .data1(data1), .data2(data2), .data3(data3), .data4(data4),
        .data5(data5), .data6(data6), .data7(data7), .data8(data8),
        .x0(x0), .x1(x1), .x2(x2), .x3(x3), .x5(x5), .x6(x6), .x7(x7), .x8(x8)
    );

    DCT_Stage2 stage2(
        .x8(x8), .x5(x5), .x7(x7), .x6(x6),
        .x4(x4), .x5_out(x5_out), .x8_out(x8_out), .x7_out(x7_out)
    );

    DCT_Stage3 stage3(
        .x4(x4), .x5_out(x5_out),
        .result1(result1), .result5(result5)
    );

    DCT_Stage3Col stage3col(
        .x4(x4), .x5_out(x5_out),
        .result1_(result1_), .result5_(result5_)
    );

    DCT_Stage4 stage4(
        .x0(x0), .x1(x1), .x2(x2), .x3(x3), .x8_out(x8_out), .x7_out(x7_out),
        .result3(result3), .result7(result7), .result8(result8), .result6(result6), .result4(result4), .result2(result2)
    );

    DCT_Stage4Col stage4col(
        .x0(x0), .x1(x1), .x2(x2), .x3(x3), .x8_out(x8_out), .x7_out(x7_out),
        .result3_(result3_), .result7_(result7_), .result8_(result8_), .result6_(result6_), .result4_(result4_), .result2_(result2_)
    );

    // Main computation and control
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            // Reset state
            data1 <= 0;
            data2 <= 0;
            data3 <= 0;
            data4 <= 0;
            data5 <= 0;
            data6 <= 0;
            data7 <= 0;
            data8 <= 0;
            readdata <= 0;
        end else begin
            // Write operation
            if (write && chipselect) begin
                case (address)
                    4'b0000: data1 <= writedata;
                    4'b0001: data2 <= writedata;
                    4'b0010: data3 <= writedata;
                    4'b0011: data4 <= writedata;
                    4'b0100: data5 <= writedata;
                    4'b0101: data6 <= writedata;
                    4'b0110: data7 <= writedata;
                    4'b0111: data8 <= writedata;
                endcase
            end
            
            // Read operation
            if (read && chipselect) begin
                case (address)
                    4'b0000: readdata <= result1;
                    4'b0001: readdata <= result2;
                    4'b0010: readdata <= result3;
                    4'b0011: readdata <= result4;
                    4'b0100: readdata <= result5;
                    4'b0101: readdata <= result6;
                    4'b0110: readdata <= result7;
                    4'b0111: readdata <= result8;

                    4'b1000: readdata <= result1_;
                    4'b1001: readdata <= result2_;
                    4'b1010: readdata <= result3_;
                    4'b1011: readdata <= result4_;
                    4'b1100: readdata <= result5_;
                    4'b1101: readdata <= result6_;
                    4'b1110: readdata <= result7_;
                    4'b1111: readdata <= result8_;

                endcase
            end

            // readdata <= result1;
        end
    end


    // // print the data
    // always @(data1 or data2 or data3 or data4 or data5 or data6 or data7 or data8) begin
    //     $display("data1 = %d, data2 = %d, data3 = %d, data4 = %d, data5 = %d, data6 = %d, data7 = %d, data8 = %d", data1, data2, data3, data4, data5, data6, data7, data8);
    //     // $display("result1 = %d, result2 = %d, result3 = %d, result4 = %d, result5 = %d, result6 = %d, result7 = %d, result8 = %d", result1, result2, result3, result4, result5, result6, result7, result8);
    // end

    // // 1stage module
    // always @(x0 or x1 or x2 or x3 or x5 or x6 or x7 or x8) begin
    //     $display("x0 = %d, x1 = %d, x2 = %d, x3 = %d, x5 = %d, x6 = %d, x7 = %d, x8 = %d", x0, x1, x2, x3, x5, x6, x7, x8);
    // end

    // // 2stage module
    // always @(x4 or x5_out or x7_out or x8_out) begin
    //     $display("x4 = %d, x5 = %d, x8 = %d, x7 = %d", x4, x5_out, x8_out, x7_out);
    // end

    // // 3stage module
    // always @(result1 or result5) begin
    //     $display("result1 = %d, result5 = %d", result1, result5);
    // end

    // // 4stage module
    // always @(result2 or result3 or result4 or result6 or result7 or result8) begin
    //     $display("result2 = %d, result3 = %d, result4 = %d, result6 = %d, result7 = %d, result8 = %d", result2, result3, result4, result6, result7, result8);
    // end

defparam stage4.c1 = c1;
defparam stage4.c2 = c2;
defparam stage4.c3 = c3;
defparam stage4.c5 = c5;
defparam stage4.c6 = c6;
defparam stage4.c7 = c7;
defparam stage4.s1 = s1;
defparam stage4.s2 = s2;
defparam stage4.s3 = s3;

defparam stage4col.c1 = c1;
defparam stage4col.c2 = c2;
defparam stage4col.c3 = c3;
defparam stage4col.c5 = c5;
defparam stage4col.c6 = c6;
defparam stage4col.c7 = c7;
defparam stage4col.s1 = s1;
defparam stage4col.s2 = s2;
defparam stage4col.s3 = s3;

defparam stage3col.s1 = s1;
defparam stage3col.s2 = s2;
defparam stage3col.s3 = s3;

endmodule




module DCT_Stage1(
    input signed [31:0] data1, data2, data3, data4, data5, data6, data7, data8,
    output reg signed [31:0] x0, x1, x2, x3, x5, x6, x7, x8
);
    always @(*) begin

        // #1
        x8 = data1 + data8;
        x0 = data1 - data8;
        x7 = data2 + data7;
        x1 = data2 - data7;
        x6 = data3 + data6;
        x2 = data3 - data6;
        x5 = data4 + data5;
        x3 = data4 - data5;
    end
endmodule


module DCT_Stage2(
    input signed [31:0] x8, x5, x7, x6,
    output reg signed [31:0] x4, x5_out, x8_out, x7_out
);
    always @(*) begin
        // #1
        x4 = x8 + x5;
        x8_out = x8 - x5;
        x5_out = x7 + x6;
        x7_out = x7 - x6;
    end
endmodule


module DCT_Stage3(
    input signed [31:0] x4, x5_out,
    output reg signed [31:0] result1, result5
);
    always @(*) begin
        // #1
        result1 = x4 + x5_out;
        result5 = x4 - x5_out;
    end
endmodule

module DCT_Stage3Col(
    input signed [31:0] x4, x5_out,
    output reg signed [31:0] result1_, result5_
);
    parameter s1 = 3;
    parameter s2 = 10;
    parameter s3 = 13; 

    always @(*) begin
        // #1
        result1_ = (x4 + x5_out) >>> s1;
        result5_ = (x4 - x5_out) >>> s1;
    end
endmodule


module DCT_Stage4(
    input signed [31:0] x0, x1, x2, x3, x8_out, x7_out,
    output reg signed [31:0] result3, result7, result8, result6, result4, result2
);
    // Parameters for DCT coefficients and shift values
    parameter signed [31:0] c1 = 1420;
    parameter signed [31:0] c2 = 1338;
    parameter signed [31:0] c3 = 1204;
    parameter signed [31:0] c5 = 805;
    parameter signed [31:0] c6 = 554;
    parameter signed [31:0] c7 = 283;
    parameter s1 = 3;
    parameter s2 = 10;
    parameter s3 = 13; 

    always @(*) begin
        // #1
        
        result3 = (x8_out * c2 + x7_out * c6) >>> s2;
        result7 = (x8_out * c6 - x7_out * c2) >>> s2;
        result8 = (x0 * c7 - x1 * c5 + x2 * c3 - x3 * c1) >>> s2;
        result6 = (x0 * c5 - x1 * c1 + x2 * c7 + x3 * c3) >>> s2;
        result4 = (x0 * c3 - x1 * c7 - x2 * c1 - x3 * c5) >>> s2;
        result2 = (x0 * c1 + x1 * c3 + x2 * c5 + x3 * c7) >>> s2;
    end
endmodule

module DCT_Stage4Col(
    input signed [31:0] x0, x1, x2, x3, x8_out, x7_out,
    output reg signed [31:0] result3_, result7_, result8_, result6_, result4_, result2_
);
    // Parameters for DCT coefficients and shift values
    parameter signed [31:0] c1 = 1420;
    parameter signed [31:0] c2 = 1338;
    parameter signed [31:0] c3 = 1204;
    parameter signed [31:0] c5 = 805;
    parameter signed [31:0] c6 = 554;
    parameter signed [31:0] c7 = 283;
    parameter s1 = 3;
    parameter s2 = 10;
    parameter s3 = 13; 

    always @(*) begin
        // #1
        
        result3_ = (x8_out * c2 + x7_out * c6) >>> s3;
        result7_ = (x8_out * c6 - x7_out * c2) >>> s3;
        result8_ = (x0 * c7 - x1 * c5 + x2 * c3 - x3 * c1) >>> s3;
        result6_ = (x0 * c5 - x1 * c1 + x2 * c7 + x3 * c3) >>> s3;
        result4_ = (x0 * c3 - x1 * c7 - x2 * c1 - x3 * c5) >>> s3;
        result2_ = (x0 * c1 + x1 * c3 + x2 * c5 + x3 * c7) >>> s3;
    end
endmodule

