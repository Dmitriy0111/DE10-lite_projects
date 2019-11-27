/*
*  File            :   mem_map_res.sv
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.27
*  Language        :   SystemVerilog
*  Description     :   This is avalon memory mapped reset module
*  Copyright(c)    :   2019 Vlasov D.V.
*/

module mem_map_res
(
    // clock and reset
    input   logic   [0        : 0]  clk,            // clock
    input   logic   [0        : 0]  rstn,           // reset
    // avalon bus side
    input   logic   [0        : 0]  address,        // address
    input   logic   [31       : 0]  writedata,      // write data
    output  logic   [31       : 0]  readdata,       // read data
    input   logic   [0        : 0]  write,          // write signal
    input   logic   [0        : 0]  chipselect,     // chip select signal
    // reset output
    output  logic   [0        : 0]  reset_out
);

    logic   [0  : 0]    write_req;
    logic   [0  : 0]    reset_int;

    assign write_req = chipselect && write;
    assign readdata = reset_int;
    assign reset_out = ~reset_int;

    reg_we  #( 1 )  reset_int_reg   ( clk, rstn, write_req, writedata[0], reset_int );

endmodule : mem_map_res
