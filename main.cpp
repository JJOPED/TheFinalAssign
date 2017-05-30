#include "include/stack.h"
#include "include/tree.h"
#include "include/queue.h"
#include "include/graph.h"

void StackTest()

{

    Stack s;

    InitStack(s);

    int i,n;

    n=5;

    for(i=0; i<n; i++)

    {

        Push(s,i+1);

    }

    VisitStack(s);

    printf("EmptyStack:%d\n",EmptyStack(s));

    printf("GetTop:%d\n",GetTop(s));

    printf("Pop:%d\n",Pop(s));

    printf("LengthStack:%d\n",LengthStack(s));

    printf("ClearStack:%d\n",ClearStack(s));

    printf("DestroyStack:%d\n",DestroySack(s));

    printf("EmptyStack:%d\n",EmptyStack(s));

}

void TreeTest()

{

    BTree bt;

    printf("按照先序次序输入二叉树各个节点的元素值，叶子节点为空用空格表示：\n");

    CreateBTree(bt);

    printf("EmptyBTree:%d\n",EmptyBTree(bt));

    printf("RootBTree:%c\n",RootBTree(bt));

    printf("PreOrderTraverse:");

    PreOrderTraverse(bt);

    printf("\n");

    printf("InorderTraverse:");

    InOrderTraverse(bt);

    printf("\n");

    printf("PostOrderTraverse:");

    PostOrderTraverse(bt);

    printf("\n");

    printf("DepthBTree:%d\n",DepthBTree(bt));

    printf("CountNode:%d\n",CountNode(bt));



}

void QueueTest()
{
    LQueue q;
    InitLQueue(q);
    int i,n,e;
    n=5;
    for(i=1; i<=n; i++)
    {
        EnLQueue(q,i);
    }
    VisitLQueue(q);
    printf("EmptyLQueue:%d\n",EmptyLQueue(q));
    printf("LengthLQueue:%d\n",LengthLQueue(q));
    printf("GetHead:%d\n",GetHead(q));
    DeLQueue(q,e);
    printf("DeLQueue:%d\n",e);
    VisitLQueue(q);
    printf("ClearLQueue:%d\n",ClearLQueue(q));
    printf("EmptyLQueue:%d\n",EmptyLQueue(q));
    printf("DestroyLQueue:%d\n",DestroyLQueu(q));
    printf("EmptyLQueue:%d\n",EmptyLQueue(q));
}

void GraphTest()

{

    Graph G;

    int v=8;

    int a=9;

    char s[8]= {'A','B','C','D','E','F','G','H'};

    int m[8][8]= {{0,1,1,0,0,0,0,0},{1,0,0,1,1,0,0,0},

        {1,0,0,0,0,1,1,0},{0,1,0,0,0,0,0,1},{0,1,0,0,0,0,0,1},

        {0,0,1,0,0,0,1,0},{0,0,1,0,0,1,0,0},{0,0,0,1,1,0,0,0}

    };

    CreateGraph(G,v,a,s,m);

    printf("LocateVex(B):%d\n",LocateVexGraph(G,'B'));

    printf("DFSTraverse:");

    DFSTraverse(G);

    printf("\n");

    printf("BESTraverse:");

    BESTraverse(G);

    printf("\n");

    printf("FirstAdjVex:%c\n",FirstAdjVex(G,'A'));

    printf("NextAdjVex:%c\n",NextAdjVex(G,'A','C'));

    DeleteVex(G,'A');

    printf("DFSTraverse(AfterDeleteVex):");

    DFSTraverse(G);

    printf("\n");

    DeleteArc(G,'B','D');

    printf("DFSTraverse(AfterDeleteArc):");

    DFSTraverse(G);

    printf("\n");

    InsertArc(G,'B','D');

    printf("DFSTraverse(AfterInsertArc):");

    DFSTraverse(G);

    printf("\n");

    DestroyGraph(G);

    DFSTraverse(G);

}

int mian()
{
	StackTest();
	QueueTest();
	TreeTest();
	GraphTest();
	return 0;
}
