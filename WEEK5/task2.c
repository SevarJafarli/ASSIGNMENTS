#include <stdio.h>
#include <string.h>
#define MAX 100

struct Stack{
    int top;
    char arr[MAX];
} st;

void init(){
    st.top = -1; //stack is empty
}

int isEmpty(){   //check whether stack is empty or not
    if(st.top == -1){ 
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){   //check whether stack is full or not
    if(st.top == MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char item){
    if(isFull()){
            printf("Stack is full");
    }
    else{
        st.top++;              
        st.arr[st.top] = item;        //push the char and increment top
    }
}

void pop(){
    if(isEmpty()){
        printf("Stack is empty");
    }
    else{
        st.top--;      //pop the char and decrement top
    }
}

int match(char opening,char closing)
{
	if(opening == '(' && closing == ')') return 1;
	else if(opening == '{' && closing == '}') return 1;
	else if(opening == '[' && closing == ']') return 1;
	return 0;
}

int main()
{
    char exp[MAX];
    int i,j;

    init();

    printf("Enter an expression to check:");
    fgets(exp, sizeof(exp), stdin);

    for(i=0;i<strlen(exp);i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
                push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(isEmpty() || !match(st.arr[st.top], exp[i])){
                printf("\nInvalid expression - Not a Balanced one !");
                return 0;
            }
            else{
                pop();
            }
        }
    }

    if(isEmpty()){   //if stack is empty, display that expression is valid
        printf("\nValid expression - Perfectly Balanced !");
    }else{
        printf("\nInvalid expression - Not a Balanced one !");
    }
}
