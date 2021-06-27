library IEEE;
use IEEE.std_logic_1164.all;

entity main_project is
port(
	a : in std_logic;
	b : in std_logic;
	c : in std_logic;
	d : in std_logic;
	s0 : in std_logic;
	s1 : in std_logic;
	resultado : out std_logic);
end main_project;

architecture demo of main_project is
begin
	resultado <= a when ( s1 = '0' and s0 = '0' ) else
		b when ( s1 = '0' and s0 = '1' ) else
		c when ( s1 = '1' and s0 = '0' ) else
		d when ( s1 = '1' and s0 = '1' );
end demo;