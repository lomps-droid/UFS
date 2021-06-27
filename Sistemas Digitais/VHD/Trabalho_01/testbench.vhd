library IEEE;
use IEEE.std_logic_1164.all;

entity testbench is
--empty
end testbench;

architecture test of testbench is

signal a,b,c,d,resultado,s0,s1 : std_logic;

begin
	UUT : entity work.main_project port map (a => a , b => b, c=> c , d=> d, resultado => resultado, s0 => s0, s1 => s1);
	process
	begin
	a <= '1';
	b <= '0';
	c <= '1';
	d <= '0';
	s1 <= '0';
	s0 <= '0';
	wait for 1 ns;
	a <= '1';
	b <= '0';
	c <= '1';
	d <= '0';
	s1 <= '1';
	s0 <= '1';
	wait for 1 ns;
	a <= '1';
	b <= '0';
	c <= '1';
	d <= '0';
	s1 <= '1';
	s0 <= '0';
	wait for 1 ns;
	a <= '1';
	b <= '0';
	c <= '1';
	d <= '0';
	s1 <= '0';
	s0 <= '1';
	wait for 1 ns;
	
	--clear
	a <= '0';
	b <= '0';
	c <= '0';
	d <= '0';
	s1 <= '0';
	s0 <= '0';
	wait;
	end process;
	
end test;