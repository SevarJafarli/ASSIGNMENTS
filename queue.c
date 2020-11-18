#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool isERR=false;

typedef struct node {
    char data[256];
    struct node * next;
} node_t;

void print(node_t * node) {
    while(node != NULL) {
        printf("%s ", node->data);
        node = node->next;
    }
}

void freed(node_t * node) {
    while(node != NULL) {
        free(node);
        node = node->next;
    }
}



void append(node_t ** head_ref, char *new_data) {
    node_t * new_node = (node_t *) malloc(sizeof(node_t));
    node_t * last = *head_ref;
    strcpy(new_node->data, new_data);
    new_node->next = NULL;
    while(last->next!= NULL) 
        last = last->next;
    
    last->next = new_node;
}

void delete(node_t ** head_ref, char *key) {
    node_t *temp=*head_ref;
    node_t *prev;

    if(temp!=NULL && strcmp(temp->data, key)==0) {
        *head_ref=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && strcmp(temp->data, key)!=0) {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL) {
        printf("There is no such user \n");
        isERR=true;
        return;
    }
    prev->next=temp->next;
    free(temp);
}

int main(){
    node_t * head=(node_t *) malloc(sizeof(node_t));
    char input[256];
    bool quit=0;
    strcpy(head->data, "Turgut ");
    head->next=NULL;

    append(&head, "Nazrin ");
    append(&head, "Kamran ");
    append(&head, "Elcan ");
    append(&head, "Nigar ");

    print(head);
    printf("\n");

    while(!quit) {
        scanf("%s", input);
        if(strcmp(input, "q")==0) {
            freed(head);
            quit=1;
        }
        else if(strcmp(input, "admit")==0) {
            delete(&head, head->data);
        }

        else {
            delete(&head, input);
            if(!isERR){
                append(&head, input);
            }
            isERR=false;
        }
        print(head);
        printf("\n");
    }

    return 0;
}


