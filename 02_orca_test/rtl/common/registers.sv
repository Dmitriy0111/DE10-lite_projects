/*
*  File            :   registers.sv
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.18
*  Language        :   SystemVerilog
*  Description     :   This is file with registers
*  Copyright(c)    :   2019 Vlasov D.V.
*/

// simple register
module reg_s
#(
    parameter                       width = 8
)(
    // clock and reset
    input   logic   [0       : 0]   clk,    // clock
    input   logic   [0       : 0]   rstn,   // reset
    // register side
    input   logic   [width-1 : 0]   din,    // data_in
    output  logic   [width-1 : 0]   dout    // data_out
);

    logic   [width-1 : 0]   int_reg;    // internal register

    assign dout = int_reg;
    
    always_ff @(posedge clk, negedge rstn)
        if( !rstn )
            int_reg <= '0;
        else
            int_reg <= din;
    
endmodule : reg_s

// register with write enable input
module reg_we
#(
    parameter                       width = 8
)(
    // clock and reset
    input   logic   [0       : 0]   clk,    // clock
    input   logic   [0       : 0]   rstn,   // reset
    // register side
    input   logic   [0       : 0]   we,     // write enable
    input   logic   [width-1 : 0]   din,    // data_in
    output  logic   [width-1 : 0]   dout    // data_out
);

    logic   [width-1 : 0]   int_reg;    // internal register

    assign dout = int_reg;
    
    always_ff @(posedge clk, negedge rstn)
        if( !rstn )
            int_reg <= '0;
        else if( we )
            int_reg <= din;

endmodule : reg_we
