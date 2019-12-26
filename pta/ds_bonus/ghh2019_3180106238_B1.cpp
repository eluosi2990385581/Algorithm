/* Author: 吴杰（WuJie）;  ID: 3180106238;  No.01 */

//
//  main.cpp
//  Bonus
//
//  Created by 吴杰 on 2019/12/24.
//  Copyright © 2019 吴杰. All rights reserved.
//  using C++

/**
 *
 * This is the DFS problem of trees.
 * To ensure that the path results are arranged in descending order,
 * we need to rank the weight of each node from large to small when adding each node.
 * In this way, the results obtained by DFS are in line with the requirements.
 * In DFS, record the weight value from the root node to the currently traversed node.
 * If the weight is equal to the given value and the point is a leaf node,
 * then this vertex is one of the correct solutions.
 * I put these satisfied vertices in the vector.
 * Then find out the path from the root node to each node in the vector, and output.
 *
 */

#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

//define Maxsize of vertices
const int MAXSIZE=200;

//define TreeNode to store the information of nodes
//including weight node's childs
struct TreeNode{
    int weight;
    vector<int> child;
}Node[MAXSIZE];

//define input data:0<N≤100, the number of nodes in a tree, M (<N), the number of non-leaf nodes, and 0<S<2^​30​​ , the given weight number.
int n,m,S,sum=0;
//where fa is a two-digit number representing a given non-leaf node, cdnum is the number of its children, followed by a sequence of two-digit fa's of its children
int fa,cdnum,child;

//storing one path which is suitable for this problem in res.
vector<int> equal_path;
vector<vector<int> >res;

/**
 *
 *Depth first search.
 * When the sum of the satisfied paths is equal to the input value and there
 * is no redundant subtree at the end of the path,
 * it is a path that meets the conditions.
 * Add all the satisfied paths to res,
 * and then sort them in descending order in res.
 *
 **/
void DFS(int ID);

//input what you need and output the result you get.
void input();
void output();
//resort the given result order by non-increasing way,using sort() function
bool cmp(vector<int> a,vector<int> b);

int main()
{
    input();
    DFS(0);
    sort(res.begin(),res.end(),cmp);
    output();
    return 0;
}

void DFS(int ID)
{
    equal_path.push_back(Node[ID].weight);
    sum+=Node[ID].weight;
    if(Node[ID].child.size()==0){
        if(sum==S)
            res.push_back(equal_path);
    }
    for(int i=0;i<Node[ID].child.size();i++)
        DFS(Node[ID].child[i]);
    equal_path.pop_back();
    sum-=Node[ID].weight;
}

void input()
{
    cin>>n>>m>>S;
    for(int i=0;i<n;i++)
        cin>>Node[i].weight;
    for(int i=0;i<m;i++){
        cin>>fa>>cdnum;
        for(int j=0;j<cdnum;j++){
            cin>>child;
            Node[fa].child.push_back(child);
        }
    }
}

void output()
{
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            if(j!=res[i].size()-1) cout<<res[i][j]<<" ";
            else cout<<res[i][j]<<endl;
        }
    }
}

bool cmp(vector<int> a,vector<int> b)
{
    for(int i=0;i<a.size()&&i<b.size();i++){
        if(a[i]!=b[i])
            return a[i]>b[i];
    }
    return false;
}
