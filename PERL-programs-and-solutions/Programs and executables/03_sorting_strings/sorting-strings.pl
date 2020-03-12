#!/usr/bin/perl -w
my @strings = qw(quantum relativistic classical);
my @sorted = sort @strings;
print "\nSorted strings:\n";
print join "\n", @sorted;
