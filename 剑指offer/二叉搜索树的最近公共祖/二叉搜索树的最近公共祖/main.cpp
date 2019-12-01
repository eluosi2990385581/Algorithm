//
//  main.cpp
//  二叉搜索树的最近公共祖
//
//  Created by 吴杰 on 2019/11/26.
//  Copyright © 2019 吴杰. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *father;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL),father(NULL) {
    }
};

TreeNode *build_BST(vector<int> a,int length);
TreeNode *serch_value(int a,TreeNode *T);
void find(int a,int b,TreeNode *T);

int main(int argc, const char * argv[]) {
    vector<int> a;
//    int arr[]={6,3,1,2,5,4,8,7};
//    for(int i=0;i<8;i++)
//        a.push_back(arr[i]);
    int n,m,temp,length=0;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>temp;
        a.push_back(temp);
        length++;
    }
    TreeNode *T=build_BST(a, length);
    
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        
        find(a,b,T);
    }
    
    return 0;
}

TreeNode *build_BST(vector<int> a,int length)
{
    TreeNode *T1=new TreeNode(a[0]);
    int length1=0;
    for(int i=1;i<length;i++)
    {
        if(a[i]>a[0])break;
        length1++;
    }
    int length2=length-1-length1;
    if(length1)
    {
        vector<int> a1(a.begin()+1,a.begin()+length1+1);
        T1->left=build_BST(a1,length1);
        T1->left->father=T1;
    }
    if(length2)
    {
        vector<int> a2(a.begin()+length1+1,a.end());
        T1->right=build_BST(a2,length2);
        T1->right->father=T1;
    }
    return T1;
}


TreeNode *serch_value(int a,TreeNode *T)
{
    while(T)
    {
        if(a==T->val)return T;
        if(a<T->val)T=T->left;
        else T=T->right;
    }
    return T;
}

void find(int a,int b,TreeNode *T)
{
    if(!serch_value(a,T)||!serch_value(b,T))
    {
        if(!serch_value(a,T)&&!serch_value(b,T))
        {
            cout<<"ERROR: "<<a<<" and "<<b<<" are not found."<<endl;
            return;
        }
        if(!serch_value(a,T))
        {
            cout<<"ERROR: "<<a<<" is not found."<<endl;
            return;
        }
        else
        {
            cout<<"ERROR: "<<b<<" is not found."<<endl;
            return;
        }
    }
    vector<int> anc1,anc2;
    TreeNode *T1=serch_value(a,T);
    TreeNode *T2=serch_value(b,T);
    int val1,val2;
    val1=T1->val;
    val2=T2->val;
    while(T1->father)
    {
        int temp=T1->father->val;
        anc1.push_back(temp);
        T1=T1->father;
    }
    while(T2->father)
    {
        int temp2=T2->father->val;
        anc2.push_back(temp2);
        T2=T2->father;
    }
    for(int i=0;i<anc1.size();i++)
    {
        if(val2==anc1[i])
        {
            cout<<b<<" is an ancestor of "<<a<<"."<<endl;
            return;
        }
    }
    for(int i=0;i<anc2.size();i++)
    {
        if(val1==anc2[i])
        {
            cout<<a<<" is an ancestor of "<<b<<"."<<endl;
            return;
        }
    }
    for(int i=0;i<anc1.size();i++)
        for(int j=0;j<anc2.size();j++)
        {
            if(anc1[i]==anc2[j])
            {
                cout<<"LCA of "<<a<<" and "<<b<<" is "<<anc1[i]<<"."<<endl;
                return;
            }
        }
}
