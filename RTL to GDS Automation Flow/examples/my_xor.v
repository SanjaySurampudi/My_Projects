// XOR Gate - Simple combinational logic example
// Design: my_xor
// PDK: sky130A
// Author: projectspace121

module my_xor (
    input  wire a,
    input  wire b,
    output wire y
);
    assign y = a ^ b;
endmodule
