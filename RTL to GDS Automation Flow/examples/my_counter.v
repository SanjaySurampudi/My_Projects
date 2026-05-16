// 4-bit Synchronous Counter - Sequential logic example
// Design: my_counter
// PDK: sky130A
// Author: projectspace121

module my_counter (
    input  wire       clk,
    input  wire       rst,
    output reg  [3:0] count
);
    always @(posedge clk or posedge rst) begin
        if (rst)
            count <= 4'b0000;
        else
            count <= count + 1;
    end
endmodule
