/*

Created by Jake
Edited and greatly improved by Thane
Date: 5/9/14

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printprimes(unsigned char array[], int size){
    int i;
    for(i=0; i < size; i++){
        if(array[i] == 1){
            fprintf(stdout, "%d%s", i, "\n" );
        }
    }
}

int assertprimes(unsigned char array[], int size){
    int p; //array index
    int rtn = 0; //return value

    // Loop though array
    for(p = 2; p < size; p++) {
        if (array[p] == 1) { // p is prime
            int i = p - 1; //current prime being checked minus 1
            while(i > 1){ // loop backwards though primes checking for divisibility
                if ((array[i] == 1) && ((p % i) == 0)){
                    fprintf(stderr, "%d is not a prime!\n", p);
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
    int arraysize = atoi(argv[1]); // size of array
    unsigned char primearray[arraysize]; // Allocate memory to array on the stack


    memset(primearray, 1, sizeof(unsigned char)*arraysize); //set all elements to 1, prime

    //set 0 and 1 to 0, not prime.
    primearray[0] = 0;
    primearray[1] = 0;

    double max = sqrt(arraysize); //max check
    int i = 2; //index of primearray

    while(i < max) {
        if(primearray[i] == 1) {
            int p = i;
            int check = p*i;
            /* printf("%d\n",i); */
            while(check < arraysize) {
                /* printf("%d\n", i); */
                primearray[check] = 0; // set to not prime
                p++;
                check=p*i;
            }
        }
        i++;
    }

    /* if(assertprimes(primearray, arraysize)) { */
        /* printprimes(primearray, arraysize); */
    /* } */
    /* }else fprintf(stderr, "%s\n", "a prime number was bad!"); */


    /* printprimes(primearray, arraysize); */

    /* assertprimes(primearray, arraysize); */

    return 0;
}
