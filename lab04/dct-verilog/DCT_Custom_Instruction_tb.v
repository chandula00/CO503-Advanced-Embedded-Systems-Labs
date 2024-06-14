`timescale 1ns / 1ps
`include "DCT_Component.v"
`include "DCT_Custom_Instruction.v"

module DCT_Custom_Instruction_tb;

    // Declare signals for DUT ports
    reg clk;
    reg reset;
    reg signed [31:0] dataa;
    reg [4:0] n;
    reg clk_en;
    reg start;
    wire done;
    wire signed [31:0] result;

    // Instantiate DUT (Device Under Test)
    DCT_Custom_Instruction dut (
        .clk(clk),
        .reset(reset),
        .dataa(dataa),
        .n(n),
        .clk_en(clk_en),
        .start(start),
        .done(done),
        .result(result)
    );

    // Clock generation
    always #(5) clk = ~clk;

    // Initial reset
    initial begin
        clk = 0;
        reset = 1;
        start = 0;
        clk_en = 0;
        n = 0;
        dataa = 0;
        #20; // Wait for some time
        reset = 0;
    end

    // Stimulus generation
    initial begin
        // Write operations
        #30;
        clk_en = 1;
        start = 1;
        dataa = -308;
        n = 0; // Write to address 0
        #10;
        n = 1; // Write to address 1
        dataa = -218;
        #10;
        n = 2; // Write to address 2
        dataa = -250;
        #10;
        n = 3; // Write to address 3
        dataa = -302;
        #10;
        n = 4; // Write to address 4
        dataa = -258;
        #10;
        n = 5; // Write to address 5
        dataa = -319;
        #10;
        n = 6; // Write to address 6
        dataa = -310;
        #10;
        n = 7; // Write to address 7
        dataa = -233;
        #10;
        start = 0;

        // Read operations
        #30;
        n = 8; // Read from address 0
        #10;
        $display("Time: %0t | Read Address: %b | Read Data: %d", $time, n, result);
        n = 9; // Read from address 1
        #10;
        $display("Time: %0t | Read Address: %b | Read Data: %d", $time, n, result);
        n = 10; // Read from address 2
        #10;
        $display("Time: %0t | Read Address: %b | Read Data: %d", $time, n, result);
        n = 11; // Read from address 3
        #10;
        $display("Time: %0t | Read Address: %b | Read Data: %d", $time, n, result);
        n = 12; // Read from address 4
        #10;
        $display("Time: %0t | Read Address: %b | Read Data: %d", $time, n, result);
        n = 13; // Read from address 5
        #10;
        $display("Time: %0t | Read Address: %b | Read Data: %d", $time, n, result);
        n = 14; // Read from address 6
        #10;
        $display("Time: %0t | Read Address: %b | Read Data: %d", $time, n, result);
        n = 15; // Read from address 7
        #10;
        $display("Time: %0t | Read Address: %b | Read Data: %d", $time, n, result);

        // Read operations
        #30;
        n = 16; // Read from address 0
        #10;
        $display("Time: %0t | Read Address: %b | Read Data: %d", $time, n, result);
        n = 17; // Read from address 1
        #10;
        $display("Time: %0t | Read Address: %b | Read Data: %d", $time, n, result);
        n = 18; // Read from address 2
        #10;
        $display("Time: %0t | Read Address: %b | Read Data: %d", $time, n, result);
        n = 19; // Read from address 3
        #10;
        $display("Time: %0t | Read Address: %b | Read Data: %d", $time, n, result);
        n = 20; // Read from address 4
        #10;
        $display("Time: %0t | Read Address: %b | Read Data: %d", $time, n, result);
        n = 21; // Read from address 5
        #10;
        $display("Time: %0t | Read Address: %b | Read Data: %d", $time, n, result);
        n = 22; // Read from address 6
        #10;
        $display("Time: %0t | Read Address: %b | Read Data: %d", $time, n, result);
        n = 23; // Read from address 7
        #10;
        $display("Time: %0t | Read Address: %b | Read Data: %d", $time, n, result);

        #200; // Wait for some time before ending simulation
        $finish;
    end

    // Monitor process
    always @(done) begin
        if (n>7) begin
            $display(">>>>>>Time: %0t | Read Address: %b | Read Data: %d", $time, n, result);
        end
    end

endmodule
