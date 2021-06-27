ghdl -a main_project.vhd
ghdl -a testbench.vhd

ghdl -e testbench

ghdl -r  testbench --vcd=main_project.vcd

gtkwave main_project.vcd