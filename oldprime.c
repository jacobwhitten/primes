
/*

Created by Jake
Date: 5/9/14
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	int i =2;

	int primearray[arraysize];
	memset(primearray,0, sizeof(int)*arraysize);//set all elements to 0.
	//set 0 and 1 to 1.
	primearray[0]=1;
	primearray[1]=1;
	while(i<arraysize){
		if(primearray[i]==0){
			int p = 2;
			while(i*p<=arraysize) {
				//printf("%d\n", i);
				primearray[i*p]=1;
				p++;}
		}
		i++;
	}
	printprimes(primearray,arraysize);
	//if(assertprimes(primearray,arraysize)) {printprimes(primearray,arraysize);
	//}else fprintf(stderr, "%s\n", "a prime number was bad!");

	return 0;
}