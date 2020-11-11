#include<stdio.h>
#include<string.h>

void function(char *source, char *integers, char *nonIntegers) {
    int i=0, a=0, b=0;

    for(i=0; source[i]!='\0'; i++) {
        if(source[i]>=48 && source[i]<=57) {
            integers[a]=source[i];
            a++;
        }
        else{
            nonIntegers[b]=source[i];
            b++;
    }   
}
    integers[a]='\0';
    nonIntegers[b]='\0';
}
    


int main() {
    char source[]="abcdfgehj1234/.!*";
    char integers[256];
    char nonIntegers[256];
    
    function(source, integers, nonIntegers);
    printf("source string is %s\n", source);
    printf("integer string is %s\n", integers);
    printf("non-integer string is %s\n", nonIntegers);
    return 0;
}

