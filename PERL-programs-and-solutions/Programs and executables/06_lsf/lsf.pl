#! /usr/bin/perl -w

print "\nEnter the name of the input file:\t";
$file = <>;
print "Enter the number of rows of data:\t";
$rows = <>;

open (INPUT,$file) or die "Could not open the file";
# @line;
@arrayX = ();
@arrayY = ();
$counter = 0;

($i, $sumx, $sumy, $sumxy, $sumx2) = (0, 0, 0, 0, 0);

while(<INPUT>){
    @line = split(/\t/,$_);
    $arrayX[$counter]=$line[0];
    $arrayY[$counter]=$line[1];
    $counter++;
}

for($i=0;$i<$rows;$i++)
    {
        $sumx = $sumx + $arrayX[$i];
        $sumx2 = $sumx2 + $arrayX[$i]*$arrayX[$i];
        $sumy = $sumy + $arrayY[$i];
        $sumxy = $sumxy + $arrayX[$i]*$arrayY[$i];
        
    }
    
$c = (($sumx2*$sumy - $sumx*$sumxy)*1.0/($rows*$sumx2-$sumx*$sumx)*1.0);
$m = (($rows*$sumxy-$sumx*$sumy)*1.0/($rows*$sumx2-$sumx*$sumx)*1.0);
print "\n\nThe line of best fit is y=$m x + $c \n\n";
