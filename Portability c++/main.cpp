/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: molinelli
 *
 * Created on 19 luglio 2018, 14.24
 */

#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
# include <queue>
#include "Config.h"
#include "ChessBoard.h"

using namespace std;

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
    
    ChessBoard chessBoard = ChessBoard();
    
    chessBoard.toString();
    
    printf("\n\nBenvenuto!");
    
    while(true){
        // Speech to text auxiliary variables
        char voice[256] = "";
        std::queue<char *> wordsQueue;
        
        printf("\n\nEsprimi un comando (EXIT per uscire): ");
        fgets(voice, 256, stdin);
        
        if(strcmp(voice,"EXIT") == 1){
            exit(0);
        }
        
        if (strlen(voice) > 0){
          char * temp = strtok(voice, " ");
          
          for(int i = 0; i < strlen(temp); i++){
              temp[i] = toupper(temp[i]);
          }
          
          wordsQueue.push(temp);
          
          while(temp != NULL){
            temp = strtok(NULL," ");
            
            if(temp != NULL){
                for(int i = 0; i < strlen(temp); i++){
                    temp[i] = toupper(temp[i]);
                }
                wordsQueue.push(temp);
            }
          }
        }
        /*printf("\n\n");
        while(wordsQueue.size() > 0){
            printf("%s\n",wordsQueue.front());
            wordsQueue.pop();
        }*/
        
        chessBoard.move(wordsQueue);
    }
}

