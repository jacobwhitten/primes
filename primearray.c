
/*

Created by Jake
Date: 5/9/14
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printprimes(int array[], int size){
	int length = size;
	int i;
	for(i=0;i<length;i++){
		if(array[i]==0){
			fprintf(stdout, "%d%s", i, "\n" );
		}
	}
}
/*
int assertprimes(int array[],int size){
	int length = size;
	int i,p;

	for(i=0;i<length;i++){
		if(array[i]==0){
			fprintf(stderr, "%d%s", i, ", " );
		}
	}
}*/

int main(int argc, char **argv){

	if(argc==1){fprintf(stderr, "%s\n", "Usage is: primearray limit");
		return 1;
	}
	int arraysize = atoi(argv[1]);
	double max = sqrt(arraysize);
	int i =2;

	int primearray[arraysize];
	memset(primearray,0, sizeof(int)*arraysize);//set all elements to 0.
	//set 0 and 1 to 1.
	primearray[0]=1;
	primearray[1]=1;
	while(i<max){
		if(primearray[i]==0){
			int p = i;
			int check= p*i;
			//printf("%d\n",i);
			while(check<arraysize) {
				//printf("%d\n", i);
				primearray[check]=1;
				p++;
				check=p*i;
			}
		}
		i++;// could move to top and iterate at 2. (start at 0)
	}
	//printprimes(primearray,arraysize);
	//if(assertprimes(primearray,arraysize)) {printprimes(primearray,arraysize);
	//}else fprintf(stderr, "%s\n", "a prime number was bad!");

	return 0;
}