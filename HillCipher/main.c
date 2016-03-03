//
//  main.c
//  HillCipher
//
//  Created by Marcus de Moraes on 9/22/14.
//  Copyright (c) 2014 Webients Development. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int MAX_INPUT_SIZE = 10000;
int MAX_MATRIX_SIZE = 500;

char plaintextInput[10000];
char ciphertextOutput[10000];
int fileLength = 0;
char temp;
int i = 0, s;

int CalcID(char input);
char calcChar(int input);

int main(int argc, const char * argv[])
{
    
    FILE* key;
    key = fopen(argv[1], "r");
	
    FILE* text;
    text = fopen(argv[2], "r");
    
    int matrixSize = 0;
    int keyRowsCols = 0;
    int keyMatrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    char tempChar;
    
    fscanf(key, "%d", &keyRowsCols);

  	for (i= 0; i < keyRowsCols; i++)
    {
        for (s= 0; s < keyRowsCols; s++){
            fscanf(key, "%c", &tempChar);
            if (isdigit(tempChar)){
                matrixSize++;
                keyMatrix[i][s] = atoi(&tempChar);
            }else {
                s--;
            }
        }
    }

    
    
    for (int o= 0; o < keyRowsCols; o++)
    {
        printf("\n");
        for (int p= 0; p < keyRowsCols; p++)
        {
            printf("%d  ", keyMatrix[o][p]);
            
        }
    }
    
    printf("\n\n\n");
    int f = 0;
    while (fscanf(text,"%c", &temp) != EOF) {
        temp = tolower(temp);
        
        //removes spaces
        if (plaintextInput[f] == ' ')
            continue;
        
        //removes newlines
        else if (plaintextInput[f] == '\n')
            continue;
        
        //removes tabs
        else if (plaintextInput[f] == '\t')
            continue;
        
        //remove any other symble
        else if (temp < 'a' || temp > 'z')
            continue;
        
        else{
            plaintextInput[f]= temp;
            f++;
            fileLength++;
        }
    }
    
    //padding
    while ((fileLength % keyRowsCols) !=0){
        plaintextInput[f] = 'x';
        f++;
        fileLength++;
    }
    
    
    int d=1;
    for (int p= 0; p < fileLength; p++)
    {
        if(d == 80)
        {
            printf("\n");
            d = 1;
            
        }
        d++;
        printf("%c", plaintextInput[p]);
        
    }
    
    printf("\n\n\n");
    
    //make sure the input is not too long.
    if (fileLength > MAX_INPUT_SIZE)
    {
        printf("Error: input too large. Ending program...");
        exit(EXIT_FAILURE);
    }
  
    //perform the matrix multiplication. store in the ciphertext array
    
    int l, r, c, k, tempToModify, cipherIndex=0, textIndex=0;
    int textNumberConversion[MAX_MATRIX_SIZE], sum[MAX_MATRIX_SIZE];
   
    for (l=0; l< (fileLength / keyRowsCols); l++)
    {
        for (k=0; k<keyRowsCols; k++)
        {
            textNumberConversion[k] = CalcID(plaintextInput[textIndex++]);
        }
        
        for (r=1; r<=keyRowsCols; r++)
        {
            for (c=1; c<=keyRowsCols; c++)
            {
                sum[r-1] += (keyMatrix[r-1][c-1] * textNumberConversion[c-1]);
            }
        }
        for (k=0; k<keyRowsCols; k++)
        {
            tempToModify = (sum[k] % 26);
            ciphertextOutput[cipherIndex++] = calcChar(tempToModify);
            sum[k] = 0;
        }
    }
        
 
    //print out the finished product.
    d=1;
    for (int p= 0; p < fileLength; p++)
    {
        if(d == 80){
            
            printf("\n");
            d = 1;
        }
        d++;
        printf("%c", ciphertextOutput[p]);
        
    }
    printf("\n\n");
    fclose(key);
    fclose(text);

    
}


int CalcID(char input)
{
    switch (input)
    {
        case 'a':
            return 0;
            break;
        case 'b':
            return 1;
            break;
        case 'c':
            return 2;
            break;
        case 'd':
            return 3;
            break;
        case 'e':
            return 4;
            break;
        case 'f':
            return 5;
            break;
        case 'g':
            return 6;
            break;
        case 'h':
            return 7;
            break;
        case 'i':
            return 8;
            break;
        case 'j':
            return 9;
            break;
        case 'k':
            return 10;
            break;
        case 'l':
            return 11;
            break;
        case 'm':
            return 12;
            break;
        case 'n':
            return 13;
            break;
        case 'o':
            return 14;
            break;
        case 'p':
            return 15;
            break;
        case 'q':
            return 16;
            break;
        case 'r':
            return 17;
            break;
        case 's':
            return 18;
            break;
        case 't':
            return 19;
            break;
        case 'u':
            return 20;
            break;
        case 'v':
            return 21;
            break;
        case 'w':
            return 22;
            break;
        case 'x':
            return 23;
            break;
        case 'y':
            return 24;
            break;
        case 'z':
            return 25;
            break;
    }
    return 0;
}

char calcChar(int input)
{
    switch (input)
    {
        case 0:
            return 'a';
            break;
        case 1:
            return 'b';
            break;
        case 2:
            return 'c';
            break;
        case 3:
            return 'd';
            break;
        case 4:
            return 'e';
            break;
        case 5:
            return 'f';
            break;
        case 6:
            return 'g';
            break;
        case 7:
            return 'h';
            break;
        case 8:
            return 'i';
            break;
        case 9:
            return 'j';
            break;
        case 10:
            return 'k';
            break;
        case 11:
            return 'l';
            break;
        case 12:
            return 'm';
            break;
        case 13:
            return 'n';
            break;
        case 14:
            return 'o';
            break;
        case 15:
            return 'p';
            break;
        case 16:
            return 'q';
            break;
        case 17:
            return 'r';
            break;
        case 18:
            return 's';
            break;
        case 19:
            return 't';
            break;
        case 20:
            return 'u';
            break;
        case 21:
            return 'v';
            break;
        case 22:
            return 'w';
            break;
        case 23:
            return 'x';
            break;
        case 24:
            return 'y';
            break;
        case 25:
            return 'z';
            break;
    }
    return 0;
}
