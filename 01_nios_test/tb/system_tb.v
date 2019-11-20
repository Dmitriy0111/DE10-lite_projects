`timescale 1 ns / 1 ns

module system_tb();

	logic	[0 : 0]		clk_clk;
	logic	[0 : 0]		reset_reset_n;
	logic	[7 : 0]		pio_0_in_port;
	logic	[7 : 0]		pio_0_out_port;

	system
	system_0
	(
		.clk_clk		( clk_clk			),
		.pio_0_in_port	( pio_0_in_port		),
		.pio_0_out_port	( pio_0_out_port	),
		.reset_reset_n	( reset_reset_n		) 
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

endmodule
