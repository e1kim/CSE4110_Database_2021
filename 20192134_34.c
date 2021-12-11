#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char command[10];
    struct node *link;
}  QUEUE_NODE;

typedef struct{
    QUEUE_NODE *front;
    int count;
    QUEUE_NODE *rear;

}QUEUE;


int CheckCommand(char *command)
{
    if (!strcmp(command,"dir\n") || !strcmp(command,"cat\n") || !strcmp(command,"help\n") ||!strcmp(command,"mkdir\n") || !strcmp(command,"cd\n") || !strcmp(command,"ls\n")|| !strcmp(command,"cp\n") )
    {
        return 1;
    }
    else return 0;
}

void EnqCommand(QUEUE *pQueue, char *dataIn)
{
    QUEUE_NODE *pNew;

    pNew = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
    strcpy(pNew->command,dataIn);
    
    if (pQueue->front) //null? no then push to rear.
    {
        pQueue->rear->link = pNew;
    }
    else // null? yes
    {
        pQueue->front = pNew;
    }
    pQueue->rear =pNew;
    pQueue->count ++;

}

int DequeuePrint(QUEUE *pQueue, char *dataOut)
{
    QUEUE_NODE *pDlt;

    if (pQueue->front)
    {
        pDlt = pQueue->front;
        strcpy(dataOut,pDlt->command);
        pQueue->front = pDlt -> link;
        pQueue->count --;
        free(pDlt);
        return 1;
    }
    else return 0;
}

int main()
{
    QUEUE *pQueue;
    pQueue = (QUEUE *)malloc (sizeof(QUEUE));
    pQueue->front = NULL;
    pQueue->rear=NULL;
    pQueue->count = 0;

    char buf[10];
    char output[10];

    while(1)
    {
        printf(">>");
        fgets(buf,10,stdin);
        if(!strcmp(buf,"quit\n")) break;
        if (CheckCommand(buf))
        {
            printf("[Valid] %s",buf);
            EnqCommand(pQueue,buf);
        }
        else printf("[Invalid] %s",buf);
        
    }
    while (DequeuePrint(pQueue,output))
    {
        printf("%s",output);
    
    }

    return 0;

}
