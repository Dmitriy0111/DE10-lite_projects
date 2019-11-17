#
# File          :   run.tcl
# Autor         :   Vlasov D.V.
# Data          :   2019.11.17
# Language      :   tcl
# Description   :   This is script for running simulation process
# Copyright(c)  :   2019 Vlasov D.V.
#

vlib work

vlog -sv -f ../00_test_zero/run/rtl.f
vlog -sv -f ../00_test_zero/run/tb.f

vsim -novopt work.counter_tb

add wave -divider  "testbench signals"
add wave -position insertpoint sim:/counter_tb/*
add wave -divider  "dut signals"
add wave -position insertpoint sim:/counter_tb/dut/*

run -all

wave zoom full

#quit
