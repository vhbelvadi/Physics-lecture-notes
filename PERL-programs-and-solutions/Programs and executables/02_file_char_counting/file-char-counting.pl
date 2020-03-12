#!/usr/bin/perl -w
open(FILE, "textfile.txt") or die "Could not open file: $!";

my ($lines, $words, $chars) = (0,0,0);

while (<FILE>) {
    $linecount++;
    $charcount += length($_);
    $wordcount += scalar(split(/\s+/, $_));
}

print ("Total number of lines: $linecount \n");
print ("Total number of words: $wordcount \n");
print ("Total number of characters: $charcount \n");

