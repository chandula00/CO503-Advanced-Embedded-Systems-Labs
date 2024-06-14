
module DCT_Custom_Instruction(clk,
                              reset,
                              dataa,
                              n,
                              clk_en,
                              start,
							                done,
                              result);

parameter c1 = 1420;
parameter c2 = 1338;
parameter c3 = 1204;
parameter c5 = 805;
parameter c6 = 554;
parameter c7 = 283;
parameter s1 = 3;
parameter s2 = 10;
parameter s3 = 13;   

  input clk;
  input reset;
  input signed [31:0] dataa;  
  input [4:0] n;
  input clk_en;
  input start;
  output done;
  output signed [31:0] result;

  wire [3:0] address;
  wire write;
  wire read;
  reg done_delay;

  assign write = (n<8);
  assign read = (n>7);
 assign address = (n == 1) ? 4'b0001 :
                   (n == 2) ? 4'b0010 :
                   (n == 3) ? 4'b0011 :
                   (n == 4) ? 4'b0100 :
                   (n == 5) ? 4'b0101 :
                   (n == 6) ? 4'b0110 :
                   (n == 7) ? 4'b0111 :
                   (n == 8) ? 4'b0000 :
                   (n == 9) ? 4'b0001 :
                   (n == 10) ? 4'b0010 :
                   (n == 11) ? 4'b0011 :
                   (n == 12) ? 4'b0100 :
                   (n == 13) ? 4'b0101 :
                   (n == 14) ? 4'b0110 :
                   (n == 15) ? 4'b0111 :
                   (n == 16) ? 4'b1000 :
                   (n == 17) ? 4'b1001 :
                   (n == 18) ? 4'b1010 :
                   (n == 19) ? 4'b1011 :
                   (n == 20) ? 4'b1100 :
                   (n == 21) ? 4'b1101 :
                   (n == 22) ? 4'b1110 :
                   (n == 23) ? 4'b1111 : 4'b0000;
                   
  assign done = (n>7)? done_delay : start;

  always @ (posedge clk or posedge reset)
  begin
    // $display("Done: %d, Start = %d", done, start);
  if (reset)
		done_delay <= 0;
  else
		done_delay <= start;
  end

  /* 
    Instantiating the Avalon CRC component and wiring it to be
    custom instruction compilant
  */
  DCT_Component wrapper_wiring(.clk(clk),
                               .reset(reset),
                               .address(address),
                               .writedata(dataa),
                               .write(write & start),
                               .read(read),
                               .chipselect(clk_en),
                               .readdata(result));

defparam wrapper_wiring.c1 = c1;
defparam wrapper_wiring.c2 = c2;
defparam wrapper_wiring.c3 = c3;
defparam wrapper_wiring.c5 = c5;
defparam wrapper_wiring.c6 = c6;
defparam wrapper_wiring.c7 = c7;
defparam wrapper_wiring.s1 = s1;
defparam wrapper_wiring.s2 = s2;
defparam wrapper_wiring.s3 = s3;

// always @(address)
//   $display("Address: %d, n: %d", address, n);

// always @(done)
//   $display("Done: %d", done);

endmodule
