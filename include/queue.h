#include <stdio.h>
#include <stdlib.h>
typedef struct Qnode
{
    int data;
    struct Qnode *next;
} Qnode,*Qflag;
struct LQueue
{
    Qflag f;
    Qflag r;
};
void InitLQueue(LQueue &q)
{
    q.f=q.r=(Qflag)malloc(sizeof(Qnode));
    if(!q.f)
        exit(0);
    q.f->next=NULL;
}
int DestroyLQueu(LQueue &q)
{
    while(q.f)
    {
        q.r=q.f->next;
        free(q.f);
        q.f=q.r;
    }
    return 1;
}
int ClearLQueue(LQueue &q)
{
    void DeLQueue(LQueue &q,int &a);
    int e;
    while(q.f!=q.r)
    {
        DeLQueue(q,e);
    }
    return 1;
}
int EmptyLQueue(LQueue q)
{
    if(q.f==q.r)
        return 1;
    else
        return 0;
}
int LengthLQueue(LQueue q)
{
    return (q.r-q.f);
}
int GetHead(LQueue q)
{
    return (q.f->next->data);
}
void EnLQueue(LQueue &q,int e)
{
    Qflag p;
    p=(Qflag)malloc(sizeof(Qnode));
    if(!p)
        exit(0);
    p->data=e;
    p->next=NULL;
    q.r->next=p;
    q.r=p;
}
void DeLQueue(LQueue &q,int &e)
{
    if(q.f==q.r)
        exit(0);
    Qflag p;
    p=q.f->next;
    e=p->data;
    q.f->next=p->next;
    if(q.r==p)
        q.f=q.r;
    free(p);
}
void VisitLQueue(LQueue q)
{
    Qflag p;
    p=q.f->next;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}
