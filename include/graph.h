#include <stdio.h>

#include <stdlib.h>

#define MAXVRETEX 50

struct Graph

{

    char vertex[MAXVRETEX];

    int vexnum,arcnum;

    int Matricx[MAXVRETEX][MAXVRETEX];

};

void CreateGraph(Graph &G,int v,int a,char s[],int m[][8])

{

    int i,j;

    G.vexnum=v;

    G.arcnum=a;

    for(i=0; i<G.vexnum; i++)

    {

        G.vertex[i]=s[i];

    }

    for(i=0; i<G.vexnum; i++)

    {

        for(j=0; j<G.vexnum; j++)

        {

            G.Matricx[i][j]=m[i][j];

        }

    }

}

int DestroyGraph(Graph &G)

{

    int i;

    for(i=0; i<G.vexnum; i++)

    {

        G.vertex[i]=' ';

    }

    G.Matricx[MAXVRETEX][MAXVRETEX]=0;

    return 1;

}

int LocateVexGraph(Graph G,char u)

{

    int i;

    for(i=0; i<G.vexnum; i++)

    {

        if(G.vertex[i]==u)

            return i;

    }

    return -1;

}

char GetVexGraph(Graph G,int v)

{

    return G.vertex[v];

}

char PutVexGraph(Graph G,int v,char value)

{

    G.vertex[v]=value;

    return G.vertex[v];

}

char FirstAdjVex(Graph G,char v)

{

    int l=LocateVexGraph(G,v);

    int i;

    for(i=0; i<G.vexnum; i++)

    {

        if(G.Matricx[l][i]!=0)

        {

            return G.vertex[i];

        }

    }

    if(i==G.vexnum)

        return 'N';

}

char NextAdjVex(Graph G,char v,char w)

{

    int lv=LocateVexGraph(G,v);

    int lw=LocateVexGraph(G,w);

    int i;

    for(i=lw+1; i<G.vexnum; i++)

    {

        if(G.Matricx[lv][i]==1)

            return G.vertex[i];

    }

    return 'N';

}

void InsertVex(Graph &G,char v)

{

    G.vexnum+=1;

    G.vertex[G.vexnum-1]=v;

}

void DeleteVex(Graph &G,char v)

{

    int l=LocateVexGraph(G,v);

    int i,j;

    for(i=l; i<G.vexnum-1; i++)

    {

        for(j=l; j<G.vexnum-1; j++)

        {

            G.Matricx[i][j]=G.Matricx[i+1][j+1];

        }

        G.vertex[i]=G.vertex[i+1];

    }

    G.vexnum-=1;

}

void InsertArc(Graph &G,char v,char w)

{

    int lv=LocateVexGraph(G,v);

    int lw=LocateVexGraph(G,w);

    G.Matricx[lv][lw]=1;

    G.Matricx[lw][lv]=1;

}

void DeleteArc(Graph &G,char v,char w)

{

    int lv=LocateVexGraph(G,v);

    int lw=LocateVexGraph(G,w);

    G.Matricx[lv][lw]=0;

    G.Matricx[lw][lv]=0;

}

void DFSTraverse(Graph G)

{

    int flag[MAXVRETEX]= {0};

    int i,j,k;

    i=k=0;

    while(i<G.vexnum)

    {

        if(flag[i]==1)

        {

            i=k+1;

            k++;

            continue;

        }

        else

        {

            flag[i]=1;

            printf("%c ",G.vertex[i]);

            for(j=0; j<G.vexnum; j++)

            {

                if(G.Matricx[i][j]==1&&flag[j]==0)

                {

                    i=j;

                    break;

                }

            }

        }

    }

}

void BESTraverse(Graph G)

{

    int i,j;

    int flag[MAXVRETEX]= {0};

    i=0;

    while(i<G.vexnum)

    {

        if(flag[i]==0)

        {

            printf("%c ",G.vertex[i]);

            flag[i]=1;

        }

        for(j=0; j<G.vexnum; j++)

        {

            if(G.Matricx[i][j]==1&&flag[j]==0)

            {

                printf("%c ",G.vertex[j]);

                flag[j]=1;

            }

        }

        i++;

    }

}
