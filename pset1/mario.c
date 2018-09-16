#include <cs50.h>
#include <stdio.h>
int main (void)
{
 bool menu = true;
  while(menu){
   printf("Height: ");
   int h = get_int();
   if(h>=0&&h<=23){
    for(int row = 1; row<=h; row++){
     for(int col = 0; col<=h; col++){
      if(col<h-row){
      printf(" ");
                   }
      else{
      printf("#");}
   }
   printf("\n");
  }
menu = false;
}
else{ menu=true; }
}
}