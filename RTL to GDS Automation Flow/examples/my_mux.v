// 2:1 Multiplexer - Combinational logic example
// Design: my_mux
// PDK: sky130A
// Author: projectspace121

module my_mux (
    input  wire a,
    input  wire b,
    input  wire sel,
    output wire y
);
    assign y = sel ? b : a;
endmodule
