#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>


/*Assignment 0: C Tokenizer*/
//Shashank Rao svr38
//Nikhil Dodley njd104



char* input = NULL;

int main(int argc, char* argv[])
{
    input = argv[1];

    // char* input = "[ , ] COMPL14IN[( /*Nick Sanju";

    //char* input = "%= sizeof 123stuff b 3a 2.4a 0xab123 0X12 0117 3 d4x 0XA123 hello everyone COMPL14AIN";




    int index;

    // Represents number of word objects being used
    int wordCount = 0;
    int numCount = 0;

    int count;
    int length;

    int i, x, y;

    length = 0;


    // 2D Array used to store words found from input
    // Initial values represent size of words and size of each words like so:

    char wordArr[100][100]; // wordArr[Max number of letters][Max length of each word]

    char numArr[100][100]; // numArr[Max number of intgers][Max length of each number]

    printf("\nInput: \"%s\"\n", input);
    printf("Address of Input: \"%d\"\n", &input);
    printf("Length of the Input String is: %ld\n\n", strlen(input));

    printf("\n\n");


    // Start reading the main input character by character
    for (index = 0; input[index] != '\0'; index++) {

        count = index;
        //printf("Count: \"%d\"\n", count);



///////////////////////////////////////////////////////Operators/////////////////////////////////////////////////////////////////////////////////////////

        // If the current character is '('
        if (input[index] == '(') {

            printf("left parenthesis: \"(\"\n");

        }

            // If the current character is ')'
        else if (input[index] == ')') {

            printf("right parenthesis: \")\"\n");

        }

            // If the current character is '['
        else if (input[index] == '[') {

            printf("left bracket: \"[\"\n");

        }

            // If the current character is ']'
        else if (input[index] == ']') {

            printf("right bracket: \"]\"\n");

        }

            // If the current character is '.'
        else if (input[index] == '.') {

            printf("structure member: \".\"\n");

        }

            // If the current character is ','
        else if (input[index] == ',') {

            printf("comma: \",\"\n");

        }

            // If the current character is '!'
        else if (input[index] == '!') {

            if (input[index + 1] == '=') {

                printf("inequality test: \"!=\"\n");
                index = index + 1;
            }
            else {

                printf("negate: \"!\"\n");

            }

        }

            // If the current character is '<'
        else if (input[index] == '<') {

            if (input[index + 1] == '<') {

                if (input[index + 2] == '=') {

                    printf("shift left equals: \"<<=\"\n");
                    index = index + 2;

                }
                else {

                    printf("shift left: \"<<\"\n");
                    index = index + 1;

                }

            }
            else if (input[index + 1] == '=') {

                printf("less than or equal test: \"<=\"\n");
                index = index + 1;

            }
            else {

                printf("less than test: \"<\"\n");

            }

        }

            // If the current character is '>'
        else if (input[index] == '>') {

            if (input[index + 1] == '>') {

                if (input[index + 2] == '=') {

                    printf("shift right equals: \">>=\"\n");
                    index = index + 2;

                }
                else {

                    printf("shift right: \">>\"\n");
                    index = index + 1;

                }

            }
            else if (input[index + 1] == '=') {

                printf("greater than or equal test: \">=\"\n");
                index = index + 1;

            }
            else {

                printf("greater than test: \">\"\n");

            }

        }

            // If the current character is '^'
        else if (input[index] == '^') {

            if (input[index + 1] == '=') {

                printf("bitwise XOR equals: \"^=\"\n");
                index = index + 1;

            }
            else {

                printf("bitwise XOR: \"^\"\n");

            }


        }

            // If the current character is '&'
        else if (input[index] == '&') {

            if (input[index + 1] == '&') {

                printf("logical AND: \"&&\"\n");
                index = index + 1;

            }
            else if (input[index + 1] == '=') {

                printf("bitwise AND equals: \"&=\"\n");
                index = index + 1;

            }
            else {
                printf("AND/address operator: \"&\"\n");
            }

        }

            // If the current character is '|'
        else if (input[index] == '|') {

            if (input[index + 1] == '|') {

                printf("logical OR: \"||\"\n");
                index = index + 1;

            }
            else if (input[index + 1] == '=') {

                printf("bitwise OR equals: \"|=\"\n");
                index = index + 1;

            }
            else {

                printf("bitwise OR: \"|\"\n");

            }

        }

            // If the current character is '+'
        else if (input[index] == '+') {

            if (input[index + 1] == '+') {

                printf("increment: \"++\"\n");
                index = index + 1;

            }
            else if (input[index + 1] == '=') {

                printf("plus equals: \"+=\"\n");
                index = index + 1;

            }
            else {

                printf("addition: \"+\"\n");

            }


        }

            // If the current character is '-'
        else if (input[index] == '-') {

            if (input[index + 1] == '-') {

                printf("decrement: \"--\"\n");
                index = index + 1;

            }
            else if (input[index + 1] == '=') {

                printf("minus equals: \"-=\"\n");
                index = index + 1;

            }
            else if (input[index + 1] == '>') {

                printf("structure pointer: \"->\"\n");
                index = index + 1;

            }
            else {

                printf("minus/subtract operator: \"-\"\n");

            }

        }

            // If the current character is '*'
        else if (input[index] == '*') {

            if (input[index + 1] == '=') {

                printf("times equals: \"*=\"\n");
                index = index + 1;

            }
            else {

                printf("multiply/deference operator: \"*\"\n");

            }

        }

            // If the current character is '/'
        else if (input[index] == '/') {

            if (input[index + 1] == '=') {

                printf("divide equals: \"/=\"\n");
                index = index + 1;

            }
            else {

                printf("division: \"/\"\n");

            }

        }

            // If the current character is '%='
        else if (input[index] == '%' && input[index + 1] == '=') {

            printf("mod equals: \"%%=\"\n");
            index = index + 1;

        }

            // If the current character is '~'
        else if (input[index] == '~') {

            printf("1s complement: \"~\"\n");

        }

            // If the current character is '?'
        else if (input[index] == '?') {

            printf("conditional true: \"?\"\n");

        }

            // If the current character is ':'
        else if (input[index] == ':') {

            printf("conditional false: \":\"\n");

        }

            // If the current character is '='
        else if (input[index] == '=') {

            if (input[index + 1] == '=') {

                printf("equality test: \"==\"\n");
                index = index + 1;

            }
            else {

                printf("assignment: \"=\"\n");

            }

        }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







///////////////////////////////////////////////////////Words/////////////////////////////////////////////////////////////////////////////////////////

            // If the current character is a letter (Capital or Lowercase)

        else if (isalpha(input[index]) != 0) {


            // If the current letter has a letter or a number after it
            while (isalpha(input[index]) != 0 || isdigit(input[index+1]) != 0) {

                // New counter to start the loop of the word Array
                x = 0;
                length = 0;

                // Find the length of the current word
                for (i = count; (isalpha(input[i]) != 0 || isdigit(input[i]) != 0) && (input[i] != '\0' || input[i] != ' '); i++) {

                    length = length + 1;
                    wordArr[wordCount][x] = input[i];

                    x++;
                }

                wordArr[wordCount][x] = '\0';
                if(strcmp(wordArr[wordCount],"sizeof") == 0) {

                    printf("sizeof: \"sizeof\"\n");

                }
                printf("Word: \"%s\"\n", wordArr[wordCount]);
                wordCount++;
                printf("Index: \"%d\"\n", index);
                printf("Length of the current word: %d\n\n", length);

                index = index + length-1;

                break; // Stops the first for loop to prevent index and length from increasing any further

            }


        }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








///////////////////////////////////////////////////////Numbers/////////////////////////////////////////////////////////////////////////////////////////

            // If the current character is a number
        else if (isdigit(input[index]) != 0) {

            // Any number starting with 0
            if(input[index] == '0') {

                // If the current character is an octal number
                if (input[index] == '0' && (input[index + 1] == '0' || input[index + 1] == '1' || input[index + 1] == '2' || input[index + 1] == '3' || input[index + 1] == '4' || input[index + 1] == '5' || input[index + 1] == '6' || input[index + 1] == '7')) {

                    // If the current number has a number after it
                    while (isdigit(input[index]) != 0) {

                        // New counter to start the loop of the word Array
                        y = 0;
                        int length1 = 0;


                        // Find the length of the current word
                        for (i = count; isdigit(input[i]) != 0; i++) {

                            length1 = length1 + 1;
                            numArr[numCount][y] = input[i];
                            y++;
                        }
                        if(input[i] == '.'){
                            length1 = 0;
                            y = 0;
                            numArr[numCount][y] = '0';
                            break;
                        }

                        numArr[numCount][y] = '\0';
                        printf("octal integer: \"%s\"\n", numArr[numCount]);
                        numCount++;
                        printf("Index: \"%d\"\n", index);
                        printf("Length of the current number: %d\n\n", length1);

                        index = index + length1-1;

                        break; // Stops the first for loop to prevent index and length from increasing any further

                    }
                }


                    // If the current character is an hexadecimal number (Capital)
                else if((input[index] == '0' && input[index + 1] == 'X') && (isdigit(input[index + 2]) != 0 || input[index + 2] == 'A' || input[index + 2] == 'B' || input[index + 2] == 'C' || input[index + 2] == 'D' || input[index + 2] == 'E' || input[index + 2] == 'F')) {

                    // If the current number has a number after it
                    while ((input[index] == '0' && input[index + 1] == 'X') && (isdigit(input[index + 2]) != 0 || input[index + 2] == 'A' || input[index + 2] == 'B' || input[index + 2] == 'C' || input[index + 2] == 'D' || input[index + 2] == 'E' || input[index + 2] == 'F')) {

                        // New counter to start the loop of the word Array
                        y = 0;
                        int length1 = 0;
                        numArr[numCount][y] = '0';
                        // Find the length of the current word
                        for (i = count;  (input[i] == '0' || input[i ] == 'X') || (isdigit(input[i ]) != 0 || input[i ] == 'A' || input[i] == 'B' || input[i ] == 'C' || input[i ] == 'D' || input[i ] == 'E' || input[i ] == 'F') && (input[i] != '\0' || input[i] != ' '); i++) {

                            //printf("testing\n");
                            length1 = length1 + 1;
                            numArr[numCount][y] = input[i];

                            y++;
                        }

                        numArr[numCount][y] = '\0';
                        printf("hexadecimal integer: \"%s\"\n", numArr[numCount]);
                        numCount++;
                        printf("Index: \"%d\"\n", index);
                        printf("Length of the current number: %d\n\n", length1);

                        index = index + length1-1;

                        break; // Stops the first for loop to prevent index and length from increasing any further

                    }

                }




                    // If the current character is an hexadecimal number (Lowercase)
                else if((input[index] == '0' && input[index + 1] == 'x') && (isdigit(input[index + 2]) != 0 || input[index + 2] == 'a' || input[index + 2] == 'b' || input[index + 2] == 'c' || input[index + 2] == 'd' || input[index + 2] == 'e' || input[index + 2] == 'f')) {

                    // If the current number has a number after it
                    while ((input[index] == '0' || input[index] == 'x') ||  (isdigit(input[index]) != 0 || input[index] == 'a' || input[index] == 'b' || input[index] == 'c' || input[index] == 'd' || input[index] == 'e' || input[index] == 'f')) {

                        // New counter to start the loop of the word Array
                        y = 0;
                        int length1 = 0;

                        // Find the length of the current word
                        for (i = count;  (input[i] == '0' || input[i ] == 'x') || (isdigit(input[i ]) != 0 || input[i ] == 'a' || input[i] == 'b' || input[i ] == 'c' || input[i ] == 'd' || input[i ] == 'e' || input[i ] == 'f') && (input[i] != '\0' || input[i] != ' '); i++) {

                            length1 = length1 + 1;
                            numArr[numCount][y] = input[i];

                            y++;
                        }

                        numArr[numCount][y] = '\0';
                        printf("hexadecimal integer: \"%s\"\n", numArr[numCount]);
                        numCount++;
                        printf("Index: \"%d\"\n", index);
                        printf("Length of the current number: %d\n\n", length1);

                        index = index + length1-1;

                        break; // Stops the first for loop to prevent index and length from increasing any further

                    }

                }

                else { // normal numbers that starts with a zero

                    // If the current number has a number after it
                    while (isdigit(input[index]) != 0) {

                        int decimalTest = 0;
                        // New counter to start the loop of the word Array
                        y = 0;
                        int length1 = 0;

                        // Find the length of the current word
                        for (i = count; input[i] == '.' || isdigit(input[i]) != 0; i++) {

                            if(input[i] == '.'){
                                decimalTest = 1;
                            }

                            length1 = length1 + 1;
                            numArr[numCount][y] = input[i];
                            y++;
                        }

                        // If the current character is a floating point number
                        if(decimalTest == 1){


                            numArr[numCount][y] = '\0';
                            printf("floating point number: \"%s\"\n", numArr[numCount]);
                            numCount++;
                            printf("Index: \"%d\"\n", index);
                            printf("Length of the current number: %d\n\n", length1);

                            index = index + length1-1;
                        }

                            // If the current character is an decimal number
                        else {
                            numArr[numCount][y] = '\0';
                            printf("decimal integer: \"%s\"\n", numArr[numCount]);
                            numCount++;
                            printf("Index: \"%d\"\n", index);
                            printf("Length of the current number: %d\n\n", length1);

                            index = index + length1 - 1;
                        }
                        break; // Stops the first for loop to prevent index and length from increasing any further

                    }


                }


            }


                // For numbers that don't start with zero
            else {

                // If the current number has a number after it
                while (isdigit(input[index]) != 0) {

                    int decimalTest = 0;
                    // New counter to start the loop of the word Array
                    y = 0;
                    int length1 = 0;

                    // Find the length of the current word
                    for (i = count; input[i] == '.' || isdigit(input[i]) != 0; i++) {

                        if(input[i] == '.'){
                            decimalTest = 1;
                        }

                        length1 = length1 + 1;
                        numArr[numCount][y] = input[i];

                        y++;
                    }

                    // If the current character is a floating point number
                    if(decimalTest == 1){
                        numArr[numCount][y] = '\0';
                        printf("floating point number: \"%s\"\n", numArr[numCount]);
                        numCount++;
                        printf("Index: \"%d\"\n", index);
                        printf("Length of the current number: %d\n\n", length1);

                        index = index + length1-1;
                    }

                        // If the current character is an decimal number
                    else {
                        numArr[numCount][y] = '\0';
                        printf("decimal integer: \"%s\"\n", numArr[numCount]);
                        numCount++;
                        printf("Index: \"%d\"\n", index);
                        printf("Length of the current number: %d\n\n", length1);

                        index = index + length1 - 1;
                    }
                    break; // Stops the first for loop to prevent index and length from increasing any further

                }

            }

        }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






///////////////////////////////////////////////////////WhiteSpace Character/////////////////////////////////////////////////////////////////////////////////////////

            // If the current character is a whitespace character
        else if (input[index] == ' ' || input[index] == '\t' || input[index] == '\v' || input[index] == '\f' || input[index] == '\n' || input[index] == '\r') 			{



        }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else {


        }



    }

    //printf("Length: %d\n\n", length);

}