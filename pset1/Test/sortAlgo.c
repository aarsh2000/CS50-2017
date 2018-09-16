#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
int values [5] = {6,2,3,3,5};
int n =5;

 for(int i =0; i<=n-2;i++){

        if(values[i]>values[i+1]){
            int one = values[i];
            int two = values[i+1];
            values[i]=two;
            values[i+1]=one;
        i=-1;
        }
 }


        /*for(int i = 0; i<n; i++){
        printf("%i", values[i]);
        int value = 42;

        if(values[i]==value){
            printf("\nx");
        }

        }*/
        printf("%i",19/2);

}
