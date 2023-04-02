transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+/home/josevaltersilvacarneiro/Documentos/programming/verilog/two_out_of_five {/home/josevaltersilvacarneiro/Documentos/programming/verilog/two_out_of_five/two_out_of_five.v}

