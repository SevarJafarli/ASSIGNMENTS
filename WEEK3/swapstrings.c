#include<stdio.h>
#include<string.h>
void swapStrings(char *destination, char *source);           

int main(){
    char str1[100]="Sevar Princess";
    char str2[100]="Princess Sevar";
    // define and initialize str1
    // define and initialize str2

    printf("str1: %s, str2: %s\n",str1,str2);
    swapStrings(str1,str2);
    printf("str1: %s, str2: %s\n",str1,str2);

    return 0;
}

void swapStrings(char *destination, char *source){
    int i=0;
    char temp[100];
    
    while(destination[i]!='\0') {
        temp[i]=destination[i];
        i++;
    }
    temp[i]='\0';
    i=0;
    while(source[i]!='\0') {
        destination[i]=source[i];
        i++;
    }
    destination[i]='\0';
    i=0;
    
    while(source[i]!='\0'){
        source[i]=temp[i];
        i++;
    }
    source[i]='\0';
    
    
}