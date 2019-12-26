/* Author: 吴杰（WuJie）;  ID: 3180106238;  No.02 */

//  main.cpp
//  Bonus
//
//  Created by 吴杰 on 2019/12/24.
//  Copyright © 2019 吴杰. All rights reserved.
//  using C++

/**
 *
 *This problem is connected graph problem
 *First, we investigate whether the rest parts are connected after removing a point.
 *If they are not connected, we add the smallest edge to make
 *them connected and satisfy the requirement of not forming a ring structure
 *Then we need to use the set algorithm to determine whether a ring is formed
 *Then find out the cost of each city and store it in the array.
 *If the cut-off point leads to the increase of connectivity component, then the city is very important
 *Then normal output
 *
 */


#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

#define MOST_IMPORTANT 2e9

using namespace std;

//Data structure: edge.
//Contains the coordinates of the cities at both ends of the edge, the weight of the edge, and the initialization method of the edge
struct EdgeOfCities
{
    int city1,city2,w;
    EdgeOfCities(int t1,int t2,int t3):city1(t1),city2(t2),w(t3){}
};

//Weight refers to the cost of keeping other cities connected when the city is occupied. FA stands for parallel search
int N,M,weight[501],fa[501];
vector<int>res;//最终结果

//Highways in need of renovation and in use
vector<EdgeOfCities>destroyed,__good;

//Find the root of the connected city and compress the path operation to optimize the search algorithm time
int find_compression_path(int x);

//To find out whether a city is connected or not, that is, to find out how many connected components there are and return the number of connected components, which is realized by using the combination of search sets
int numberOfset();

//starts with a line containing 2 numbers N (≤500), and M, which are the total number of cities, and the number of highways, respectively. Then M lines follow, each describes a highway by 4 integers: City1 City2 Cost Status where City1 and City2 are the numbers of the cities the highway connects (the cities are numbered from 1 to N)
void input();

//It is used to arrange the loss degree in order after inputting data
void update();

//Initial state: each point is its own father, that is, it is not related to other points
void initialize();

//In addition to I City, find out the connectivity of other cities, and store set fa
void connect_expect_ith(int i);

//Calculate the consideration cost of the city and store it in the weight array
void compute_ith_cost(int i);

//First find the most important city and output it in the output format
void output();


//Sorting method: if the weight of the edge is large, it will be ranked first
bool cmp(EdgeOfCities t1,EdgeOfCities t2)
{
    return t1.w<t2.w;
}


int main(){
    input();
    //It is guaranteed to start from the edge with the least weight, so as to obtain the minimum consideration cost when the city is damaged
    update();
    
    //Here, suppose the i-th city is destroyed, find out the consideration cost of the city, and traverse all cities
    for(int i=1;i<=N;++i)
    {
        //Initial state: each point is its own father, that is, it is not related to other points
        initialize();
        
        //In addition to I City, find out the connectivity of other cities, and store set fa
        connect_expect_ith(i);
        
        //Calculate the consideration cost of the city and store it in the weight array
        compute_ith_cost(i);
        
        //If the i-th city is cut off, the city is very important!
        if(numberOfset()>2)
            weight[i]=MOST_IMPORTANT;
    }
    output();
    
    return 0;
}


int find_compression_path(int x){
    if(x==fa[x])
        return x;
    int temp=find_compression_path(fa[x]);
    fa[x]=temp;
    return temp;
}
int numberOfset()
{
    int root=0;
    for(int i=1;i<=N;++i)
        if(fa[i]==i)
            ++root;
    return root;
}

void input()
{
    cin>>N>>M;
    for(int i=0;i<M;++i){
        int t1,t2,t3,t4;
        cin>>t1>>t2>>t3>>t4;
        if(t4==0)
            destroyed.push_back(EdgeOfCities(t1,t2,t3));
        else
            __good.push_back(EdgeOfCities(t1,t2,t3));
    }
}


void update()
{
    sort(destroyed.begin(),destroyed.end(),cmp);
}



void initialize()
{
    for(int k=0;k<=N;++k)
        fa[k]=k;
}

void connect_expect_ith(int i)
{
    for(int i1=0;i1<__good.size();i1++)
    {
        EdgeOfCities tempedge=__good[i1];
        int temp1=find_compression_path(tempedge.city1);
        int temp2=find_compression_path(tempedge.city2);
        if(tempedge.city1!=i&&tempedge.city2!=i&&temp1!=temp2)
            fa[temp1]=temp2;
    }
}

void compute_ith_cost(int i)
{
    for(int i1=0;i1<destroyed.size();i1++)
    {
        EdgeOfCities tempedge=destroyed[i1];
        int temp1=find_compression_path(tempedge.city1);
        int temp2=find_compression_path(tempedge.city2);
        if(tempedge.city1!=i&&tempedge.city2!=i&&temp1!=temp2)
        {
            fa[temp1]=temp2;
            weight[i]+=tempedge.w;
        }
    }
}

void output()
{
    int tempMax=0;
    for(int i=1;i<=N;++i)
        if(weight[i]!=0&&weight[i]>tempMax)
        {
            tempMax=weight[i];
            res.clear();
            res.push_back(i);
        }
        else if(weight[i]!=0&&weight[i]==tempMax)
            res.push_back(i);
    if(res.empty()==true)
        cout<<"0"<<endl;
    for(int i=0;i<res.size();++i)
        {
            if(i==0)
                cout<<res[i];
            else
                cout<<" "<<res[i];
        }
}
