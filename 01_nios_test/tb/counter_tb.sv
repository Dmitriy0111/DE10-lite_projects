/*
* File          :   counter_tb.sv
* Autor         :   Vlasov D.V.
* Data          :   2019.11.17
* Language      :   SystemVerilog
* Description   :   This is testbench for counter unit
* Copyright(c)  :   2019 Vlasov D.V.
*/

module counter_tb();

    parameter               width = 8,
                            T = 10,
                            rstn_delay = 7,
                            rep_c = 300;

    logic   [0       : 0]   clk;
    logic   [0       : 0]   rstn;
    logic   [0       : 0]   dir;
    logic   [0       : 0]   en;
    logic   [width-1 : 0]   cnt;

    counter
    #(
        .width      ( width     )
    )
    dut
    (
        .clk        ( clk       ),
        .rstn       ( rstn      ),
        .dir        ( dir       ),
        .en         ( en        ),
        .cnt        ( cnt       )
    );

    initial
    begin
        clk = '0;
        forever
            #(T/2) clk = !clk;
    end

    initial
    begin
        rstn = '0;
        repeat(rstn_delay) @(posedge clk);
        rstn = '1;
    end

    initial
    begin
        @(posedge rstn);
        en = '1;
        repeat(rep_c)
        begin
            dir = $random();
            repeat($urandom_range(10,100)) @(posedge clk);
        end
        $stop;
    end

endmodule : counter_tb
