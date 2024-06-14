`timescale 1ns / 1ps
`include "DCT_Component.v"

module DCT_Component_tb;

    // Declare signals for DUT ports
    reg clk;
    reg reset;
    reg [2:0] address; // Adjust address width to match the DUT
    reg [31:0] writedata;
    reg write;
    reg read;
    reg chipselect;
    wire signed [31:0] readdata;

    // Instantiate DUT (Device Under Test)
    DCT_Component dut (
        .clk(clk),
        .reset(reset),
        .address(address),
        .writedata(writedata),
        .write(write),
        .read(read),
        .chipselect(chipselect),
        .readdata(readdata)
    );

    // Clock generation
    always #(5) clk = ~clk;

    // Initial reset
    initial begin
        clk = 0;
        reset = 1;
        write = 0;
        read = 0;
        chipselect = 0;
        address = 3'b000;
        writedata = 0;
        #20; // Increase reset duration to ensure proper reset
        reset = 0;
    end

    // Stimulus generation
    initial begin
        // Write operation example
        #30;
        writedata = 1; // Example data to write
        write = 1;
        read = 0;
        chipselect = 1;
        address = 3'b000; // Address for data1
        #10;
        write = 0;

        #10;
        writedata = 2; // Example data to write
        write = 1;
        read = 0;
        chipselect = 1;
        address = 3'b001; // Address for data2
        #10;
        write = 0;

        #10;
        writedata = 3; // Example data to write
        write = 1;
        read = 0;
        chipselect = 1;
        address = 3'b010; // Address for data3
        #10;
        write = 0;

        #10;
        writedata = 4; // Example data to write
        write = 1;
        read = 0;
        chipselect = 1;
        address = 3'b011; // Address for data4
        #10;
        write = 0;

        #10;
        writedata = 5; // Example data to write
        write = 1;
        read = 0;
        chipselect = 1;
        address = 3'b100; // Address for data5
        #10;
        write = 0;

        #10;
        writedata = 6; // Example data to write
        write = 1;
        read = 0;
        chipselect = 1;
        address = 3'b101; // Address for data6
        #10;
        write = 0;

        #10;
        writedata = 7; // Example data to write
        write = 1;
        read = 0;
        chipselect = 1;
        address = 3'b110; // Address for data7
        #10;
        write = 0;

        #10;
        writedata = 8; // Example data to write
        write = 1;
        read = 0;
        chipselect = 1;
        address = 3'b111; // Address for data8
        #10;
        write = 0;

        // Read operation example
        #20;
        read = 1;
        write = 0;
        chipselect = 1;
        address = 3'b000; // Address for data1
        #10;
        read = 0;

        #10;
        read = 1;
        address = 3'b001; // Address for data2
        #10;
        read = 0;

        #10;
        read = 1;
        address = 3'b010; // Address for data3
        #10;
        read = 0;

        #10;
        read = 1;
        address = 3'b011; // Address for data4
        #10;
        read = 0;

        #10;
        read = 1;
        address = 3'b100; // Address for data5
        #10;
        read = 0;

        #10;
        read = 1;
        address = 3'b101; // Address for data6
        #10;
        read = 0;

        #10;
        read = 1;
        address = 3'b110; // Address for data7
        #10;
        read = 0;

        #10;
        read = 1;
        address = 3'b111; // Address for data8
        #10;
        read = 0;

        #200; // Wait for some time before ending simulation
        $finish;
    end

    // Monitor process
    always @(negedge read) begin
            $display("Time: %0t | Read Address: %b | Read Data: %b %d", $time, address, readdata, readdata);
    
    end

endmodule
