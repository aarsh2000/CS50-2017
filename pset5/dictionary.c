/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    bool is_word;
    struct node* children[27];
}node;

node* first;

int wCount = 0;

bool unload_helper(node* nodePtr);

int get_index(char c);
node* create_init_node();

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    node* nodePtr = first;

    for(int i =0,len = strlen(word); i <=len; i++){
        if(word[i]=='\0'){
            if(nodePtr -> is_word == true){
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
    first = create_init_node();

    node* nodePtr = first;
    for(char c = fgetc(dPtr); c!=EOF; c =fgetc(dPtr))
    {

        if(c != '\n'){

             int index = get_index(c);
             if(nodePtr->children[index]==NULL){
                 nodePtr->children[index] = create_init_node();

             }
              nodePtr = nodePtr->children[index];
        }
        else{
            //end of word
            nodePtr->is_word = true;

            wCount++;
            //nback to beggining
            nodePtr = first;
        }
    }
    return true;
}
//index of character

int get_index(char c)
{
    if(c=='\'')
    return 26;

    else if (c>= 'a' && c<= 'z')
        return c - 'a';

    else if (c>='A'&& c <='Z')
        return c - 'A';


    return -1;
}

//return node pointer with null

node* create_init_node(){
    node* nodePtr = malloc(sizeof(node));
    nodePtr -> is_word = false;
    for(int i = 0; i <27;i++){
        nodePtr -> children[i] = NULL;
    }
    return nodePtr;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return wCount;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void){

    // TODO
   if(unload_helper(first)){
    return true;
   }

   return true;

}


bool unload_helper(node* nodePtr){

 for(int i =0; i<27 ; i++){
    if(nodePtr -> children[i] !=NULL){
    unload_helper(nodePtr -> children[i]);

    }
 }

 free(nodePtr);
 return true;
}
