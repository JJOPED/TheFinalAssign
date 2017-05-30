#include <iostream>

#include <stdio.h>

#include <stdlib.h>

using namespace std;

typedef struct BTNode

{

    char data;

    struct BTNode *lchild,*rchild;

}BTNode,*BTree;

char ch;

void CreateBTree(BTree &bt)

{

   ch=cin.get();

    if(ch==' ')

        bt=NULL;

    else if(ch=='\n')

        return;

    else

    {

        bt=(BTNode*)malloc(sizeof(BTNode));

        bt->data=ch;

        CreateBTree(bt->lchild);

        CreateBTree(bt->rchild);

    }

}

int EmptyBTree(BTree bt)

{

    if(bt==NULL)

        return 1;

    return 0;

}

int depthval=0;

int dl=0;

int dr=0;

int DepthBTree(BTree bt)

{

    if(!bt)

        return 0;

    else

    {

        dl=DepthBTree(bt->lchild);

        dr=DepthBTree(bt->rchild);

        depthval=1+(dl>dr?dl:dr);

        return depthval;

    }

}

int cnt=0;

int CountNode(BTree bt)

{

    if(bt)

    {

        cnt++;

        CountNode(bt->lchild);

        CountNode(bt->rchild);

    }

    return cnt;

}

char RootBTree(BTree bt)

{

    return (bt->data);

}

void PreOrderTraverse(BTree bt)

{

    if(bt!=NULL)

    {

        printf("%c ",bt->data);

        PreOrderTraverse(bt->lchild);

        PreOrderTraverse(bt->rchild);

    }

}

void InOrderTraverse(BTree bt)

{

    if(bt!=NULL)

    {

        InOrderTraverse(bt->lchild);

        printf("%c ",bt->data);

        InOrderTraverse(bt->rchild);

    }

}

void PostOrderTraverse(BTree bt)

{

    if(bt!=NULL)

    {

        PostOrderTraverse(bt->lchild);

        PostOrderTraverse(bt->rchild);

        printf("%c ",bt->data);

    }

}
