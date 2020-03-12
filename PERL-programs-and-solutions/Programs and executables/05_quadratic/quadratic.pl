#! /usr/bin/perl -w
use Math::Complex;
INPUT:
print "\nEnter the three non-zero co-efficients of ax^2 + bx + c:\n";
chomp($a=<>, $b=<>, $c=<>);
if ($a == 0) {
	print "The co-efficient a cannot be zero. Try again.\n";
	goto INPUT;
}
($x1, $x2) = solveQuad($a,$b,$c);
print "Root 1 = $x1, Root 2 = $x2\n\n";
sub solveQuad {
	my ($a, $b, $c) = @_;
	my $root = sqrt($b**2 - 4*$a*$c);
	return (-$b + $root)/(2*$a), (-$b-$root)/(2*$a);
}
