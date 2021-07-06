# MC54/74F151

O MC54/74F151 é um multiplexador com 8 entradas, podendo ser utilizado como um gerador de função universal para gerar qualquer lógica por conta da sua 'habilidade' de forncer uma linha de dados de até 8 fontes.

A posição da chave controladora é feita através das entradas Selects: `S0, S1, S2`

O valor da saída são fornecidos através das entradas: `i0,i1,i2,i3,i4,i5,i6,i7`.

Para o funcionamento é necessário que a entrada |E1 ( E1 Invertido ) esteja em estado Low , ou seja, a entrada E1 precisa está em HIGH Voltage Level.



## 💻 Simulator:

<img src="https://i.imgur.com/BkzDu9g.png" alt="Simulator Digital" width="640px" height="480px">

### :exclamation::exclamation: Importante
A entrada "e1" é fundamental para o funcionamento do sistema, caso ela esteja configurada como Low ( 0 ) , a saída 'Z' vai ser sempre
Low ( 0 ).

<img src="https://i.imgur.com/B3uJqMM.png" alt="Truth Table">


### :computer:GTKWave TestBench
`Click on image for take a zoom`

<img src="https://i.imgur.com/Fd5giXD.png" alt="TestBench" width="640px" height="480px">

### ☕ Usando TestBench

```
ghdl -a 74F151.vhd
ghdl -a testbench.vhd

ghdl -e testbench

ghdl -r  testbench --vcd=74F151.vcd

gtkwave 74F151.vcd
```
