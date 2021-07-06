library IEEE;
use IEEE.std_logic_1164.all;

entity main_project is
port(
	s0,s1,s2,e1 : in std_logic;
	i0,i1,i2,i3,i4,i5,i6,i7 : in std_logic;
	z , z_invertido : out std_logic
	);
end main_project;

architecture implementar of main_project is
begin
	process(s0,s1,s2,e1,i0,i1,i2,i3,i4,i5,i6,i7)
	begin
	if e1 = '1' then
		if (s2='0' and s1='0' and s0='0') then
			z <= i0;
			z_invertido <= not i0;
		elsif (s2='0' and s1='0' and s0='1') then
			z <= i1;
			z_invertido <= not i1;
		elsif (s2='0' and s1='1' and s0='0') then
			z <= i2;
			z_invertido <= not i2;
		elsif (s2='0' and s1='1' and s0='1') then
			z <= i3;
			z_invertido <= not i3;
		elsif (s2='1' and s1='0' and s0='0') then
			z <= i4;
			z_invertido <= not i4;
		elsif (s2='1' and s1='0' and s0='1') then
			z <= i5;
			z_invertido <= not i5;
		elsif (s2='1' and s1='1' and s0='0') then
			z <= i6;
			z_invertido <= not i6;
		elsif (s2='1' and s1='1' and s0='1') then
			z <= i7;
			z_invertido <= not i7;
		end if;
	else
		z <= '0';
		z_invertido <= '1';
	end if;
	end process;
end implementar;