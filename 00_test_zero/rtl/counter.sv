/*
* File          :   counter.sv
* Autor         :   Vlasov D.V.
* Data          :   2019.11.17
* Language      :   SystemVerilog
* Description   :   This is counter unit
* Copyright(c)  :   2019 Vlasov D.V.
*/

module counter
#(
    parameter                       width = 8
)(
    input   logic   [0       : 0]   clk,
    input   logic   [0       : 0]   rstn,
    input   logic   [0       : 0]   dir,
    input   logic   [0       : 0]   en,
    output  logic   [width-1 : 0]   cnt
);

    logic   [width-1 : 0]   count;

    assign cnt = count;

    always_ff @(posedge clk, negedge rstn)
        if( !rstn )
            count <= '0;
        else if( en )
        begin
            if( dir )
                count <= count + 1'b1;
            else
                count <= count - 1'b1;
        end

endmodule : counter
