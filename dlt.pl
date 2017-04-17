#!/bin/perl

my $cont = 0;
while(<>){
	if($cont == 1){
		$s .= $_;
		if($s =~ /\)\s;/){
			$cont = 0;
		} else {
			continue;
		}
		print "\$s => $s";
	} else {    # $cont == 0
		if($s =~ /DLT_LOG\s*\(/){
			if($s =~ /\)\s;/){
				$cont = 0;
			} else {
				$cont = 1;
				continue;
			}
		} else {
		}
		if($s =~ /DLT_STRING\s*\(\s*\"([^"]*)\"\s*\)/){
			print "$1 --> $_";
		}
	}
}

