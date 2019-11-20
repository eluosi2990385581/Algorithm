#include<stdio.h>

#ifndef __GRAPH__ALGORITHM__
#define __GRAPH__ALGORITHM__

#define MaxVertexNum 100

//functions of graph operation

//adjcent matrix style

typedef char VertexType
typedef int EdgeType
typedef struct
{
    VertexTpye Vertex[MaxVertexNum];
    EdgeType Edge[MaxvertexNum][MaxVertexNum];
    int VertexNum;
    int EdgeNum;
}MatrixGraph;




#else
//do nothing

#endif
