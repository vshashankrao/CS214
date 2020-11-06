#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mymalloc.h"
#include <math.h>
#include <time.h>

// Malloc 1 byte and immediately free it, repeat 120 times
void A() {

    int x = 0;
    while(x < 120){
        char* aByte = malloc(1);
        free(aByte);
        x++;
    }

}


// Malloc 1 byte and store the pointer in an array, repeat 120 times
void B() {

    int x = 0;
    char* pointerArr[1000];
    while(x < 120){
        pointerArr[x] = malloc(1);
        x++;
    }
    x = 0;
    while(x < 120){
        free(pointerArr[x]);
        x++;
    }

}


// 240 times, randomly choose between a 1 byte malloc() or free()ing one of the malloc()ed pointers
void C() {
    int mallocCount = 0, freeCount = 0;
    int i;
    int randNum = rand() / 2;

    char* pointerArr[120];
    for(i = 0; i < 120; i++) {
        pointerArr[i] = NULL;
    }

    while((mallocCount + freeCount) < 240){
        if((randNum == 0) && (mallocCount < 120)){
            pointerArr[mallocCount] = malloc(1);

            if(pointerArr[mallocCount] != NULL){
                mallocCount++;
            }


        }
        else{
            if(freeCount < mallocCount){
                free(pointerArr[freeCount]);
                pointerArr[freeCount] = NULL;
                freeCount++;
            }
        }

        randNum = rand() / 2;
    }

}


// Malloc 4 bytes and immediately free it, repeat 400 times every 500 loops
void D() {

    int x = 0;
    char* aByte;
    int y = 0;
    char* bByte;

    while(x < 500){
        aByte = malloc(4);
        free(aByte);

        while(y < 400){
            bByte = malloc(4);
            free(bByte);
            y++;
        }

        x++;
    }

}


// Malloc 1 bytes and immediately free it until the 250th loop, then malloc 10 bytes and immediately free it until total loops reach 1000 times.
void E() {

    int x;
    char* aByte;

    for(x = 0; x < 1000; x++) {

        if(x >= 250) {
            aByte = malloc(1);
            free(aByte);
        }
        else {

            aByte = malloc(10);
            free(aByte);

        }


    }


}




// Main Function
int main(int argc, char* argv[]){

    double timeA = 0.0;
    double timeB = 0.0;
    double timeC = 0.0;
    double timeD = 0.0;
    double timeE = 0.0;
    double difference = 0.0;


    // Testing A
    int x = 0;
    clock_t start, stop;
    start = clock();
    while (Tester > x){
        A();
        x++;
    }
    stop = clock();
    difference = stop - start;
    timeA = (difference/CLOCKS_PER_SEC)/Tester;


    // Testing B
    x = 0;
    start = clock();
    while (Tester > x){
        B();
        x++;
    }
    stop = clock();
    difference = stop - start;
    timeB = (difference/CLOCKS_PER_SEC)/Tester;

    	// Testing C
    	x = 0;
    	start = clock();
    	while (Tester > x){
        	C();
        	x++;
    	}
    	stop = clock();
    	difference = stop - start;
    	timeC = (difference/CLOCKS_PER_SEC)/Tester;



    // Testing D
    x = 0;
    start = clock();
    while (Tester > x){
        D();
        x++;
    }
    stop = clock();
    difference = stop - start;
    timeD = (difference/CLOCKS_PER_SEC)/Tester;




    // Testing E
    x = 0;
    start = clock();
    while (Tester > x){
        E();
        x++;
    }
    stop = clock();
    difference = stop - start;
    timeE = (difference/CLOCKS_PER_SEC)/Tester;



    printf("The Average time taken of Test A is: %f\n", timeA);
    printf("The Average time taken of Test B is: %f\n", timeB);
    printf("The Average time taken of Test C is: %f\n", timeC);
    printf("The Average time taken of Test D is: %f\n", timeD);
    printf("The Average time taken of Test E is: %f\n", timeE);

}
