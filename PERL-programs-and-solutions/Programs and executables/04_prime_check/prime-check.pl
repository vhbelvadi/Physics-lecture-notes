#! /usr/bin/perl -w
print "Enter a number:\t";
$number = <>;
$divisor = 0;
$flag = 0;
if ($number != 2) {
	for ($divisor = 2; $divisor < $number ; $divisor++) {
		if ($number % $divisor == 0) {
			$flag = 1;
			last;
		}
	}
} else {
	$flag = 1;
}
if ($flag != 1) {
	print "The number is prime.\n";
} else {
	print "The number is composite.\n";
}
