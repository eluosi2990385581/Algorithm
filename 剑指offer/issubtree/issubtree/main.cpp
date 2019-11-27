#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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
    
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot2)return false;
        stack<TreeNode*> s,s1,s2;
        TreeNode* p=pRoot1;
        int flag=0;
        while(p||!s.empty())
        {
            while(p)
            {
                s.push(p);
                p=p->left;
            }
            if(!s.empty())
            {
                p=s.top();
                s.pop();
                
                if(p->val==pRoot2->val)
                {
                    if(isequal2(p, pRoot2))return true;
                }
                p=p->right;
                
            }
        }
        if(flag==0)return false;
        
        //判断p、proot2是否相等
        vector<int> a1,a2;
        
        while(p||!s1.empty())
        {
            while(p)
            {
                s1.push(p);
                p=p->left;
            }
            if(!s1.empty())
            {
                p=s1.top();
                s1.pop();
                
                a1.push_back(p->val);
                p=p->right;
                
            }
        }
        
        while(pRoot2||!s2.empty())
        {
            while(pRoot2)
            {
                s2.push(pRoot2);
                pRoot2=pRoot2->left;
            }
            if(!s2.empty())
            {
                pRoot2=s2.top();
                s2.pop();
                
                a2.push_back(pRoot2->val);
                pRoot2=pRoot2->right;
                
            }
        }
        
        int flag1=1,i=0;
        if(a1.size()!=a2.size())return false;
        for(i=0;i<a1.size();i++)
        {
            if(a1[i]!=a2[i])
            {
                flag1=0;
                break;
            }
        }
        
        if(flag1==0)return false;
        else return true;
    }
    
    void Travel_tree(Tree T){
        if(!T)return;
        Travel_tree(T->left);
        cout<<T->val;
        Travel_tree(T->right);
    }
    void level_travelsal(Tree T){
        if(!T)return;
        queue<TreeNode*> q;
        TreeNode* t1;
        q.push(T);
        while(!q.empty())
        {
            t1=q.front();
            q.pop();
            cout<<t1->val;
            if(t1->left)q.push(t1->left);
            if(t1->right)q.push(t1->right);
        }
    }
    bool isequal2(TreeNode* p,TreeNode* pRoot2)
    {
        if(p==NULL&&pRoot2==NULL)return 1;
        if(p!=NULL&&pRoot2!=NULL)
        {
            if(p->val==pRoot2->val)return isequal2(p->left,pRoot2->left)&&isequal2(p->right,pRoot2->right);
            else return 0;
        }
        else return 0;
        
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
    Tree T1,T2;
    Solution S;
    T1=S.reConstructBinaryTree(pre,vin);
    //S.Travel_tree(T1);
    T2=new TreeNode(4);
    T2->right=new TreeNode(7);
    if(S.HasSubtree(T1,T2))cout<<"right"<<endl;
    S.level_travelsal(T2);
    
    return 0;
}
