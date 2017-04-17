#include <stdio.h>

char *dltString[5] = {
	""
	, "1ABC"
	, "2DEFGSF  666666666666"
	, "3 5555"
	, "4voidvoid void "
};

int main(void){
	int i=0;
	for(i=0;i<5;i++){
		printf("%d : %s\n",i,dltString[i]);
	}
	return 0;
}
