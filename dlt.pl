#!/bin/perl

our %gStr;          # $gStr{string} = index
our %gStrCount;     # $gStrCount{index} = count
our @gNum;          # $gNum{index} = string
our %gLengthCount;  # $gLengthCount{length of string} = count
our %gLengthText;   # $gLengthCount{length of string} = concatenation of strings
our $gMaxCount = 1;
our $total_context_org; # to check whether original file is changed or not between org and chg.
our $total_context_chg;
my $num;
foreach $filename (@ARGV){
	print "$filename\n";
	open(FH, "<",$filename) or die "Can't open < $filename: $!";
	$total_context_org = "";
	$total_context_chg = "";
	while(<FH>){

		$s = $_;
		$s_org = $s;
		$total_context_org .= $s;

		# DLT_STRING(...)   or DLT_CSTRING(...) 
		# These types will use in DLT_LOG functions as arguments.
		if(($s =~ /DLT_STRING/)  or  ($s =~ / DLT_CSTRING/)){   
			while(1){   # several DLT_STING will be located in one sentense. 
				# This is for DLT_STRING
				if($s =~ /DLT_STRING\s*\(\s*\"([^"]*)\"\s*\)/){
					#print "S $1 --> $s";
					if($gStr{$1} != 0){
						$num = $gStr{$1};
						$gStrCount{$num} ++;
					} else {
						$gStr{$1} = $gMaxCount;
						$gNum[$gMaxCount] = $1;
						$num = $gMaxCount;
						$gStrCount{$num} = 1;
						$gLengthCount{length($1)} ++;
						$gLengthText{length($1)} .= "#\t\t$1\n";
						$gMaxCount ++;
					}
					# to distinguish between processed DLT_STRING and unproessed it.
					$s =~ s/DLT_STRING\s*\(\s*\"([^"]*)\"\s*\)/DLT_SSSTRING\(\"!~$num\"\)/;
				} elsif($s =~ /DLT_CSTRING\s*\(\s*\"([^"]*)\"\s*\)/){    # copy from DLT_sRING
					#print "C $1 --> $s";
					if($gStr{$1} != 0){
						$num = $gStr{$1};
						$gStrCount{$num} ++;
					} else {
						$gStr{$1} = $gMaxCount;
						$gNum[$gMaxCount] = $1;
						$num = $gMaxCount;
						$gStrCount{$num} = 1;
						$gLengthCount{length($1)} ++;
						$gLengthText{length($1)} .= "#\t\t$1\n";
						$gMaxCount ++;
					}
					$s =~ s/DLT_CSTRING\s*\(\s*\"([^"]*)\"\s*\)/DLT_SSCSTRING\(\"!~$num\"\)/;
				} else {
					last;
				}
			}
		} elsif($s =~ /(^.*DLT_LOG_STRING[^\"]+)\"([^\"]*)\"([^\"]+)/){ # DLT_LOG_STRING....() is the same level of DLT_LOG(...)
			# DLT_LOG_STRING
			# DLT_LOG_STRING_INT
			# DLT_LOG_STRING_UINT
			#print "D $2 --> $s";
			if($gStr{$2} != 0){
				$num = $gStr{$2};
				$gStrCount{$num} ++;
			} else {
				$gStr{$2} = $gMaxCount;
				$gNum[$gMaxCount] = $2;
				$num = $gMaxCount;
				$gStrCount{$num} = 1;
				$gLengthCount{length($2)} ++;
				$gLengthText{length($2)} .= "#\t\t$2\n";
				$gMaxCount ++;
			}
			$s = "$1\"!~$num\"$3";
		}
		$s =~ s/DLT_SSCSTRING/DLT_CSTRING/g;
		$s =~ s/DLT_SSSTRING/DLT_STRING/g;
		if($s eq $s_org){
			#print "$s";
			$total_context_chg .= $s;
		} else {
			chop($s);
			#print "$s \t\t\/\/\/\/*$s_org";
			$total_context_chg .= "$s \t\t\/\/\/\/*$s_org";
		}
	}
	close(FH);
	if($total_context_org ne $total_context_chg){
		open(FO,">","./chg/$filename\.chg");
		print FO $total_context_chg;
		close(FO);
	}
}

open(FO,">","./chg/string_list.chg");
my $goodSize = 0;
my $badSize = 0;
print FO "# Sorted String and Index Table.\n";
foreach my $key (sort {$gStrCount{$b} <=> $gStrCount{$a}} keys %gStrCount){
	$strLen = length($gNum[$key]);
	$temp = "$key";
	$keyLen = length($temp) + 2 ;       # 2 is !~
	#print "$key : len $keyLen\n";
	if($strLen > $keyLen){
		$goodSize += ( ($strLen - $keyLen) * $gStrCount{$key} );
		print FO "A";
	} elsif($strLen < $keyLen){
		$badSize += ( ($keyLen - $strLen) * $gStrCount{$key} );
		print FO "D";
	} else {
		print FO "=";
	}
	print FO "!~ (index) $key : (used count) $gStrCount{$key} -> (len) $strLen  : (origin string) \[$gNum[$key]\]\n";
}
print FO "Advantages : $goodSize Bytes\n";
print FO "Disadvantages : $badSize Bytes\n";
my $tadv = $goodSize - $badSize;
print FO "Total Advantages : $tadv Bytes\n";
print FO "\n\n\n";

print FO "# Index Table\n";
for (my $i = 1 ; $i < $gMaxCount;$i++){
	print FO "!~$i : $gStrCount{$i} -> \[$gNum[$i]\]\n";
}
print FO "\n\n\n";

foreach my $key (sort {$gLengthCount{$b} <=> $gLengthCount{$a}} keys %gLengthCount){
	print FO "Length : $key  => Count : $gLengthCount{$key}\n$gLengthText{$key}";
}
close(FO);

open(FO,">","./chg/dltString.c");
print FO "#include <stdio.h>\n\n";
print FO "char *dltString\[ $gMaxCount \] = {\n";
print FO "\t\"\!\~\"\n";
for (my $i = 1 ; $i < $gMaxCount;$i++){
	$strLen = length($gNum[$i]);
	print FO "\t, \"$gNum[$i]\"\n";
}
print FO "};\n\n";
print FO "
char *getDltString(int i){
	if(i >= $gMaxCount ){
		return NULL;
	}
	return dltString[i];
}

#ifdef TEST
int main(void){
	int i=0;
	for(i=0; i< $gMaxCount ; i++){
		printf(\"\%d : \%s\\n\",i,getDltString(i));
	}
	return 0;
}
#endif // TEST
";
close(FO);
