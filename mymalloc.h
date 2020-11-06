//
// Created by Shashank on 10/21/2020.
//

#ifndef _MYMALLOC_H
#define _MYMALLOC_H
#define malloc( x ) mymalloc( x , __FILE__, __LINE__)
#define free( x ) myfree( x , __FILE__, __LINE__)
#define MEMORY 20000
#define Tester 100

#endif //_MYMALLOC_H


typedef struct _metadata{
    int size;
    //free: 1 = true, 0 = false
    int free;
    char* data;
} metadata;



char* mymalloc(int byteSize, char* inputFile, int line);
void myfree(char* inputPointer, char* inputFile, int line);




