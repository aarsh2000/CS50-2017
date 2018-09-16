
for(int r = 1 ; argc>r; r++){
 for(int c=0; strlen(dcript[r])>c;c++){
     char d = dcript[r][c];

     if (d>=48&&d<=57){
         printf("error");
         return 1;
     }
 }
}
if(argc==2){

int num[strlen(dcript[1])];
int size= (int)( sizeof(num) / sizeof(num[0]));
printf("plaintext: ");
string s = get_string();
int n = strlen(s);
printf("ciphertext: ");

for(int r = 1 ; argc>r; r++){
 for(int c=0; strlen(dcript[r])>c;c++){
     char t = dcript[r][c];

     t = tolower(t);
     int k = t - 97;

     num[c]=k;



    }



 }


int k = 0;

int counter=0;

  for(int i =0; n>i; i++){

    char t = s[i];


    if(t== ' '){

        counter++;
        k=num[((i-counter)%size)];
         printf("%i\n",i-counter);
    }
    else{

         k=num[((i-counter)%size)];

    }

    if(t >= 'A' && t<='Z'){
        char tt = t;
        t=t+k;

        if(k>26){
            t=t-k;
            int r=k%26;
            t=r+tt;

        }
        if(t<='@'|| t>= '['){
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
        if(t<='`'|| t>= '{'){
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

