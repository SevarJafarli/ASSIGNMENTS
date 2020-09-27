#include<stdio.h>
int swapIntegers(int a, int b);
int main(){
    int n1,n2;
    printf("Enter 2 integers: ");
    scanf("%d%d", &n1, &n2);
    swapIntegers(n1, n2);
    return 0;
 }

int swapIntegers(int a , int b){
    int temp;
    temp=a;
    a=b;
    b=temp;
    printf("After swapping a=%d and b=%d", a, b);
}
