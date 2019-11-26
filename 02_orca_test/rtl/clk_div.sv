/*
* File          :   clk_div.sv
* Autor         :   Vlasov D.V.
* Data          :   2019.11.26
* Language      :   SystemVerilog
* Description   :   This is clock dividing unit
* Copyright(c)  :   2019 Vlasov D.V.
*/

module clk_div
#(
    parameter                   div_val = 96000000
)(
    input   logic   [0 : 0]     clk,
    input   logic   [0 : 0]     rstn,
    input   logic   [0 : 0]     en,
    output  logic   [0 : 0]     div
);

    logic   [31 : 0]    counter;
    logic   [0  : 0]    clr_counter;

    assign div = ( counter <= ( div_val >> 1 ) );
    assign clr_counter = ( counter == div_val );

    always_ff @(posedge clk, negedge rstn)
        if( !rstn )
            counter <= '0;
        else if( en )
            counter <= clr_counter ? '0 : counter + 1'b1;

endmodule : clk_div
