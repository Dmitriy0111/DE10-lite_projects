/*
*  File            :   gpio_avalon.sv
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.18
*  Language        :   SystemVerilog
*  Description     :   This is avalon GPIO module
*  Copyright(c)    :   2019 Vlasov D.V.
*/

module gpio_avalon
#(
    parameter                       gpio_w = 8
)(
    // clock and reset
    input   logic   [0        : 0]  clk,            // clock
    input   logic   [0        : 0]  rstn,           // reset
    // avalon bus side
    input   logic   [2        : 0]  address,        // address
    input   logic   [31       : 0]  writedata,      // write data
    output  logic   [31       : 0]  readdata,       // read data
    input   logic   [0        : 0]  write,          // write signal
    input   logic   [0        : 0]  read,           // read signal
    input   logic   [0        : 0]  chipselect,     // chip select signal
    output  logic   [0        : 0]  readdatavalid,  // read data valid signal
    // interrupt
    output  logic   [0        : 0]  irq,            // interrupt
    // GPIO side
    input   logic   [gpio_w-1 : 0]  gpi,            // GPIO input
    output  logic   [gpio_w-1 : 0]  gpo,            // GPIO output
    output  logic   [gpio_w-1 : 0]  gpd             // GPIO direction
);

    logic   [0  : 0]    write_req;
    logic   [0  : 0]    read_req;

    logic   [2  : 0]    w_addr;
    logic   [2  : 0]    r_addr;

    logic   [2  : 0]    addr;
    logic   [0  : 0]    we;
    logic   [31 : 0]    wd;
    logic   [31 : 0]    rd;

    assign write_req = chipselect && write;
    assign read_req  = chipselect && read;

    assign wd = writedata;
    assign readdata = rd;
    assign we = write_req;
    assign w_addr = address;
    assign addr = readdatavalid ? r_addr : w_addr;

    reg_s   #( 1 )  readdatavalid_reg   ( clk, rstn,           read_req, readdatavalid );
    reg_we  #( 3 )  r_addr_reg          ( clk, rstn, read_req, address,  r_addr        );
    
    gpio 
    #(
        .gpio_w     ( gpio_w    )
    )
    gpio_
    (
        // clock and reset
        .clk        ( clk       ),  // clock and reset
        .rstn       ( rstn      ),  // clock and reset
        // bus side
        .addr       ( addr      ),  // address
        .we         ( we        ),  // write enable
        .wd         ( wd        ),  // write data
        .rd         ( rd        ),  // read data
        .irq        ( irq       ),  // interrupt
        // GPIO side
        .gpi        ( gpi       ),  // GPIO input
        .gpo        ( gpo       ),  // GPIO output
        .gpd        ( gpd       )   // GPIO direction
    );

endmodule : gpio_avalon
