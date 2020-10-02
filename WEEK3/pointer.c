#include<stdio.h>
void swapStrings(char *destination, char *source);

int main(){
    char str1[1000]="I am";
    char str2[1000]="World";

    // define and initialize str1
    // define and initialize str2

    printf("str1: %s, str2: %s\n",str1,str2);
    swapStrings(str1,str2);
    printf("str1: %s, str2: %s\n",str1,str2);

    return 0;
}

void swapStrings(char *destination, char *source){
    char temp[1000];
    int lenDest=sizeof(destination)/sizeof(char);
    int lenSo=sizeof(source)/sizeof(char);

    for(int i=0; i<lenDest; i++){
        temp[i]=destination[i];
    }

    for(int i=0; i<lenSo; i++){
        destination[i]=source[i];
    }

    for(int i; i<lenDest; i++){
        source[i]=temp[i];
    }
}

