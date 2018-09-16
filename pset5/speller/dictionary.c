/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    bool one;
    struct node* children[27];
}node;

node* first;

int wCount = 0;

bool u(node* nodePtr);

int get_index(char c);


/**
 * Returns true if word is in dictionary else false.
 */

 node* make(){
    node* nodePtr = malloc(sizeof(node));
    nodePtr -> one = false;
    for(int i = 0; i <27;i++){
        nodePtr -> children[i] = NULL;
    }
    return nodePtr;

}

bool check(const char *word)
{
    // TODO
    node* nodePtr = first;

    for(int i =0,len = strlen(word); i <=len; i++){
        if(word[i]=='\0'){
            if(nodePtr -> one == true){
            return true;
            }
            else{
            return false;
            }
        }
        int index = get_index(word[i]);
        if(nodePtr->children[index]==NULL)

        return false;

        //CHANGED
        nodePtr = nodePtr->children[index];
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // TODO
    FILE* dPtr = fopen(dictionary, "r");
    if(dPtr == NULL){
        fprintf(stderr,"No file found\n");
        return false;
    }
    //check until EOF
    first = make();

    node* nodePtr = first;
    for(int c = fgetc(dPtr); c!=EOF; c =fgetc(dPtr))
    {

        if(c != '\n'){

             int index = get_index(c);
             if(nodePtr->children[index]==NULL){
                 nodePtr->children[index] =make();

             }
              nodePtr = nodePtr->children[index];
        }
        else{
            //end of word
            nodePtr->one = true;

            wCount++;
            //nback to beggining
            nodePtr = first;
        }

    }
    fclose(dPtr);

    return true;
}
//index of character

int get_index(char c)
{
    if(c=='\''){
    return 26;
    }

    return 0;
}

//return node pointer with null


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return wCount;
}


bool u(node* nodePtr){

 for(int i =0; i<27 ; i++){
    if(nodePtr -> children[i] !=NULL){
    u(nodePtr -> children[i]);

    }
 }

 free(nodePtr);

 return true;
}


/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void){

    // TODO
   if(u(first)){
    return true;
   }

   return true;

}




