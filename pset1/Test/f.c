#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
 int d = 4;

     int strt = d*d-1;
     int set = strt;
    int board [d][d];
    for(int row =0; d>row;row++){
        for(int col = 0; d>col;col++){

                board[row][col]= set;


            set--;
        }
    }

    if(d%2==0&&d>2){
        board[d-1][d-2]=2;
        board[d-1][d-3]=1;
    }



    for(int row =0; d>row;row++){
        for(int col = 0; d>col;col++){

            printf("%2i ", board[row][col]);

        }
        printf("\n");
    }

}
