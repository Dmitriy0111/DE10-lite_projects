/*
*  File            :   ram_avalon.sv
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.23
*  Language        :   SystemVerilog
*  Description     :   This is avalon ram memory
*  Copyright(c)    :   2019 Vlasov D.V.
*/

module ram_avalon
#(
    parameter                           a_width   = 7,
                                        init      = 0,
                string                  path2file = "path to hex file"
)(
    input   logic   [0         : 0]     clk,        // clock
    input   logic   [0         : 0]     reset,      // reset
    //
    input   logic   [a_width-1 : 0]     address,    // avalon address
    input   logic   [0         : 0]     chipselect, // avalon chipselect
    input   logic   [0         : 0]     write,      // avalon write
    input   logic   [3         : 0]     byteenable, // avalon byteenable
    input   logic   [31        : 0]     writedata,  // avalon writedata
    output  logic   [31        : 0]     readdata    // avalon readdata
);

    logic   [31 : 0]    rd_ff;
    logic   [31 : 0]    rd;
    logic   [3  : 0]    we;
    logic   [0  : 0]    re;

    assign we = byteenable & { 4 { write } } & { 4 { chipselect } };
    assign re = chipselect && !write;
    assign readdata = rd_ff;

    always_ff @(posedge clk) 
        if( re )
            rd_ff <= rd;

    ram
    #(
        .a_width    ( a_width   ),
        .init       ( init      ),
        .path2file  ( path2file )
    )
    ram_unit
    (
        .clk        ( clk       ),  // clock
        .addr       ( address   ),  // address
        .we         ( we        ),  // write enable
        .wd         ( writedata ),  // write data
        .rd         ( rd        )   // read data
    );

endmodule : ram_avalon
