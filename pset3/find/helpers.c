/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{

int mid = n/2;
if(values[mid]==value){
    return true;
}
 if(value>values[mid]){
     //right
    for(int i = mid; n>i;i++){
        if(values[i]==value){
            return true;
        }
    }
 }

 if(value<values[mid]){
     //left
     for(int i = 0; mid>i;i++){
        if(values[i]==value){
            return true;
        }
    }

 }

 return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{

    for(int i =0; i<=n-2;i++){

        if(values[i]>values[i+1]){
            int one = values[i];
            int two = values[i+1];
            values[i]=two;
            values[i+1]=one;
        i=-1;
        }
 }
}
