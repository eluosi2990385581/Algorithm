#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define INFINITY 1000000
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */
typedef int WeightType;
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

void ShortestDist( MGraph Graph, int dist[], int count[], Vertex S );

int main()
{
    int dist[MaxVertexNum], count[MaxVertexNum];
    Vertex S, V;
    int i,j;
    MGraph G1 = (MGraph)malloc(sizeof(struct GNode));
    for(i=0;i<MaxVertexNum;i++)
        for(j=0;j<MaxVertexNum;j++)
            G1->G[i][j]=INFINITY;
    G1->G[3][0]=40;
    G1->G[3][1]=20;
    G1->G[3][2]=100;
    G1->G[3][7]=70;
    G1->G[0][4]=5;
    G1->G[0][7]=10;
    G1->G[4][7]=5;
    G1->G[6][2]=1;
    G1->G[7][2]=50;
    G1->G[7][5]=3;
    G1->G[1][7]=30;
    G1->Nv=8;
    G1->Ne=11;
    scanf("%d", &S);
    ShortestDist( G1, dist, count, S );
    for ( V=0; V<G1->Nv; V++ )
        printf("%d ", dist[V]);
    printf("\n");
    for ( V=0; V<G1->Nv; V++ )
        printf("%d ", count[V]);
    printf("\n");
    return 0;
}


void ShortestDist( MGraph Graph, int dist[], int path[], Vertex S )
{
    bool isvisit[MaxVertexNum]={false};
    dist[S]=0;
    path[S]=-1;
    int path_length[MaxVertexNum]={0};
    for(Vertex i=0;i<Graph->Nv;i++)
    {
        if(i!=S)
        {
            dist[i]=Graph->G[S][i];
            path[i]=S;
        }
        
    }
    
    //find shortest distance
    while(1)
    {
        Vertex min=INFINITY;
        Vertex v=-1;
        for(Vertex i=0;i<Graph->Nv;i++)
            if(isvisit[i]==false)
                if(dist[i]<min)
                {
                    min=dist[i];
                    v=i;
                }
        
        
        if(v==-1)break;
        isvisit[v]=true;
        
        for(Vertex i=0;i<Graph->Nv;i++)
        {
            if(Graph->G[v][i]!=INFINITY)
            {
                if(dist[i] > Graph->G[v][i] + dist[v])
                {
                    dist[i]=Graph->G[v][i]+dist[v];
                    path[i]=v;
                    path_length[i]=path_length[v]+1;
                }
                else if(dist[i]==Graph->G[v][i] + dist[v])
                {
                    if(path_length[i]>path_length[v]+1)
                    {
                        path[i]=v;
                        path_length[i]=path_length[v]+1;
                    }
                }
                    
            }
        }
    }
    for(Vertex i=0;i<Graph->Nv;i++)
        if(dist[i]==INFINITY)
        {
            dist[i]=-1;
            path[i]=-1;
        }
}

void ShortestDist( MGraph Graph, int dist[], int count[], Vertex S )
{
    bool visit[MaxVertexNum]={false};
    
    
    
    //数组模拟队列，BST方法遍历图找出不连通点
    int queue1[MaxVertexNum]={-1};
    int tail=-1,front=-1;
    int temp=S;
    
    queue1[++tail]=S;
    while(tail!=front)
    {
        temp=queue1[++front];
        for(int i=0;i<Graph->Nv;i++)
        {
            if(visit[i]!=true && Graph->G[temp][i]!=INFINITY)
            {
                visit[i]=true;
                queue1[++tail]=i;
            }
        }
    }
    
    //BST遍历完之后尚未访问的点即为与S无路径的点
    for(int i=0;i<Graph->Nv;i++)
    {
        if(visit[i]==false)
        {
            dist[i]=-1;
            count[i]=0;
        }
    }
    
    //Dijkstra算法，求最短路径
    
    
}
