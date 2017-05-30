#include <stdio.h>

#include <stdlib.h>

#define STACK_SIZE 100

#define STACKADDSIZE 10

struct Stack

{

    int *bottom;

    int *top;

    int stack_size;

};

void InitStack(Stack &s);

int DestroySack(Stack &s);

int ClearStack(Stack &s);

int EmptyStack(Stack s);

int LengthStack(Stack s);

int GetTop(Stack s);

void Push(Stack &s,int e);

int Pop(Stack &s);

void VisitStack(Stack s);



void InitStack(Stack &s)

{

    s.bottom=(int *)malloc(STACK_SIZE*sizeof(int));

    if(!s.bottom)

        exit(0);

    s.top=s.bottom;

    s.stack_size=STACK_SIZE;

}

int DestroySack(Stack &s)

{

    int e;

    while(s.bottom!=s.top)

    {

        e=Pop(s);

    }

    free(s.bottom);

    free(s.top);

    return 1;

}

int ClearStack(Stack &s)

{

    int e;

    while(s.top!=s.bottom)

    {

        e=Pop(s);

    }

    return 1;

}

int EmptyStack(Stack s)

{

    if(s.bottom==s.top)

        return 1;

    else

        return 0;

}

int LengthStack(Stack s)

{

    return (s.top-s.bottom);

}

int GetTop(Stack s)

{

    if(s.bottom==s.top)

        return 0;

    else

        return (*(s.top-1));

}

void Push(Stack &s,int e)

{

    if(s.top-s.bottom>=s.stack_size)

    {

        s.bottom=(int *)realloc(s.bottom,(s.stack_size+STACKADDSIZE)*sizeof(int));

        if(!s.bottom)

            exit(0);

        s.top=s.bottom+s.stack_size;

        s.stack_size+=STACKADDSIZE;

    }

    *s.top++=e;

}

int Pop(Stack &s)

{

    s.top-=1;

    return (*s.top);

}

void VisitStack(Stack s)

{

    while(s.bottom!=s.top)

    {

        s.top=s.top-1;

        printf("%d\t",*s.top);

    }

    printf("\n");

}
