module DCT_Component (
    input clk,
    input reset,
    input [2:0] address,  // Adjusted address width to 3 bits
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
    reg signed [31:0] result1, result2, result3, result4, result5, result6, result7, result8;
    reg signed [31:0] x0, x1, x2, x3, x4, x5, x6, x7, x8;

    // DCT computation
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
            result1 <= 0;
            result2 <= 0;
            result3 <= 0;
            result4 <= 0;
            result5 <= 0;
            result6 <= 0;
            result7 <= 0;
            result8 <= 0;
            x0 <= 0;
            x1 <= 0;
            x2 <= 0;
            x3 <= 0;
            x4 <= 0;
            x5 <= 0;
            x6 <= 0;
            x7 <= 0;
            x8 <= 0;
        end else begin
            // Write operation
            if (write && chipselect) begin
                case (address)
                    3'b000: data1 <= writedata;
                    3'b001: data2 <= writedata;
                    3'b010: data3 <= writedata;
                    3'b011: data4 <= writedata;
                    3'b100: data5 <= writedata;
                    3'b101: data6 <= writedata;
                    3'b110: data7 <= writedata;
                    3'b111: data8 <= writedata;
                endcase
            end

            // Read operation
            if (read && chipselect) begin
                case (address)
                    3'b000: readdata <= result1;
                    3'b001: readdata <= result2;
                    3'b010: readdata <= result3;
                    3'b011: readdata <= result4;
                    3'b100: readdata <= result5;
                    3'b101: readdata <= result6;
                    3'b110: readdata <= result7;
                    3'b111: readdata <= result8;
                endcase
            end
        end
    end

    // DCT computation (continued)
    // Computation of x0 to x8 and results 1 to 8 would be here...

    always @( data8)begin
        #1

            // $display("wri %d %d", writedata, address);
            // $display("Data1: %d, Data2: %d, Data3: %d, Data4: %d, Data5: %d, Data6: %d, Data7: %d, Data8: %d", data1, data2, data3, data4, data5, data6, data7, data8);

            // Stage 1
            x8 <= data1 + data8;
            x0 <= data1 - data8;
            x7 <= data2 + data7;
            x1 <= data2 - data7;
            x6 <= data3 + data6;

            #1

            x2 <= data3 - data6;
            x5 <= data4 + data5;
            x3 <= data4 - data5;

            #1

            // $display("x0: %d, x1: %d, x2: %d, x3: %d, x4: %d, x5: %d, x6: %d, x7: %d, x8: %d", x0, x1, x2, x3, x4, x5, x6, x7, x8);
            // Stage 2
            x4 <= x8 + x5;
            x8 <= x8 - x5;
            x5 <= x7 + x6;
            x7 <= x7 - x6;

            #1


            // $display("x0: %d, x1: %d, x2: %d, x3: %d, x4: %d, x5: %d, x6: %d, x7: %d, x8: %d", x0, x1, x2, x3, x4, x5, x6, x7, x8);

            // Stage 3
            result1 <= x4 + x5;
            result5 <= x4 - x5;

            #1
            // Stage 4
            result3 <= (x8 * c2 + x7 * c6) >>> s2;
            result7 <= (x8 * c6 - x7 * c2) >>> s2;
            result8 <= (x0 * c7 - x1 * c5 + x2 * c3 - x3 * c1) >>> s2;
            result6 <= (x0 * c5 - x1 * c1 + x2 * c7 + x3 * c3) >>> s2;
            result4 <= (x0 * c3 - x1 * c7 - x2 * c1 - x3 * c5) >>> s2;
            result2 <= (x0 * c1 + x1 * c3 + x2 * c5 + x3 * c7) >>> s2;

            // #5
            // $display("Result1: %d, Result2: %d, Result3: %d, Result4: %d, Result5: %d, Result6: %d, Result7: %d, Result8: %d", result1, result2, result3, result4, result5, result6, result7, result8);
    end

endmodule
