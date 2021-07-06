library IEEE;
use IEEE.std_logic_1164.all;

entity testbench is
--empty
end testbench;

architecture test of testbench is

signal s0,s1,s2,e1,i0,i1,i2,i3,i4,i5,i6,i7, z , z_invertido : std_logic;

begin
	UUT : entity work.main_project port map (s0 => s0 , s1 => s1, s2 => s2, i0 => i0,i1 => i1,i2 => i2,i3 => i3,i4 => i4,i5 => i5,i6 => i6,i7 => i7, e1 => e1, z => z, z_invertido => z_invertido);
	process
	begin
	
	e1 <= '0';
	s0 <= '0';
	s1 <= '0';
	s2 <= '0';
	i0 <= '0';
	i1 <= '0';
	i2 <= '0';
	i3 <= '0';
	i4 <= '0';
	i5 <= '0';
	i6 <= '0';
	i7 <= '0';
	wait for 1 ns;
	--Test 2
	e1 <= '1';
	s0 <= '0';
	s1 <= '1';
	s2 <= '0';
	i0 <= '1';
	i1 <= '0';
	i2 <= '0';
	i3 <= '1';
	i4 <= '1';
	i5 <= '0';
	i6 <= '1';
	i7 <= '1';
	wait for 1 ns;
	--Test 3
	e1 <= '1';
	s0 <= '1';
	s1 <= '0';
	s2 <= '1';
	i0 <= '0';
	i1 <= '1';
	i2 <= '0';
	i3 <= '1';
	i4 <= '1';
	i5 <= '0';
	i6 <= '0';
	i7 <= '0';
	wait for 1 ns;
	--Test 4
	e1 <= '1';
	s0 <= '1';
	s1 <= '0';
	s2 <= '0';
	i0 <= '0';
	i1 <= '1';
	i2 <= '0';
	i3 <= '1';
	i4 <= '1';
	i5 <= '0';
	i6 <= '0';
	i7 <= '1';
	wait for 1 ns;
	--Test 5
	e1 <= '1';
	s0 <= '1';
	s1 <= '0';
	s2 <= '1';
	i0 <= '0';
	i1 <= '1';
	i2 <= '1';
	i3 <= '1';
	i4 <= '1';
	i5 <= '1';
	i6 <= '1';
	i7 <= '1';
	wait for 1 ns;
	--Test 6
	e1 <= '1';
	s0 <= '1';
	s1 <= '0';
	s2 <= '1';
	i0 <= '0';
	i1 <= '1';
	i2 <= '0';
	i3 <= '1';
	i4 <= '0';
	i5 <= '1';
	i6 <= '0';
	i7 <= '1';
	wait for 1 ns;
	--Clear
	e1 <= '0';
	s0 <= '0';
	s1 <= '0';
	s2 <= '0';
	i0 <= '0';
	i1 <= '0';
	i2 <= '0';
	i3 <= '0';
	i4 <= '0';
	i5 <= '0';
	i6 <= '0';
	i7 <= '0';
	wait;
	end process;
end test;