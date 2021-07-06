
## Simulator:

<img src="https://i.imgur.com/BkzDu9g.png" alt="Simulator Digital">

## 💻 Importante
A entrada "e1" é fundamental para o funcionamento do sistema, caso ela esteja configurada como Low ( 0 ) , a saída 'Z' vai ser sempre Low 
( 0 ).

<img src="https://i.imgur.com/B3uJqMM.png" alt="Truth Table">


## GTKWave TestBench

<img src="https://i.imgur.com/Fd5giXD.png" alt="TestBench">

## ☕ Usando TestBench

```
ghdl -a 74F151.vhd
ghdl -a testbench.vhd

ghdl -e testbench

ghdl -r  testbench --vcd=74F151.vcd

gtkwave 74F151.vcd
```
