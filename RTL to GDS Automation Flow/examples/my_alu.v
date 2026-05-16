// 4-bit ALU - Arithmetic Logic Unit example
// Design: my_alu
// PDK: sky130A
// Author: projectspace121
// Operations: ADD, SUB, AND, OR

module my_alu (
    input  wire [3:0] a,
    input  wire [3:0] b,
    input  wire [1:0] op,
    output reg  [3:0] result
);
    // op: 00=ADD, 01=SUB, 10=AND, 11=OR
    always @(*) begin
        case (op)
            2'b00: result = a + b;
            2'b01: result = a - b;
            2'b10: result = a & b;
            2'b11: result = a | b;
            default: result = 4'b0000;
        endcase
    end
endmodule
