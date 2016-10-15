#!/usr/bin/perl -w
## generate_plat.perl for generate_plat in /home/soto_a/rendu/CPE_2014_bsq
## 
## Made by Kaso Soto
## Login   <soto_a@epitech.net>
## 
## Started on  Mon Dec 22 19:43:30 2014 Kaso Soto
## Last update Sun Dec 28 22:15:44 2014 Kaso Soto
##

if ((scalar @ARGV) != 3)
{
    print "program x y density\n";
    exit;
}

my $x = $ARGV[0];
my $y = $ARGV[1];
my $density = $ARGV[2];
my $i = 0;
my $j = 0;

print $y . "\n";

while ($i < $y)
{
    $j = 0;
    while ($j < $x)
    {
	if (int(rand($y) * 2) < $density)
	    {
		print "o";
	    }
        else
	    {
		print ".";
	    }
	    $j++;
    }
    print "\n";
    $i++;
}
