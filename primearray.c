/*

Created by Jake
Edited and greatly improved by Thane (LOLOLLOLOLOLOL)
Date: 5/9/14

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printprimes(unsigned char array[], unsigned long long int size){
    unsigned long long int i;
    for(i=size; i > 0; i--){
        if(array[i] == 1){
            fprintf(stdout, "%llu%s", i, "\n" );
        }
    }
}

int assertprimes(unsigned char array[], unsigned long long int size){
    unsigned long long int p; //array index
    int rtn = 0; //return value

    // Loop though array
    for(p = 3; p < size; p++) {
        if (array[p] == 1) { // p is prime
            unsigned long long int i = ((unsigned long long int) sqrt(p)) + 1; // Start at the sqrt + 1 of p
            while(i > 1){ // loop backwards though primes checking for divisibility
                if ((array[i] == 1) && ((p % i) == 0)){
                    fprintf(stderr, "%llu is not a prime!\n", p);
                    i = 1; // already not prime, not worth checking anything else
                    rtn = 1;
                }
                i--;
            }
        }
    }
    return rtn;
}

int main(int argc, char **argv){

    if(argc == 1){
        fprintf(stderr, "%s\n", "Usage is: primearray limit");
        return 1;
    }
    unsigned long long int arraysize = atoi(argv[1]); // size of array
    unsigned char primearray[arraysize]; // Allocate memory to array on the stack


    memset(primearray, 1, sizeof(unsigned char) * (arraysize)); //set all elements to 1, prime

    //set 0 and 1 to 0, not prime.
    primearray[0] = 0;
    primearray[1] = 0;

    long double max = sqrt(arraysize); //max check
    unsigned long long int i = 2; //index of primearray

    while(i < max) {
        if(primearray[i] == 1) {
            unsigned long long int p = i;
            unsigned long long int check = i+i;
            /* printf("%d\n",i); */
            while(check < arraysize) {
                /* printf("%d\n", i); */
                primearray[check] = 0; // set to not prime
                p++;
                check+=i;
            }
        }
        i++;
    }


    printprimes(primearray, arraysize);

    /* assertprimes(primearray, arraysize); */

    return 0;
}
