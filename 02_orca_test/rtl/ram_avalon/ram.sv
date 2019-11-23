/*
*  File            :   ram.sv
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.23
*  Language        :   SystemVerilog
*  Description     :   This is common ram memory
*  Copyright(c)    :   2019 Vlasov D.V.
*/

module ram
#(
    parameter                           a_width   = 7,
                                        init      = 0,
                string                  path2file = "path to hex file"
)(
    input   logic   [0         : 0]     clk,    // clock
    input   logic   [a_width-1 : 0]     addr,   // address
    input   logic   [3         : 0]     we,     // write enable
    input   logic   [31        : 0]     wd,     // write data
    output  logic   [31        : 0]     rd      // read data
);

    localparam          depth = 2 ** a_width;

    logic   [7  : 0]    bank_0  [depth-1 : 0];  // memory bank 0
    logic   [7  : 0]    bank_1  [depth-1 : 0];  // memory bank 1
    logic   [7  : 0]    bank_2  [depth-1 : 0];  // memory bank 2
    logic   [7  : 0]    bank_3  [depth-1 : 0];  // memory bank 3

    assign rd[24 +: 8] = bank_3[addr];
    assign rd[16 +: 8] = bank_2[addr];
    assign rd[8  +: 8] = bank_1[addr];
    assign rd[0  +: 8] = bank_0[addr];

    always @(posedge clk)
    begin : write_to_bank_3
        if( we[3] )
            bank_3[addr] <= wd[24 +: 8]; 
    end
    
    always @(posedge clk)
    begin : write_to_bank_2
        if( we[2] )
            bank_2[addr] <= wd[16 +: 8]; 
    end
    
    always @(posedge clk)
    begin : write_to_bank_1
        if( we[1] )
            bank_1[addr] <= wd[8  +: 8]; 
    end
    
    always @(posedge clk)
    begin : write_to_bank_0
        if( we[0] )
            bank_0[addr] <= wd[0  +: 8]; 
    end

    initial
    begin
        if( init )
        begin
            $readmemh( { path2file , "_3" , ".hex" } , bank_3 );
            $readmemh( { path2file , "_2" , ".hex" } , bank_2 );
            $readmemh( { path2file , "_1" , ".hex" } , bank_1 );
            $readmemh( { path2file , "_0" , ".hex" } , bank_0 );
        end
    end

endmodule : ram
