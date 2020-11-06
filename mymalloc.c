#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mymalloc.h"

metadata *curr = NULL;
metadata *prev = NULL;
metadata *header = NULL;
// Allocating memory blocks
static char memoryblocks[MEMORY];

//QUESTION/Potential Change, we can probably remove file and line parameters but I kept it for now in case we want to debug code
void myfree(char* inputPointer, char* inputFile, int line){
    if(inputPointer == NULL){
        printf("Pointer is NULL\n");
    }

    // Checks to see if pointer isn't allocated by malloc
    if((char*)inputPointer > (char*)header + MEMORY || (char*)inputPointer < (char*) header){
        printf("This pointer hasn't been allocated yet\n");
        return;
    }

    curr = header;

    // Find the metadata that links to the inputPointer
    while((char*)curr + (sizeof(metadata)) != (char*)inputPointer && curr->data){
        prev = curr;
        curr = (metadata*)curr->data;
        // Set curr->data to null
        if(curr->data > (char*)header + MEMORY || curr->data < (char*)header){
            curr->data = NULL;
        }
    }
    // Check for data alignment
    if(curr->data == NULL){
        printf("Pointer isn't aligned\n");
    }
    // Change link
    metadata* next = (metadata*)curr->data;


    if(next->data == NULL){
        prev->data = (char*)(((char*)header) + sizeof(metadata));
    }
    else{
        prev->data = curr->data;
    }

    // Reset free and data values
    curr->free = 1;
    curr->data = NULL;
    return;
}

//QUESTION/Potential Change, we can probably remove file and line parameters but I kept it for now in case we want to debug code
char* mymalloc(int byteSize, char* inputFile, int line){
    // Corner case if size is nothing
    if(byteSize == 0){
        printf("No memory allocated\n");
        return NULL;
    }

    // This block is for the first time malloc is called in the program
    if(header == NULL){
        // Check to see if there's enough memory available
       if(byteSize > (MEMORY - sizeof(metadata))){
           printf("Not enough memory left in container to allocate to this pointer\n");
           return NULL;
       }
       else{
           // Initialize header and metadata values
           header = (metadata*) memoryblocks;
           header->size = 0;
           header->free = 0;
           header->data = sizeof(metadata) + memoryblocks;

           curr = (metadata*)(header->data);
           curr->size = byteSize;
           curr->free = 0;
           curr->data = ((char*)curr + byteSize + sizeof(metadata));

           char* inputPointer = (char*)curr + sizeof(metadata);
           return inputPointer;
       }
    }

    // We start with this block when malloc is used for the nth time where n > 1

    // Reset header to current metadata
    curr = header;
    curr->data = header->data;


    while(curr->data != NULL){
        // Check to see if there's enough memory available
        if((((int)curr + byteSize + curr->size + (2 * sizeof(metadata))) - (int)memoryblocks) > MEMORY){
            printf("Not enough memory left in container to allocate to this pointer\n");
            return NULL;
        }

        // Real size required to allocate memory
        int realMemSize = byteSize + sizeof(metadata);
        // Difference in sizes of curr and its associated values
        int difference = curr->data - (char*)curr - sizeof(metadata) - curr->size;

        // In the event that real memory size needed is less than difference
        if((curr->data != NULL) && (difference >= realMemSize)){
            prev = curr;
            curr = (metadata*)((char*)prev + sizeof(metadata) + prev->size);
            prev->data = (char*)curr;
            break;
        }
        else{
            // If the header is greater than the curr->data OR the curr->data is greater than the total Memory allocation
            if(((char*)curr->data < (char*)header) || (char*)curr->data > (char*)((char*)header + MEMORY)){
                curr->data = NULL;
            }
            if(curr->data == NULL){
                // If header value is equal to the difference between curr and metadata size
                if((metadata*)header == (metadata*)((char*)curr - sizeof(metadata))){
                    header->data = (char*)curr;
                    curr->data = (char*)((char*)curr + sizeof(metadata)+byteSize);
                    curr->free = 0;
                    prev->data = (char*)curr;
                    char* inputPointer = (char*)curr + sizeof(metadata);
                    return inputPointer;
                }
                break;
            }

            prev = curr;
            curr = (metadata*)curr->data;
        }

    }


    //Initialize new malloc pointer of specified size
    curr->size = byteSize;
    curr->free = 0;
    curr->data = (char*)((char*)curr + byteSize + sizeof(metadata));

    char* inputPointer = (char*)curr + sizeof(metadata);
    return inputPointer;
}


