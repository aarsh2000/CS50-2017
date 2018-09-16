#include <cs50.h>
#include <stdio.h>
int main (void)
 {
bool menu = true;

while(menu){
printf("O hai! How much change is owed?");
double change = get_double();
if(change>=0){

  int cents= change*100;
  int counter =0;
   while(cents>=25){
    cents-=25;
    counter++;
   }
   while(cents>=10){
    cents-=10;
    counter++;
   }
   while(cents>= 5){
    cents-=5;
    counter++;
   }
   while(cents>=1){
    cents--;
    counter++;
   }
   printf("%i\n",counter);
   menu=false;
 }
 else{
  menu=true;
 }
 }


 }
