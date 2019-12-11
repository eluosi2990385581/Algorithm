#include<stdio.h>
#include<stdlib.h> 
#include<math.h>

#define INFINITY 1000000
#define MaxStationNum 501
#define Vertex int
#define RoadWeight int
#define ERROR -1

//define the storage structure of the graph
typedef struct GNode *PtrtoGNode;
struct GNode {
	int Nv;//the number of vertices of the graph
	int Ne;//the number of edges of the graph
	RoadWeight G[MaxStationNum][MaxStationNum];//the length of edges of the graph
	Vertex NumberWeight[MaxStationNum];//the weight of vertices of the graph
};
typedef PtrtoGNode MGraph;

//define the storage structure of the edge
typedef struct ENode *PtrtoENode;
struct ENode {
	Vertex V1, V2;//two vertices of the edge
	RoadWeight Weight;//the length of the edge
};
typedef PtrtoENode Road;

//define the storage structure of the shortest paths between the PBMC and the problem station
struct PNode {
	Vertex pre[MaxStationNum];//the precursor vertex of the vertex
	Vertex top;//the number of the shortest paths
};

//As these variables are invoked in multiple functions, we define them as global variables.
Vertex Cmax;
int MinNeed = INFINITY, MinRemain = INFINITY;
struct PNode Path[MaxStationNum], TempPath, LastPath;

//function definition
MGraph ReadGraph(int N, int M);//build a graph
Vertex Findmin(MGraph Graph, int dist[], int Known[]);//Return the vertex in the graph which have not been visited and have the minimum dist
MGraph ShortestPath(MGraph Graph, Vertex S);//find out several shortest paths
void DepthFirstSearch(MGraph Graph, Vertex S);//find the path which needs the least bikes
void PrintPath();//output the relevant information

/*
First of all, we store the station information in the graph structure, 
then use the Dijkstra's Algorithm to find out several shortest paths and store them in the structure array, 
after that, we use the depth first search algorithm to find the path which needs the least bikes, 
and finally output the relevant information
*/
int main()
{
	int N, M;
	Vertex Sp;
	
	//Input the maximum capacity of each station, the total number of stations,
	//the index of the problem station, the number of roads.
	scanf("%d%d%d%d", &Cmax, &N, &Sp, &M);
	MGraph Graph;
	Graph = ReadGraph(N, M);
	Graph = ShortestPath(Graph, 0);
	DepthFirstSearch(Graph, Sp);
	PrintPath();
}

/* 
 In this function, we store the station information in the graph structure.
 Firstly,input N non-negative numbers,which stand for the current number of bikes at a station.
 For convenience, we subtract the number of bikes in half full state from the current number, 
 so that we can judge whether the station needs or remains bikes by judging the positive and negative values.
 Then M lines follow, each contains two stations of a road and the time taken to move between them,​
 and we store all of them in a graph.
 */
MGraph ReadGraph(int N, int M)
{
	MGraph Graph;
	Road E;
	Vertex V, W;
	int i;

	//Initialization
	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = N + 1;
	Graph->Ne = 0;
	TempPath.top = 0;
	for (V = 0; V <= N; V++) {
		for (W = 0; W <= N; W++) {
			Graph->G[V][W] = INFINITY;
		}
	}

	//Input the current number of bikes at a station
	for (V = 1; V <= N; V++) {
		scanf("%d", &Graph->NumberWeight[V]);
		Graph->NumberWeight[V] -= Cmax / 2;
		Path[V].top = 0;
	}
	Graph->NumberWeight[0] = 0;//As the PBMC neither needs nor remains bikes, we assume it's zero.

	//Input the road information
	Graph->Ne = M;
	if (M != 0) 
	{
		E = (Road)malloc(sizeof(struct ENode));
		for (i = 0; i < M; i++) {
			scanf("%d%d%d", &E->V1, &E->V2, &E->Weight);
			Graph->G[E->V1][E->V2] = E->Weight;
			Graph->G[E->V2][E->V1] = E->Weight;
		}
	}
	return Graph;
}

/*
 In this function, we use the Dijkstra's Algorithm to find out several shortest paths, 
 and store them in the structure array.
 We define two arrays: dist and Known. The first one is used to save the minimum distance 
 from the vertex to the source vertex, and the other is used to save the visit of the vertex. 
 Each time we visit the minimum dist value from the array Known, we update the dist value of 
 its adjacent points, and save the precursor node of the shortest path in the Path structure 
 array until all the vertices are visited.
 */
MGraph ShortestPath(MGraph Graph, Vertex S)
{
	//Initializing the arrays
	int N;
	N = Graph->Nv;
	int dist[MaxStationNum], Known[MaxStationNum];
	Vertex V, W;
	for (V = 0; V < N; V++) {
		dist[V] = Graph->G[S][V];
		Known[V] = 0;
	}
	dist[S] = 0;

	//Visit vertices in order, update the shortest distance and save it in the array structure
	while (1) {
		V = Findmin(Graph, dist, Known);
		if (V == ERROR) break;
		Known[V] = 1;
		for (W = 0; W < N; W++) {
			if (Known[W] == 0 && Graph->G[V][W] < INFINITY) 
			{
				if (dist[V] + Graph->G[V][W] < dist[W]) 
				{
					dist[W] = dist[V] + Graph->G[V][W];
					Path[W].top = 0;
					Path[W].pre[Path[W].top] = V;
					Path[W].top++;
				}
				else if (dist[V] + Graph->G[V][W] == dist[W])
				{
					Path[W].pre[Path[W].top] = V;
					Path[W].top++;
				}
			}
		}
	}
	return Graph;
}

/*
 In this function, we find the lowest dist among the vertices we've never visited.
 If all of the vertices are visited, return ERROR.
*/
Vertex Findmin(MGraph Graph, int dist[], int Known[])
{
	Vertex V, MinV;
	int Mindist = INFINITY;
	for (V = 0; V < Graph->Nv; V++) {
		if (Known[V] == 0 && dist[V] < Mindist) 
		{
			Mindist = dist[V];
			MinV = V;
		}
	}
	if (Mindist == INFINITY) return ERROR;
	return MinV;
}

/*
 In this function, we find the best path from the shortest paths.
 We recursively find out each shortest path from the Path structure array, 
 store the path in TempPath, and then calculate the number of bikes required for 
 each shortest path and the number of bikes remained, 
 so as to save the better path in LastpPath.
 */
void DepthFirstSearch(MGraph Graph, Vertex S)
{
	int i;
	if (S == 0) //recursive boundary
	{ 
		TempPath.pre[TempPath.top] = S;//store the vertices in the path to TempPath
		TempPath.top++;
		int need = 0, remain = 0;

		//calculate the number of bikes required or remained in the path from the source station to the problem station
		for (i = TempPath.top - 1; i >= 0; i--) 
		{
			Vertex id = TempPath.pre[i];
			int w = Graph->NumberWeight[id];
			if (w > 0) //we need to take some bikes
			{
				remain += w;
			}
			else 
			{
				if (remain > abs(w)) //current bikes remain is sufficient
				{
					remain -= abs(w);
				}
				else //current bikes remain is not sufficient
				{
					need += abs(w) - remain; //we need to carry somes bikes from PBMC
					remain = 0;
				}
			}
		}

		//Optimize the path
		if (need < MinNeed) 
		{
			MinNeed = need;
			MinRemain = remain;
			LastPath = TempPath;
		}
		else if (need == MinNeed && remain < MinRemain) 
		{
			MinRemain = remain;
			LastPath = TempPath;
		}
		TempPath.top--;
		return;
	}
	TempPath.pre[TempPath.top] = S; //recursively store the vertices in the path to TempPath
	TempPath.top++;
	for (i = 0; i < Path[S].top; i++) //loop through each path
		DepthFirstSearch(Graph, Path[S].pre[i]);
	TempPath.top--;
}

/*
 In this function, we output the relevant information from the best path.
 */
void PrintPath()
{
	int i;
	printf("%d ", MinNeed);
	for (i = LastPath.top - 1; i >= 0; i--) {
		printf("%d", LastPath.pre[i]);
		if (i > 0) printf("->");
	}
	printf(" %d", MinRemain);
	return;
}
