`timescale 1ns / 1ps

`include "CRC_Custom_Instruction.v"

module test;

  // Parameters
  parameter CLK_PERIOD = 10; // Clock period in ns
  
  // Signals
  reg clk;
  reg reset;
  reg [31:0] dataa;
  reg [2:0] n;
  reg clk_en;
  reg start;
  wire done;
  wire [31:0] result;

  // Instantiate the CRC_Custom_Instruction module
  CRC_Custom_Instruction dut (
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
  always #((CLK_PERIOD / 2)) clk = ~clk;

  // Reset generation
  initial begin
    clk = 0;
    reset = 1;
    #100;
    reset = 0;
    #100;
    start = 1; // Initiate CRC calculation
    #10;
    start = 0;
    // Write 32-bit data
    n = 3;
    dataa = 32'hABCDEFBB;
    clk_en = 1;
    #10;
    clk_en = 0;
    #100;
    // Read result
    n = 4;
    clk_en = 1;
    #10;
    clk_en = 0;
    #100;
    $display("Result: %h, Done: %b", result, done);
    // Repeat for other operations if needed
    // ...
    $finish;
  end

endmodule
