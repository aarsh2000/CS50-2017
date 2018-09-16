#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, string dcript[]){
if(argc==2){
int k = atoi(dcript[1]);
printf("plain text: ");
string s = get_string();
printf("ciphertext: ");
int n = strlen(s);
    for(int i =0; n>i; i++){
    char t = s[i];

    if(t >= 'A' && t<='Z'){
        char tt = t;
        t=t+k;

        if(k>26){
            t=t-k;
            int r=k%26;
            t=r+tt;

        }
        if(t<='A'|| t>= 'Z'){
        t = t - k;
        t = (k + 'A') - (91-t);

        }
    }

   if(t >= 'a' && t<='z'){
        char tt = t;
        t=t+k;

        if(k>26){
            t=t-k;
            int r=k%26;
            t=r+tt;

        }
        if(t<='a'|| t>= 'z'){
        t = t - k;
        t = (k + 'a') - (123-t);

        }
    }

    s[i]=t;
    }

printf("%s\n",s);
return 0;
}

else{
    printf("only one k value allowed\n");
    return 1;
}

}


