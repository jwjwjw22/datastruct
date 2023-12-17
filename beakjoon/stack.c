#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE{
    int data;
    struct NODE* next;
}NODE;
//메모리 할당 할 구조체 형성

NODE* g_pHead; 
// 전역변수로 헤드잡기




void push_back(int pData){
    NODE* head = g_pHead;
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data=pData;
    newnode->next = 0;        
    if(g_pHead == NULL){
        g_pHead = newnode;
    }
    else{
        while(head->next != NULL) head=head->next;
        head->next=newnode;
    }
}

void pop_front(){
    if(g_pHead == NULL) printf("-1\n");
    else{
        printf("%d\n",g_pHead->data);
        g_pHead = g_pHead->next;
    }
}

void pop_back(){
    NODE* head = g_pHead;
    if(head == NULL) printf("-1\n");
    else if (head->next == NULL)
    {
        printf("%d\n",head->data);
        g_pHead = 0;
    }
    
    else{
        while(head->next->next != NULL) head=head->next;
        printf("%d\n",head->next->data);
        head->next=0;
    }
}

void size(){
    int s=0;
    NODE* head = g_pHead;
    while(head!=NULL){
        s++;
        head=head->next;
    }
    printf("%d\n",s);
}

void empty(){
    if(g_pHead==NULL) printf("1\n");
    else printf("0\n");
}

void front(){
    if(g_pHead == NULL) printf("-1\n");
    else printf("%d\n",g_pHead->data);
}

void back(){
    if(g_pHead == NULL) printf("-1\n");
    else{
        NODE* head = g_pHead;
        while(head->next != NULL) head=head->next;
        printf("%d\n",head->data);
    }
}


int main(){
    
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char oder[12];
        int x;
        scanf("%s",oder);

        switch (oder[1])
        {        
        case 'u': scanf("%d",&x);
            break;

        case 'i': size();
            break;

        case 'm': empty();
            break;

        case 'r': front();
            break;

        case 'a': back();
            break;
        }
        if(!strcmp(oder,"push_front")) push_front(x);
        else if(!strcmp(oder,"push_back")) push_back(x);
        else if(!strcmp(oder,"pop_front")) pop_front();
        else if(!strcmp(oder,"pop_back")) pop_back();
    }

    free(g_pHead);
    return 0;
}