#!/usr/bin/perl -w
open (FILE, 'input.txt') or die "$!";
while (<FILE>) {
	if (m/text file/) {
		for (1..10) {
			<FILE>;
		}
		print;
		last;
	}
}
close FILE;
