#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *push(int data,node *top)
{
    node *temp = (node*)malloc(sizeof(node));
    if(temp==NULL)
        return NULL;
    temp->next = top;
    temp->data = data;
    top = temp;
    return top;
}

node *pop(int *data, node *top)
{
    if(top==NULL)
    {
        return NULL;
    }
    else
    {
        node *temp = top;
        *data = top->data;
        top = top->next;
        free(temp);
        return top;
    }
}

int main(int argc, char **argv)
{
    node *top = NULL;
    int data;
    top = push(1,top);
    top = pop(&data,top); printf("%d\n",data);
    top = push(10,top);
    top = push(5,top);
    top = push(6,top);
    top = push(3,top);
    top = pop(&data,top); printf("%d\n",data);
    top = pop(&data,top); printf("%d\n",data);
    top = pop(&data,top); printf("%d\n",data);
    return 0;   
}
