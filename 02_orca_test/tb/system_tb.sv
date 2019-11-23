`timescale 1 ns / 1 ns

module orca_system_tb();

    logic   [0 : 0]     clk_clk;
    logic   [0 : 0]     reset_reset_n;
    logic   [7 : 0]     gpio_0_gpi;
    logic   [7 : 0]     gpio_0_gpo;
    logic   [7 : 0]     gpio_0_gpd;

    orca_systems
    orca_systems_0
    (
        .clk_clk        ( clk_clk       ),
        .gpio_0_gpd     ( gpio_0_gpd    ),
        .gpio_0_gpi     ( gpio_0_gpi    ),
        .gpio_0_gpo     ( gpio_0_gpo    ),
        .reset_reset_n  ( reset_reset_n ) 
    );

    initial 
    begin
        clk_clk = '0;
        forever 
            #(10) clk_clk = !clk_clk;
    end

    initial
    begin
        reset_reset_n = 0;
        repeat(20) @(posedge clk_clk);
        reset_reset_n = '1;
    end

    initial
    begin
        repeat(2000) @(posedge clk_clk);
        $stop;
    end

endmodule : orca_system_tb
