#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int count;
    struct node* top;
} STACK;

typedef struct node{
    char data;
    struct node* link;
} STACK_NODE;

void push(STACK *pStack, char dataIn)
{
    STACK_NODE *pNew;

    pNew = (STACK_NODE *)malloc(sizeof(STACK_NODE));
        
    pNew->data = dataIn;
    pNew->link = pStack->top;
    pStack->top=pNew;
    pStack->count++;
}
int isEmpty(STACK *pStack)
{
    if (pStack->top == NULL)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
int pop(STACK *pStack)
{
    STACK_NODE *pDlt;
    
    char n;

    if (!isEmpty(pStack)) // empty? no
    {
        n=pStack->top->data;
        pDlt=pStack->top;
        pStack->top = (pStack->top) -> link;
        pStack->count--;
        free(pDlt);
    }
    else
    {
        n=-1;
    }

    return n;
}

void printS(STACK *pStack)
{
    if (pStack->count != 0)
    {
        STACK_NODE *ptr;
        ptr = pStack->top;
        
        while(ptr != NULL)
        {
            printf("%c",ptr->data);
            ptr = ptr->link;
        }printf("\n");
    }
    
}

int main()
{
    STACK* pStack;
    pStack = (STACK *)malloc(sizeof(STACK));
    pStack->top = NULL;
    pStack->count = 0;
    
    char input[101];
    printf("Enter the formula : ");    
    scanf("%100[^\n]",input);

    for (int i=0; i<strlen(input); ++i)
    {
        if (input[i] == '(')
        {
            push(pStack,input[i]);
        }
        else if(input[i] == '{')
        {
            push(pStack,input[i]);
        }
        else if (input[i] == '[')
        {
            push(pStack,input[i]);
        }
        else if (input[i] == ')')
        {
            if (pop(pStack) != '(')
            {
                printf("Unmatched Parenthese!\n");
                return 1;
            }

        }
        else if (input[i] == '}')
        {
            if (pop(pStack) != '{')
            {  
               printf("Unmatched Parenthese!\n");
               return 1;
            }
        }
        else if (input[i] == ']')
        {
            if (pop(pStack) != '[')
            {
               printf("Unmatched Parenthese!\n");
                return 1;
            }

        }
        

    }
    printf("Matched Parenthese!\n");


    return 0;
}
