#include<iostream>
#include<vector>
using namespace std;
typedef struct TreeNode* Tree;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int root=pre[0],length=0;
        for(int i=0;i<vin.size();i++)
        {
            if(root==vin[i])break;
            length++;
        }
        TreeNode* T=new TreeNode(root);
        if(length!=0)
        {
            vector<int> p1(pre.begin()+1,pre.begin()+length+1);
            vector<int> i1(vin.begin(),vin.begin()+length);
            T->left=reConstructBinaryTree(p1,i1);
        }
        
        if(length+1!=vin.size())
        {
            vector<int> p2(pre.begin()+length+1,pre.end());
            vector<int> i2(vin.begin()+length+1,vin.end());
            T->right=reConstructBinaryTree(p2,i2);
        }
        
        return T;
    }
    
    void Travel_tree(Tree T){
        if(!T)return;
        Travel_tree(T->left);
        cout<<T->val;
        Travel_tree(T->right);
    }
};

int main()
{
    vector<int> pre;int a1[]={1,2,4,7,3,5,6,8};
    vector<int> vin;int a2[]={4,7,2,1,5,3,8,6};
    for(int i=0;i<8;i++)
        pre.push_back(a1[i]);
    for(int i=0;i<8;i++)
        vin.push_back(a2[i]);
    Tree T1;
    Solution S;
    T1=S.reConstructBinaryTree(pre,vin);
    S.Travel_tree(T1);
    
    return 0;
}
