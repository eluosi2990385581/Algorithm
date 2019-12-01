//
//  main.cpp
//  12312
//
//  Created by 吴杰 on 2019/11/27.
//  Copyright © 2019 吴杰. All rights reserved.
//



#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
        }
};
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
struct node
{
    int val;
    struct node *left;
    struct node *right;
    node(int x):val(x),left(NULL),right(NULL){
    }
};

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};
class Solution {
public:
    
//    在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
    bool Find(int target, vector<vector<int> > array) {
        int i=array.size()-1,j=0;
        while(i>=0 && j<array[0].size())
        {
            if(target>array[i][j])j++;
            else if (target<array[i][j])i--;
            else return true;
        }
        return false;
    }
    
//    请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
    void replaceSpace(char *str,int length) {
        int blank=0,space=0;
        for(int i=0;i<length;i++)
            if(*(str+i)==' ')blank++;
        space=length+2*blank+1;
        
        for(int i=length+1;i>=0;i--)
        {
            if(*(str+i)==' ')
            {
                *(str+space)='0';
                space--;
                *(str+space)='2';
                space--;
                *(str+space)='%';
                space--;
            }
            else
            {
                *(str+space)=*(str+i);
                space--;
            }
        }
    }
    
    //输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int>reV;
        while(head!=NULL)
        {
            reV.push_back(head->val);
            head=head->next;
        }
        reverse(reV.begin(),reV.end());
        return reV;
    }
    
    //输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
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
    
    //用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
    stack<int> stack1;
    stack<int> stack2;
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
            
        int temp=stack2.top();
        stack2.pop();
        while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return temp;
    }
    
    //把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
    //输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
//    例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
//    NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())return 0;
        int i=0;
        while(true)
        {
            if(i==rotateArray.size())
            {
                return rotateArray[0];
            }
            if(rotateArray[i]>rotateArray[i+1])return rotateArray[i+1];
            i++;
        }
    }
    
//    大家都知道斐波那契数列，现在要求输入一个整数n，
//    请你输出斐波那契数列的第n项（从0开始，第0项为0）。
//    n<=39
    int Fibonacci(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        int n1=0,n2=1,n3;
        for(int i=3;i<=n+1;i++)
        {
            n3=n1+n2;
            n1=n2;
            n2=n3;
        }
        return n3;
    }
    
//    一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该
//    青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
    int jumpFloor(int number) {
        if(number==1)return 1;
        if(number==2)return 2;
        int n1=1,n2=2,n3;
        for(int i=3;i<=number;i++)
        {
            n3=n1+n2;
            n1=n2;
            n2=n3;
        }
        return n3;
    }
    
//    一只青蛙一次可以跳上1级台阶，也可以
//    跳上2级……它也可以跳上n级。求该青蛙跳上一
//    个n级的台阶总共有多少种跳法。
    int jumpFloorII(int number) {
        if(number==1)return 1;
        int a=1;
        for (int i=1;i<number;i++)
            a*=2;
        return a;
    }
    
//    我们可以用2*1的小矩形横着或者竖着
//    去覆盖更大的矩形。请问用n个2*1的小矩形无重
//    叠地覆盖一个2*n的大矩形，总共有多少种方法？
    int rectCover(int number) {
        if(number==0)return 0;
        if(number==1)return 1;
        if(number==2)return 2;
        int n1=1,n2=2,n3;
        for(int i=2;i<number;i++)
        {
            n3=n1+n2;
            n1=n2;
            n2=n3;
        }
        return n3;
    }
    
    //输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
    int  NumberOf1(int n) {
        int count=0;
        int flag=1;
        while(flag)
        {
            if(n&flag)count++;
            flag=flag<<1;
        }
        return count;
    }
    
    
//    给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
//
//    保证base和exponent不同时为0
    
    double Power(double base, int exponent) {
        double base1=base;
        if(base==0)return 0;
        if(exponent==0)return 1;
        if(exponent<0){
            base1=1/base;
            base=base1;
            exponent=-exponent;
        }
        
        for(int i=0;i<exponent-1;i++)
            base*=base1;
        return base;
    }
    
//    输入一个整数数组，实现一个函数来调整该数
//    组中数字的顺序，使得所有的奇数位于数组的
//    前半部分，所有的偶数位于数组的后半部分，并保证奇
//    数和奇数，偶数和偶数之间的相对位置不变。
    void reOrderArray(vector<int> &array) {
        vector<int> left,right;
        for(int i=0;i<array.size();i++)
        {
            if(array[i]%2==1)left.push_back(array[i]);
            else right.push_back(array[i]);
        }
        for(int i=0;i<array.size();i++)
        {
            if(i<left.size())array[i]=left[i];
            else array[i]=right[i-left.size()];
        }
    }
    
    //输入一个链表，输出该链表中倒数第k个结点。
    
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        int length=0;
        ListNode* temp=pListHead;
        while(temp)
        {
            length++;
            temp=temp->next;
        }
        if(length<k)return NULL;
        for(int i=0;i<length-k;i++)
            pListHead=pListHead->next;
        return pListHead;
    }
    
    //输入一个链表，反转链表后，输出新链表的表头。
    ListNode* ReverseList(ListNode* pHead) {
    if(!pHead||!pHead->next)return pHead;
    ListNode* p=pHead;
    ListNode* q=p->next;
    ListNode* r=NULL;
    while(q)
    {
        p->next=r;
        r=p;
        p=q;
        q=q->next;
    }
    p->next=r;
    return p;
    }
        
//    输入两个单调递增的链表，输出两个链表
//        合成后的链表，当然我们需要合成后的链表满足单调不减规则。
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1)return pHead2;
        if(!pHead2)return pHead1;
        ListNode* head;
        ListNode* temp;
        if(pHead1->val<pHead2->val)
        {
            head=new ListNode(pHead1->val);
            temp=head;
            pHead1=pHead1->next;
        }
        else
        {
            head=new ListNode(pHead2->val);
            temp=head;
            pHead2=pHead2->next;
        }
        while(pHead1 && pHead2)
        {
            if(pHead1->val<pHead2->val)
            {
                temp->next=new ListNode(pHead1->val);
                temp=temp->next;
                pHead1=pHead1->next;
            }
            else
            {
                temp->next=new ListNode(pHead2->val);
                temp=temp->next;
                pHead2=pHead2->next;
            }
        }
        if(pHead1)temp->next=pHead1;
        if(pHead2)temp->next=pHead2;
        return head;
    }
    
    //输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
    
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
                if(p&&pRoot2)
                if(p->val==pRoot2->val)
                {
                    if(isequal2(p,pRoot2))
                        return true;
                }
                p=p->right;
                
            }
        }
        if(flag==0)return false;
        
        //判断p、proot2是否相等
        
    
    
    }
    bool isequal(TreeNode* p,TreeNode* pRoot2)
    {
        vector<int> a1,a2;
        
        
        queue<TreeNode*> q,q1;
        
        q.push(p);
        while(!q.empty())
        {
            TreeNode* t1=q.front();
            q.pop();
            a1.push_back(t1->val);
            if(t1->left)q.push(t1->left);
            if(t1->right)q.push(t1->right);
        }
        q1.push(pRoot2);
        while(!q1.empty())
        {
            TreeNode* t2=q1.front();
            q1.pop();
            a2.push_back(t2->val);
            if(t2->left)q1.push(t2->left);
            if(t2->right)q1.push(t2->right);
        }
        
        int flag1=1,i=0;
        //if(a1.size()!=a2.size())return false;
        int m;
        if(a1.size()>a2.size())m=a2.size();
        else m=a1.size();
        for(i=0;i<m;i++)
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
    bool isequal2(TreeNode* p,TreeNode* pRoot2)
    {
        if(p==NULL&&pRoot2==NULL)return 1;
        if(p!=NULL&&pRoot2!=NULL)
        {
            if(p->val==pRoot2->val)return isequal2(p->left,pRoot2->left)&&isequal2(p->right,pRoot2->right);
            else return 0;
        }
        else if(pRoot2==NULL)return 1;
        else return 0;
        
    }
    
    
//    操作给定的二叉树，将其变换为源二叉树的镜像。
//    输入描述:
//    二叉树的镜像定义：源二叉树
//                8
//               /  \
//              6   10
//             / \  / \
//            5  7 9 11
//            镜像二叉树
//                8
//               /  \
//              10   6
//             / \  / \
//            11 9 7  5
    
    void Mirror(TreeNode *pRoot) {
        if(!pRoot)return;
        TreeNode *temp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=temp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
    
    
//    输入一个矩阵，按照从外向里以顺时针的顺序依次打印出
//    每一个数字，例如，如果输入如下4 X 4
//    矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
//    则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row=matrix.size(),col=matrix[0].size();
        int visit[row+2][col+2];
        for(int i=0;i<row+2;i++)
            for(int j=0;j<col+2;j++)
                {
                    if(i==0||i==row+1||j==0||j==col+1)visit[i][j]=1;
                    else visit[i][j]=0;
                }
        vector<int> printm;
        int i=0,j=0;
        while(!visit[i+1][j+2]||!visit[i+2][j+1]||!visit[i+1][j]||!visit[i][j+1])
        {
            while(!visit[i+1][j+2])
            {
                visit[i+1][j+1]=1;
                printm.push_back(matrix[i][j]);
                j++;
            }
            while(!visit[i+2][j+1])
            {
                visit[i+1][j+1]=1;
                printm.push_back(matrix[i][j]);
                i++;
            }
            while(!visit[i+1][j])
            {
                visit[i+1][j+1]=1;
                printm.push_back(matrix[i][j]);
                j--;
            }
            while(!visit[i][j+1])
            {
                visit[i+1][j+1]=1;
                printm.push_back(matrix[i][j]);
                i--;
            }
        }
        printm.push_back(matrix[i][j]);
        return printm;
    }
    
//    定义栈的数据结构，请在该类型中实现
//    一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
    int stack[100];
    int pointer=-1;
    int pointer_min=-1;
    void push(int value) {
        stack[++pointer]=value;
        if(pointer_min==-1)pointer_min=0;
        else
        {
            if(stack[pointer_min]>value)
                pointer_min=pointer;
        }
    }
    void pop() {
        if(pointer_min==pointer)
        {
            pointer_min=0;
            for(int i=0;i<pointer-1;i++)
            {
                if(stack[pointer_min]>stack[i])pointer_min=i;
            }
        }
        pointer--;
    }
    int top() {
        return stack[pointer];
    }
    int min() {
        return stack[pointer_min];
    }
    
//    输入两个整数序列，第一个序列表示栈的压入顺序，
//    请判断第二个序列是否可能为该栈的弹出顺序。假设压
//    入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈
//    的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个
//    弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
//    （注意：这两个序列的长度是相等的）
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    stack<int> s1,s2;
    int pointer=0;
    for(int i=popV.size()-1;i>=0;i--)
        s2.push(popV[i]);
    while(pointer<pushV.size())
    {
        s1.push(pushV[pointer]);
        while((!s1.empty()&&!s2.empty())&&(s1.top()==s2.top()))
        {
            if(s1.top()==s2.top())
            {
                s1.pop();
                s2.pop();
            }
        }
        pointer++;
    }
    if(s1.empty()&&s2.empty())return true;
    else return false;
    }
    
//    从上往下打印出二叉树的每个节点，同层节点从左至右打印。
    
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root)q.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
            res.push_back(temp->val);
        }
        return res;
    }
    
    
    
//    输入一个整数数组，判断该数组是
//    不是某二叉搜索树的后序遍历的结果
//    。如果是则输出Yes,否则输出No。假设输入的
//    数组的任意两个数字都互不相同。
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(!sequence.size())return 0;
        int length=0,i=0;
        while(sequence[sequence.size()-1]>sequence[i])
        {
            length++;
            i++;
        }
        for(int j=length;j<sequence.size()-1;j++)
        {
            if(sequence[sequence.size()-1]>sequence[j])return 0;
        }
        int flag1=1,flag2=1;
        if(length>0)
        {
            vector<int> left(sequence.begin(),sequence.begin()+length);
            flag1=VerifySquenceOfBST(left);
        }
        if(length<sequence.size()-1)
        {
            vector<int> right(sequence.begin()+length,sequence.end()-1);
            flag2=VerifySquenceOfBST(right);
        }
        return flag1&&flag2;
    }
    
//    输入一颗二叉树的跟节点和一个整数
//    ，打印出二叉树中结点值的和为输入整数
//    的所有路径。路径定义为从树的根结点开始往下一
//    直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
    
    vector<vector<int>> res;
    vector<int> temp;
    void find_path(TreeNode* root,int expectNumber)
    {
        if(!root)return;
        temp.push_back(root->val);
        if(!root->left && !root->right && root->val==expectNumber)
            res.push_back(temp);
        if(root->left)find_path(root->left,expectNumber-root->val);
        if(root->right)find_path(root->right,expectNumber-root->val);
        temp.pop_back();
    }
    vector<vector<int>> sorted(vector<vector<int>> a)
    {
        
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        find_path(root,expectNumber);
        
        return res;
    }
    
//    输入一个复杂链表（每个节点中有节点值
//    ，以及两个指针，一个指向下一个节点，另
//    一个特殊指针指向任意一个节点），返回结果为
//    复制后复杂链表的head。（注意，输出结果中请不要返
//    回参数中的节点引用，否则判题程序会直接返回空）
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)return pHead;
        RandomListNode* cp=new RandomListNode(pHead->label);
        RandomListNode *head=cp;
        RandomListNode *temp=pHead;
        while(temp->next)
        {
            temp=temp->next;
            cp->next=new RandomListNode(temp->label);
            cp=cp->next;
        }
        temp=pHead;
        cp=head;
        while(temp)
        {
            if(!temp->random)
            {
                cp=cp->next;
                temp=temp->next;
                continue;
            }
            int value=temp->random->label;
            RandomListNode *t=head;
            while(value!=t->label)t=t->next;
            cp->random=t;
            
            cp=cp->next;
            temp=temp->next;
        }

        return head;
    }
    
//    输入一棵二叉搜索树，将该二叉搜索树转换
//    成一个排序的双向链表。要求不能创建任何新的结
//    点，只能调整树中结点指针的指向。
    
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        stack<TreeNode*> s;
        TreeNode* pre=NULL;
        TreeNode* h=pRootOfTree;
        while(pRootOfTree||!s.empty())
        {
            while(pRootOfTree)
            {
                s.push(pRootOfTree);
                pRootOfTree=pRootOfTree->left;
            }
            pRootOfTree=s.top();
            s.pop();
            
            pRootOfTree->left=pre;
            if(pre)pre->right=pRootOfTree;
            pre=pRootOfTree;
            
            pRootOfTree=pRootOfTree->right;
        }
        pRootOfTree=h;
        while(pRootOfTree->left)pRootOfTree=pRootOfTree->left;
        return pRootOfTree;
    }
    
    
//    输入一个字符串,按字典序打印出该
//    字符串中字符的所有排列。例如输入字符串ab
//    c,则打印出由字符a,b,c所能排列出来的所有字符串
//    abc,acb,bac,bca,cab和cba。
//    输入描述:
//    输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母
    
    
    vector<string> res;
    vector<string> Permutation(string str) {
        FP(str,0);
        sort(res.begin(),res.end());
        return res;
    }
    void _swap(string &a,int i,int j)
    {
        char temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    void FP(string a,int begin)
    {
        if(begin==a.size()-1)
        {
            if(find(res.begin(),res.end(),a)==res.end())
                res.push_back(a);
        }
        else
        {
            for(int i=begin;i<a.size();i++)
            {
                    _swap(a,begin,i);
                    FP(a,begin+1);
                    _swap(a,begin,i);
            }
        }
    }
    int canswap(string a,int k)
    {
        for(int i=0;i<k;i++)
        {
            if(a[i]==a[k])return 0;
        }
        return 1;
    }
    
    
    
//    数组中有一个数字出现的次数超过数组长
//    度的一半，请找出这个数字。例如输入一个长度
//    为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长
//    度的一半，因此输出2。如果不存在则输出0。
    int MoreThanHalfNum_Solution(vector<int> numbers) {
            for(int i=0;i<numbers.size();i++)
                if(count(numbers.begin(),numbers.end(),numbers[i])>numbers.size()/2)
                {
                    return numbers[i];
                }
            return 0;
        }
    /*
    int _hash[10000];
            for(int i=0;i<=numbers.size();i++)
                _hash[i]=0;
            for(int i=0;i<numbers.size();i++)
                _hash[numbers[i]]++;
            for(int i=0;i<numbers.size();i++)
                if(_hash[i]>numbers.size()/2)
                    return i;
            return 0;
    */
    
//    输入n个整数，找出其中最小的K个数。例如
//    输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(),input.end());
        vector<int> res;
        if(k>input.size())return res;
        for(int i=0;i<k;i++)res.push_back(input[i]);
        return res;
    }
    
    
//    HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学
//    。今天测试组开完会后,他又发话了:在古老的一
//    维模式识别中,常常需要计算连续子向量的最大和,
//    当向量全为正数的时候,问题很好解决。但是,如果向
//    量中包含负数,是否应该包含某个负数,并期望旁边的
//正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为
//    8(从第0个开始,到第3个为止)。给一个数组，返回
//    它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
    
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sum=0,max=array[0];
        for(int i=0;i<array.size();i++)
        {
            sum+=array[i];
            if(sum>max)max=sum;
            if(sum<0)sum=0;
        }
        return max;
    }
    
    
    
    
    //--------------------------------------------------------
    bool VerifySquenceOfBST1(vector<int> sequence) {
        int length=0,i=0;
        while(sequence[sequence.size()-1]>sequence[i])
        {
            length++;
            i++;
        }
        for(int j=length;j<sequence.size()-1;j++)
        {
            if(sequence[sequence.size()-1]>sequence[j])return 0;
        }
        int flag1=1,flag2=1;
        if(length>0)
        {
            vector<int> left(sequence.begin(),sequence.begin()+length);
            flag1=VerifySquenceOfBST1(left);
        }
        if(length<sequence.size()-1)
        {
            vector<int> right(sequence.begin()+length,sequence.end()-1);
            flag2=VerifySquenceOfBST1(right);
        }
        return flag1&&flag2;
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        TreeNode *T=build_tree(sequence);
        return isBST(T);
    }
    TreeNode *build_tree(vector<int> a)
    {
        TreeNode *root=new TreeNode(a[a.size()-1]);
        int length=0,i=0;
        while(a[a.size()-1]>a[i])
        {
            length++;
            i++;
        }
        if(length>0)
        {
            vector<int> left(a.begin(),a.begin()+length);
            root->left=build_tree(left);
        }
        if(length<a.size()-1)
        {
            vector<int> right(a.begin()+length,a.end()-1);
            root->right=build_tree(right);
        }
        return root;
    }
    int isBST(TreeNode *T)
    {
        if(!T)return 1;
        int flag1=1,flag2=1;
        if(T->left&&T->left->val>T->val)flag1=0;
        if(T->right&&T->right->val<T->val)flag2=0;
        int flag=flag1&&flag2;
        if(!T->left&&!T->right)return 1;
        else return flag&&isBST(T->left)&&isBST(T->right);
    }
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s1,s2;
        int pointer=0;
        for(int i=popV.size()-1;i>=0;i--)
            s2.push(popV[i]);
        while(pointer<pushV.size())
        {
            s1.push(pushV[pointer]);
            while((!s1.empty()&&!s2.empty())&&(s1.top()==s2.top()))
            {
                if(s1.top()==s2.top())
                {
                    s1.pop();
                    s2.pop();
                }
            }
            pointer++;
        }
        if(!s1.empty()&&!s2.empty())return true;
        else return false;
    }
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root)q.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(!temp->left)q.push(temp->left);
            if(!temp->right)q.push(temp->right);
            res.push_back(temp->val);
        }
        return res;
    }
    
     //--------------------------------------------------------
};

int main(int argc, const char * argv[]) {
    vector<int> a1,a2;
    int b1[]={4,6,12,8,16,14,10};
    int b2[]={4,5,3,2,1};
    for(int i=0;i<7;i++)
        a1.push_back(b1[i]);

//    for(int i=0;i<5;i++)
//        a2.push_back(b2[i]);
    Solution S;
    TreeNode *T=S.build_tree(a1);
    TreeNode *t1=S.Convert(T);
//    cout<<S.IsPopOrder(a1, a2)<<endl;
//    TreeNode *root=new TreeNode(1);
//    root->left=new TreeNode(2);
//    root->right=new TreeNode(3);
//
//    for(int i=0;i<S.PrintFromTopToBottom(root).size();i++)
//        cout<<S.PrintFromTopToBottom(root)[i];
//    bool bol=S.VerifySquenceOfBST(a1);
//    cout<<bol;
    
//    RandomListNode *p=new RandomListNode(1);
//    RandomListNode *h=p;
//    p->next=new RandomListNode(2);
//    p->next->next=new RandomListNode(3);
//    p->next->next->next=new RandomListNode(4);
//    p->next->next->next->next=new RandomListNode(5);
//    p->next->random=p->next->next->next->next;
//    p->next->next->random=p->next->next->next;
//    RandomListNode *cp=S.Clone(h);
    
    return 0;
}


//6-1 Add Two Polynomials (8 分)
//Write a function to add two polynomials. Do not destroy the input. Use a linked list implementation with a dummy head node. Note: The zero polynomial is represented by an empty list with only the dummy head node.
//
//Format of functions:
//
//Polynomial Add( Polynomial a, Polynomial b );
//where Polynomial is defined as the following:
//
//typedef struct Node *PtrToNode;
//struct Node {
//    int Coefficient;
//    int Exponent;
//    PtrToNode Next;
//};
//typedef PtrToNode Polynomial;
///* Nodes are sorted in decreasing order of exponents.*/
//The function Add is supposed to return a polynomial which is the sum of a and b.
//
//
//
//
//Polynomial Add( Polynomial a, Polynomial b )
//{
//    if (!a->Next) { return b; }
//    if (!b->Next) { return a; }
//    Polynomial c=(Polynomial)malloc(sizeof(struct Node));
//    Polynomial temp=c;
//    while(a->Next&&b->Next)
//    {
//
//        if(a->Next->Exponent>b->Next->Exponent)
//        {
//            c->Next=(Polynomial)malloc(sizeof(struct Node));
//            c->Next->Coefficient=a->Next->Coefficient;
//            c->Next->Exponent=a->Next->Exponent;
//            c->Next->Next=NULL;
//            a=a->Next;
//            c=c->Next;
//        }
//        else if(a->Next->Exponent<b->Next->Exponent)
//        {
//            c->Next=(Polynomial)malloc(sizeof(struct Node));
//            c->Next->Coefficient=b->Next->Coefficient;
//            c->Next->Exponent=b->Next->Exponent;
//            c->Next->Next=NULL;
//            b=b->Next;
//            c=c->Next;
//        }
//        else
//        {
//            if(b->Next->Coefficient+a->Next->Coefficient!=0)
//            {
//                c->Next=(Polynomial)malloc(sizeof(struct Node));
//                c->Next->Coefficient=b->Next->Coefficient+a->Next->Coefficient;
//            c->Next->Exponent=b->Next->Exponent;
//            c->Next->Next=NULL;
//            c=c->Next;
//            }
//           b=b->Next;
//            a=a->Next;
//        }
//    }
//    if(a->Next!=NULL)
//    {
//        c->Next=a->Next;
//    }
//    if(b->Next!=NULL)
//    {
//        c->Next=b->Next;
//    }
//return temp;
//}







//6-2 Reverse Linked List (7 分)
//Write a nonrecursive procedure to reverse a singly linked list in O(N) time using constant extra space.
//
//Format of functions:
//
//List Reverse( List L );
//where List is defined as the following:
//
//typedef struct Node *PtrToNode;
//typedef PtrToNode List;
//typedef PtrToNode Position;
//struct Node {
//    ElementType Element;
//    Position Next;
//};
//The function Reverse is supposed to return the reverse linked list of L, with a dummy header.
//
//
//
//List Reverse(List L)
//{
//    if(L->Next==NULL)return L;
//    Position a,b,c;
//    c=NULL;
//    a=L->Next;
//    b=a->Next;
//    L->Next=NULL;
//    while(b)
//    {
//        a->Next=c;
//        c=a;
//        a=b;
//        b=b->Next;
//    }
//    a->Next=c;
//    L->Next=a;
//    return L;
//}


//6-1 Evaluate Postfix Expression (10 分)
//Write a program to evaluate a postfix expression. You only have to handle four kinds of operators: +, -, x, and /.
//
//Format of functions:
//
//ElementType EvalPostfix( char *expr );
//where expr points to a string that stores the postfix expression. It is guaranteed that there is exactly one space between any two operators or operands. The function EvalPostfix is supposed to return the value of the expression. If it is not a legal postfix expression, EvalPostfix must return a special value Infinity which is defined by the judge program.
//
//
//
//ElementType EvalPostfix( char *expr )
//{
//    ElementType number[Max_Expr];//To store the value of each number
//
//    /*
//     i:used to point to the position of input strings
//     j:used to point to value that read from strings,index is behind the last number
//     k:used to point to temp array to store value
//     double_number:used to store the value through operate two number
//     */
//    int i=0,j=0,k=0;
//    ElementType temp_number;
//
//    char temp[Max_Expr];//used to store value and load to number array
//    //Read
//    while(expr[i]!='\0')
//    {
//        while(expr[i]!=' '&&expr[i]!='\0')//blank to split the value and operator
//        {
//            temp[k]=expr[i];
//            i++;
//            k++;
//        }
//
//        temp[k]='\0';//do some follow-up of temp
//        k=0;
//
//        if((temp[0]=='-'&&temp[1]!='\0')||(temp[0]>='0'&&temp[0]<='9'))//get value and load to number[]
//           {
//               if(temp[0]=='-')
//               {
//                   number[j]=-(atof(&temp[1]));
//               }
//               else
//               {
//                   number[j]=atof(temp);
//               }
//               j++;
//           }
//        else if (temp[0]=='+'||temp[0]=='-'||temp[0]=='*'||temp[0]=='/')//do operate
//           {
//               if(j-2<0)return Infinity;
//               switch(temp[0])
//               {
//
//                   case '+':
//                       temp_number=number[j-2]+number[j-1];
//                       number[j-2]=temp_number;
//                       j=j-1;
//                       break;
//                   case '-':
//                       temp_number=number[j-2]-number[j-1];
//                       number[j-2]=temp_number;
//                       j=j-1;
//                       break;
//                   case '*':
//                       temp_number=number[j-2]*number[j-1];
//                       number[j-2]=temp_number;
//                       j=j-1;
//                       break;
//                   case '/':
//                       if(number[j-1]==0)return Infinity;
//                       temp_number=number[j-2]/number[j-1];
//                       number[j-2]=temp_number;
//                       j=j-1;
//                       break;
//                   default:
//                       //do nothing
//                       break;
//               }
//           }
//
//           i++;
//    }
//    if(j>1)return Infinity;
//           return number[j-1];
//
//}
//
//
//
//
//6-2 Two Stacks In One Array (6 分)
//Write routines to implement two stacks using only one array. Your stack routines should not declare an overflow unless every slot in the array is used.
//
//Format of functions:
//
//Stack CreateStack( int MaxElements );
//int IsEmpty( Stack S, int Stacknum );
//int IsFull( Stack S );
//int Push( ElementType X, Stack S, int Stacknum );
//ElementType Top_Pop( Stack S, int Stacknum );
//where int Stacknum is the index of a stack which is either 1 or 2; int MaxElements is the size of the stack array; and Stack is defined as the following:
//
//typedef struct StackRecord *Stack;
//struct StackRecord  {
//    int Capacity;       /* maximum size of the stack array */
//    int Top1;           /* top pointer for Stack 1 */
//    int Top2;           /* top pointer for Stack 2 */
//    ElementType *Array; /* space for the two stacks */
//}
//
//
//
//Stack CreateStack( int MaxElements )
//{
//    Stack sta=(Stack)malloc(sizeof(struct StackRecord));
//    sta->Capacity=MaxElements;
//    sta->Array=(ElementType *)malloc(sizeof(ElementType)*MaxElements);
//    sta->Top1=-1;
//    sta->Top2=MaxElements;
//    return sta;
//}
//int IsEmpty( Stack S, int Stacknum )
//{
//    switch (Stacknum) {
//        case 1:
//            if(S->Top1==-1)return 1;
//            else return 0;
//            break;
//
//        case 2:
//            if(S->Top2==S->Capacity)return 1;
//            else return 0;
//            break;
//    }
//}
//int IsFull( Stack S )
//{
//    if(S->Top1+1>=S->Top2)return 1;
//    else return 0;
//}
//int Push( ElementType X, Stack S, int Stacknum )
//{
//    if(IsFull(S))return 0;
//    switch (Stacknum) {
//        case 1:
//            S->Top1++;
//            S->Array[S->Top1]=X;
//            return 1;
//            break;
//
//        case 2:
//            S->Top2--;
//            S->Array[S->Top2]=X;
//            return 1;
//            break;
//    }
//}
//ElementType Top_Pop( Stack S, int Stacknum )
//{
//    if(IsEmpty(S,Stacknum))return ERROR;
//    switch (Stacknum) {
//        case 1:
//
//            return S->Array[S->Top1--];
//            break;
//
//        case 2:
//
//            return S->Array[S->Top2++];
//            break;
//    }
//}
//
//
//
//6-3 Deque (10 分)
//A "deque" is a data structure consisting of a list of items, on which the following operations are possible:
//
//Push(X,D): Insert item X on the front end of deque D.
//Pop(D): Remove the front item from deque D and return it.
//Inject(X,D): Insert item X on the rear end of deque D.
//Eject(D): Remove the rear item from deque D and return it. Write routines to support the deque that take O(1) time per operation.
//Format of functions:
//
//Deque CreateDeque();
//int Push( ElementType X, Deque D );
//ElementType Pop( Deque D );
//int Inject( ElementType X, Deque D );
//ElementType Eject( Deque D );
//where Deque is defined as the following:
//
//typedef struct Node *PtrToNode;
//struct Node {
//    ElementType Element;
//    PtrToNode Next, Last;
//};
//typedef struct DequeRecord *Deque;
//struct DequeRecord {
//    PtrToNode Front, Rear;
//};
//Here the deque is implemented by a doubly linked list with a header.  Front and Rear point to the two ends of the deque respectively.  Front always points to the header. The deque is empty when Front and Rear both point to the same dummy header. Note: Push and Inject are supposed to return 1 if the operations can be done successfully, or 0 if fail. If the deque is empty, Pop and Eject must return ERROR which is defined by the judge program.
//
//
//Deque CreateDeque()
//{
//    Deque D=(Deque)malloc(sizeof(struct DequeRecord));
//    D->Front=(PtrToNode)malloc(sizeof(struct Node));
//    D->Front->Last=NULL;
//    D->Rear=D->Front;
//    D->Rear->Next=NULL;
//    return D;
//}
//
//int Push( ElementType X, Deque D )
//{
//    PtrToNode temp=(PtrToNode)malloc(sizeof(struct Node));
//    temp->Element=X;
//    if(temp==NULL)return 0;
//    if(D->Front!=D->Rear)
//    {
//        temp->Next=D->Front->Next;
//        D->Front->Next=temp;
//        temp->Last=D->Front;
//        temp->Next->Last=temp;
//        return 1;
//    }
//    else
//    {
//        D->Front->Next=temp;
//        temp->Last=D->Front;
//        D->Rear=temp;
//        D->Rear->Next=NULL;
//        return 1;
//    }
//
//}
//
//
//ElementType Pop( Deque D )
//{
//    ElementType temp;
//    if(D->Front==D->Rear)return ERROR;
//    temp=D->Front->Next->Element;
//    if(D->Front->Next==D->Rear)
//    {
//        D->Rear=D->Front;
//        D->Front->Next=NULL;
//        return temp;
//    }
//    D->Front->Next->Next->Last=D->Front;
//    D->Front->Next=D->Front->Next->Next;
//    return temp;
//
//}
//
//
//int Inject( ElementType X, Deque D )
//{
//    PtrToNode temp=(PtrToNode)malloc(sizeof(struct Node));
//    temp->Element=X;
//    if(temp==NULL)return 0;
//
//        D->Rear->Next=temp;
//        temp->Last=D->Rear;
//        D->Rear=temp;
//        D->Rear->Next=NULL;
//        return 1;
//
//}
//
//
//ElementType Eject( Deque D )
//{
//    if(D->Front==D->Rear)return ERROR;
//    ElementType temp=D->Rear->Element;
//    D->Rear=D->Rear->Last;
//    D->Rear->Next=NULL;
//    return temp;
//}
//
//
//
//7-1 Pop Sequence (10 分)
//Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.
//
//
//
//
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct Node *Stack;//建立栈，数组实现
//struct Node
//{
//    int stack_point;//从1开始存放值,0代表栈中不存在元素
//    int max;//栈的实际容量
//    int stack_array[2000];//开辟空间保证大小
//};
//
//int push(Stack S,int num);//将num压入栈顶，若栈满，则返回0，若压入成功，则返回1
//int pop(Stack S);//弹出栈顶元素，若成功则返回弹出值，若失败则返回0
//
//int main()
//{
//    Stack S=(Stack)malloc(sizeof(struct Node));
//    int M,N,K;
//    scanf("%d %d %d",&M,&N,&K);
//    S->max=M;
//
//    int input_value[K][N],i,j;//存放输入数据
//    for(i=0;i<K;i++)
//        for(j=0;j<N;j++)
//            scanf("%d",&input_value[i][j]);
//
//
//    for(i=0;i<K;i++)
//    {
//        S->stack_point=0;
//        int number = 1;
//        int right=1;
//        for(j=0;j<N;j++)
//        {
//            while(number<=(input_value[i][j])&&right==1)
//            {
//                right=push(S,number);
//                number++;
//            }
//            if(pop(S)!=input_value[i][j])right=0;
//        }
//        if(right==1)printf("YES\n");
//        else printf("NO\n");
//    }
//    return 0;
//}
//
//int push(Stack S ,int num)
//{
//    if(S->stack_point<S->max)
//    {
//        S->stack_point++;
//        S->stack_array[S->stack_point]=num;
//        return 1;
//    }
//    else return 0;
//}
//
//int pop(Stack S)
//{
//    if(S->stack_point==0)return 0;
//    else
//    {
//        int temp=S->stack_array[S->stack_point];
//        S->stack_point--;
//        return temp;
//    }
//}
//
//
//
//6-2 Isomorphic (7 分)
//Two trees, T1 and T2, are isomorphic if T1 can be transformed into T2 by swapping left and right children of (some of the) nodes in T1. For instance, the two trees in Figure 1 are isomorphic because they are the same if the children of A, B, and G, but not the other nodes, are swapped. Give a polynomial time algorithm to decide if two trees are isomorphic.
//
//
//int Isomorphic(Tree T1,Tree T2)
//{
//    if(T1!=NULL && T2 !=NULL)
//    {
//        if(T1->Element!=T2->Element)return 0;
//
//        int flag;
//        flag=(Isomorphic(T1->Left,T2->Left)&&Isomorphic(T1->Right,T2->Right))||(Isomorphic(T1->Left,T2->Right)&&Isomorphic(T1->Right,T2->Left));
//    }
//    else if (T1==NULL && T2==NULL)
//    {
//        return 1;
//    }
//    else
//    {
//        return 0;
//    }
//}
//
//
//7-1 Tree Traversals Again
//
//#include <stdio.h>
//
//int pre_order_stack[100],in_order_stack[100],post_order_stack[100],stack[100];
//int pre_stackpointer,in_stackpointer,post_stackpointer,stackpointer;
//
//void get_input(int N);
//void get_post_order_stack(int pre,int _in,int post,int length);
//
//
//int main() {
//    int N,flag=1;
//    scanf("%d",&N);
//    get_input(N);
//    get_post_order_stack(0, 0, 0, N);
//    for(int i=0;i<N;i++)
//    {
//        if(flag==1)
//        {
//            printf("%d",post_order_stack[i]);
//            flag=0;
//        }
//        else
//        printf(" %d",post_order_stack[i]);
//    }
//    return 0;
//}
//
//void get_input(int N)
//{
//    char words[5];
//    int number,i=0;
//    while(i<2*N)
//    {
//        scanf("%s",words);
//        if(words[2]=='s')
//        {
//            scanf("%d",&number);
//            pre_order_stack[pre_stackpointer++]=number;
//            stack[stackpointer++]=number;
//        }
//        else
//        {
//            in_order_stack[in_stackpointer++]=stack[--stackpointer];
//        }
//        i++;
//    }
//}
//
//void get_post_order_stack(int pre,int _in,int post,int length)
//{
//    int temp=pre_order_stack[pre],i=0;
//    if(length==0)return;
//    if(length==1)
//    {
//        post_order_stack[post]=temp;
//        return;
//    }
//    post_order_stack[post+length-1]=temp;
//    while(i<length)
//    {
//        if(in_order_stack[_in+i]==temp)break;
//        i++;
//    }
//    get_post_order_stack(pre+1,_in, post, i);
//    get_post_order_stack(pre+i+1, _in+i+1, post+i, length-i-1);
//}
//
//
//
//7-3 ZigZagging on a Tree
//
//#include <stdio.h>
//int in_order[100],post_order[100],tree[100][100],level_stackpointer[100];
//
//void get_input(int N);
//void build_tree(int inorder_left,int inorder_right,int post_last,int level);
//void print_tree();
//int main() {
//    int N;
//    scanf("%d",&N);
//    get_input(N);
//    build_tree(0,N-1,N-1,0);
//    print_tree();
//    return 0;
//}
//
//void get_input(int N)
//{
//    for(int i=0;i<N;i++)scanf("%d",&in_order[i]);
//    for(int i=0;i<N;i++)scanf("%d",&post_order[i]);
//}
//
//void build_tree(int inorder_left,int inorder_right,int post_last,int level)
//{
//    if(inorder_left>inorder_right)return;
//    int index=inorder_left;
//    while(post_order[post_last]!=in_order[index])index++;
//    tree[level][level_stackpointer[level]++]=in_order[index];
//    build_tree(inorder_left, index-1, post_last-1+index-inorder_right, level+1);
//    build_tree(index+1, inorder_right, post_last-1, level+1);
//}
//
//void print_tree()
//{
//    int max=0,i;
//    while(tree[max][0]!=0)max++;
//    printf("%d",tree[0][0]);
//    for(i=1;i<max;i++)
//    {
//        if(i%2==1)//--->
//        {
//            for(int j=0;j<level_stackpointer[i];j++)
//            {
//                printf(" %d",tree[i][j]);
//            }
//        }
//        else    //<---
//        {
//            for(int j=level_stackpointer[i]-1;j>=0;j--)
//            {
//                printf(" %d",tree[i][j]);
//            }
//        }
//    }
//}
//
//
//6-1 CheckBST[1] (13 分)
//Given a binary tree, you are supposed to tell if it is a binary search tree. If the answer is yes, try to find the K-th largest key, else try to find the height of the tree.
//
//int height(BinTree T)
//{
//    if(T==NULL)return 0;
//    int leftheight=height(T->Left);
//    int rightheight=height(T->Right);
//    return leftheight>rightheight?leftheight+1:rightheight+1;
//}
//
//int CheckBST(BinTree T,int K)
//{
//    int h=height(T);
//    int array[100]={0};
//    int array_pointer=0;
//    BinTree stack[100]={NULL};
//    int stackpointer=0;
//    while(T!=NULL || stackpointer!=0)
//    {
//        while(T!=NULL)
//        {
//            stack[stackpointer++]=T;
//            T=T->Left;
//        }
//        if(stackpointer!=0)
//        {
//            T=stack[--stackpointer];
//            array[array_pointer++]=T->Key;
//            T=T->Right;
//        }
//    }
//    for(int i=0;i<array_pointer-1;i++)
//    {
//        if(array[i+1]<array[i])
//        {
//            return -h;
//        }
//    }
//    return array[array_pointer-K];
//}
//
//7-1 Binary Search Tree
//
//#include <stdio.h>
//
//typedef struct Node *BinTree;
//struct Node
//{
//    int key;
//    BinTree left;
//    BinTree right;
//};
//int pre_order_stack[100];
//int pre_order_stackpointer;
//
//void pre_order(BinTree T);
//int isequal(BinTree T1,BinTree T2);
//BinTree insert(BinTree T,int key);
//BinTree creatTree(int temp[],int N);
//
//int main(int argc, const char * argv[]) {
//    int N,L;
//    while(1)
//    {
//        scanf("%d",&N);
//        if(N==0)break;
//        scanf("%d",&L);
//        int temp[N];
//        for(int i=0;i<N;i++)
//        {
//            scanf("%d",&temp[i]);
//        }
//        BinTree T=creatTree(temp, N);
//        for(int j=0;j<L;j++)
//        {
//            int temp[N];
//            for(int i=0;i<N;i++)
//            {
//                scanf("%d",&temp[i]);
//            }
//            BinTree T1=creatTree(temp, N);
//            if(isequal(T, T1))
//            {
//                printf("Yes\n");
//            }
//            else
//            {
//                printf("No\n");
//            }
//        }
//    }
//
//    return 0;
//}
//
//BinTree creatTree(int key[],int N)
//{
//    BinTree root=NULL;
//    for(int i=0;i<N;i++)
//    {
//        root=insert(root, key[i]);
//    }
//    return root;
//}
//
//BinTree insert(BinTree T,int k)
//{
//    if(T==NULL)
//    {
//        BinTree tempnode=(BinTree)malloc(sizeof(struct Node));
//        tempnode->key=k;
//        tempnode->left=tempnode->right=NULL;
//        T=tempnode;
//        return T;
//    }
//    else if (k<T->key)
//    {
//        T->left=insert(T->left, k);
//    }
//    else
//    {
//        T->right=insert(T->right, k);
//    }
//    return T;
//}
//
//
//void pre_order(BinTree T)
//{
//    if(T==NULL)return;
//    pre_order_stack[pre_order_stackpointer++]=T->key;
//    pre_order(T->left);
//    pre_order(T->right);
//
//}
//
//int isequal(BinTree T1,BinTree T2)
//{
//    int temp1[100]={0},temp2[100]={0};
//    pre_order_stackpointer=0;
//    pre_order(T1);
//    for(int i=0;i<pre_order_stackpointer;i++)
//    {
//        temp1[i]=pre_order_stack[i];
//    }
//    pre_order_stackpointer=0;
//    pre_order(T2);
//    for(int i=0;i<pre_order_stackpointer;i++)
//    {
//        temp2[i]=pre_order_stack[i];
//    }
//    int length=pre_order_stackpointer;
//    for(int i=0;i<length;i++)
//    {
//        if(temp1[i]!=temp2[i])
//            return 0;
//    }
//    return 1;
//}
//
//
//6-1 Percolate Up and Down (7 分)
//Write the routines to do a "percolate up" and a "percolate down" in a binary min-heap.
//
//Format of functions:
//
//void PercolateUp( int p, PriorityQueue H );
//void PercolateDown( int p, PriorityQueue H );
//where int p is the position of the element, and PriorityQueue is defined as the following:
//
//typedef struct HeapStruct *PriorityQueue;
//struct HeapStruct {
//    ElementType  *Elements;
//    int Capacity;
//    int Size;
//};
//
//void PercolateUp( int p, PriorityQueue H )
//{
//    while(p)
//    {
//        if(p/2!=0&&H->Elements[p]<H->Elements[p/2])
//        {
//            int temp=H->Elements[p/2];
//            H->Elements[p/2]=H->Elements[p];
//            H->Elements[p]=temp;
//            p/=2;
//        }
//        else break;
//    }
//}
//void PercolateDown( int p, PriorityQueue H )
//{
//    while(1)
//    {
//        int left=p*2,right=left+1,min=p;
//        if(left>H->Size&&right>H->Size)break;
//        if(left<=H->Size && H->Elements[left]<H->Elements[min])
//        {
//            min=left;
//        }
//        if(right<=H->Size && H->Elements[min]>H->Elements[right])
//        {
//            min=right;
//        }
//        if(min!=p)
//        {
//            int temp=H->Elements[p];
//            H->Elements[p]=H->Elements[min];
//            H->Elements[min]=temp;
//            p=min;
//        }
//        else break;
//    }
//}
//
//7-1 Complete Binary Search Tree
//
//#include<stdio.h>
//
//int in_order[2000];
//int in_order_pointer;
//int CBST[2000];
//
//void sort_array(int N);
//void build_tree(int root,int N);
//void print_reuslt(int N);
//
//int main()
//{
//    int N;
//    scanf("%d",&N);
//    for(int i=0;i<N;i++)scanf("%d",&in_order[i]);
//
//    sort_array(N);
//    build_tree(1,N);
//    print_reuslt(N);
//
//    return 0;
//}
//
//void sort_array(int N)
//{
//    for(int i=0;i<N;i++)
//        for(int j=i+1;j<N;j++)
//        {
//            if(in_order[i]>in_order[j])
//            {
//                int temp=in_order[i];
//                in_order[i]=in_order[j];
//                in_order[j]=temp;
//            }
//        }
//}
//
//void build_tree(int root,int N)
//{
//    if(root>N)return;
//    build_tree(2*root,N);
//    CBST[root]=in_order[in_order_pointer++];
//    build_tree(2*root+1,N);
//}
//void print_reuslt(int N)
//{
//    for(int i=1;i<=N;i++)
//    {
//        if(i==1)printf("%d",CBST[i]);
//        else
//        {
//            printf(" %d",CBST[i]);
//        }
//    }
//}
//
//7-1 File Transfer
//
//#include<stdio.h>
//
//int tree[100000],height[100000];
//int i,j;
//
//void init_tree(int N);
//int find(int a);
//void tree_union(int a,int b);
//int find_classes();
//
//int main()
//{
//    int N,a,b;
//    char c;
//    scanf("%d",&N);
//    init_tree(N);
//
//    c=getchar();
//    c=getchar();
//    while(c!='S')
//    {
//        scanf("%d %d",&a,&b);
//        if(c=='I')
//        {
//            tree_union(a,b);
//            N--;
//        }
//        else
//        {
//            if(find(a)==find(b))printf("yes\n");
//            else printf("no\n");
//        }
//        c=getchar();
//        c=getchar();
//    }
//    //int temp=find_classes();
//    if(N==1)printf("The network is connected.");
//    else printf("There are %d components.",N);
//
//    return 0;
//}
//
//void init_tree(int N)
//{
//    for( i=1;i<=N;i++)
//    {
//        tree[i]=i;
//        height[i]=1;
//    }
//
//}
//
//int find(int a)
//{
//    while(a!=tree[a])
//    {
//        if(tree[a]==0)return 0;
//        a=tree[a];
//    }
//    return a;
//}
//
//void tree_union(int a,int b)
//{
//    int root1=find(a);
//    int root2=find(b);
//    if(root1==root2)return;
//    else
//    {
//        if(height[root1]>height[root2])
//        {
//            tree[root2]=root1;
//        }
//        else
//        {
//            if(height[root1]==height[root2]) height[root2]++;
//            tree[root1]=root2;
//        }
//    }
//    return;
//}
//
//int find_classes()
//{
//    int temp[100000]={0};
//    for( i=1;tree[i]!=0;i++)
//    {
//        temp[i]=tree[i];
//    }
//    int count=0;
//    for( i=1;tree[i]!=0;i++)
//    {
//        for( j=i+1;tree[j]!=0;j++)
//        {
//            if(find(temp[j])==find(temp[i]))
//                temp[j]=0;
//        }
//    }
//    for( i=1;tree[i]!=0;i++)
//    {
//        if(temp[i]!=0)count++;
//    }
//    return count;
//}
//
//6-1 Is Topological Order
//
//bool IsTopSeq( LGraph Graph, Vertex Seq[] )
//{
//    int in_degree[10000]={0};
//    int pointer=0;
//
//    for (int i = 0; i<Graph->Nv; i++)
//    {
//        PtrToAdjVNode temp = Graph->G[i].FirstEdge;
//        while (temp)
//        {
//            in_degree[temp->AdjV]++;
//            temp = temp->Next;
//        }
//    }
//    while(pointer<Graph->Nv)
//    {
//        Seq[pointer]=Seq[pointer]-1;
//        pointer++;
//    }
//    pointer=0;
//    while(pointer<Graph->Nv)
//    {
//        int value=Seq[pointer];
//        if(in_degree[value]!=0)return false;
//        PtrToAdjVNode temp = Graph->G[value].FirstEdge;
//        while (temp)
//        {
//            in_degree[temp->AdjV]--;
//            if (in_degree[temp->AdjV]<0) return false;
//            temp = temp->Next;
//        }
//        pointer++;
//    }
//    return true;
//}
//
//6-1 Shortest Path [3] (8 分)
//Write a program to not only find the weighted shortest distances, but also count the number of different minimum paths from any vertex to a given source vertex in a digraph. It is guaranteed that all the weights are positive.
//
//Format of functions:
//
//void ShortestDist( MGraph Graph, int dist[], int count[], Vertex S );
//where MGraph is defined as the following:
//
//typedef struct GNode *PtrToGNode;
//struct GNode{
//    int Nv;
//    int Ne;
//    WeightType G[MaxVertexNum][MaxVertexNum];
//};
//typedef PtrToGNode MGraph;
//
//void ShortestDist( MGraph Graph, int dist[], int count[], Vertex S )
//{
//    bool isvisit[MaxVertexNum]={false};
//    dist[S]=0;
//    count[S]=1;
//    for(Vertex i=0;i<Graph->Nv;i++)
//    {
//        if(i!=S)
//        {
//            dist[i]=Graph->G[S][i];
//            count[i]=0;
//        }
//
//    }
//
//    //find shortest distance
//    while(1)
//    {
//        Vertex min=INFINITY;
//        Vertex v=-1;
//        for(Vertex i=0;i<Graph->Nv;i++)
//            if(isvisit[i]==false)
//                if(dist[i]<min)
//                {
//                    min=dist[i];
//                    v=i;
//                }
//
//
//        if(v==-1)break;
//        isvisit[v]=true;
//
//        for(Vertex i=0;i<Graph->Nv;i++)
//        {
//            if(Graph->G[v][i]!=INFINITY)
//            {
//                if(dist[i] > Graph->G[v][i] + dist[v])
//                {
//                    dist[i]=Graph->G[v][i]+dist[v];
//                    count[i]=count[v];
//                }
//                else if(dist[i]==Graph->G[v][i] + dist[v])
//                    count[i]+=count[v];
//            }
//        }
//    }
//    for(Vertex i=0;i<Graph->Nv;i++)
//        if(dist[i]==INFINITY)
//        {
//            dist[i]=-1;
//            count[i]=0;
//        }
//    //bool visit[MaxVertexNum]={false};
//
//
//    /*
//    //数组模拟队列，BST方法遍历图找出不连通点
//    int queue1[MaxVertexNum]={-1};
//    int tail=-1,front=-1;
//    int temp=S;
//
//    queue1[++tail]=S;
//    while(tail!=front)
//    {
//        temp=queue1[++front];
//        for(int i=0;i<Graph->Nv;i++)
//        {
//            if(visit[i]!=true && Graph->G[temp][i]!=INFINITY)
//            {
//                visit[i]=true;
//                queue1[++tail]=i;
//            }
//        }
//    }
//
//    //BST遍历完之后尚未访问的点即为与S无路径的点
//    for(int i=0;i<Graph->Nv;i++)
//    {
//        if(visit[i]==false)
//        {
//            dist[i]=-1;
//            count[i]=0;
//        }
//    } I
//    */
//}
//
//6-2 Shortest Path [4] (8 分)
//Write a program to find the weighted shortest distances from any vertex to a given source vertex in a digraph. If there is more than one minimum path from v to w, a path with the fewest number of edges is chosen. It is guaranteed that all the weights are positive and such a path is unique for any vertex.
//
//Format of functions:
//
//void ShortestDist( MGraph Graph, int dist[], int path[], Vertex S );
//where MGraph is defined as the following:
//
//typedef struct GNode *PtrToGNode;
//struct GNode{
//    int Nv;
//    int Ne;
//    WeightType G[MaxVertexNum][MaxVertexNum];
//};
//typedef PtrToGNode MGraph;
//
//void ShortestDist( MGraph Graph, int dist[], int path[], Vertex S )
//{
//    bool isvisit[MaxVertexNum]={false};
//    dist[S]=0;
//    path[S]=-1;
//    int path_length[MaxVertexNum]={0};
//    for(Vertex i=0;i<Graph->Nv;i++)
//    {
//        if(i!=S)
//        {
//            dist[i]=Graph->G[S][i];
//            path[i]=S;
//        }
//
//    }
//
//    //find shortest distance
//    while(1)
//    {
//        Vertex min=INFINITY;
//        Vertex v=-1;
//        for(Vertex i=0;i<Graph->Nv;i++)
//            if(isvisit[i]==false)
//                if(dist[i]<min)
//                {
//                    min=dist[i];
//                    v=i;
//                }
//
//
//        if(v==-1)break;
//        isvisit[v]=true;
//
//        for(Vertex i=0;i<Graph->Nv;i++)
//        {
//            if(Graph->G[v][i]!=INFINITY)
//            {
//                if(dist[i] > Graph->G[v][i] + dist[v])
//                {
//                    dist[i]=Graph->G[v][i]+dist[v];
//                    path[i]=v;
//                    path_length[i]=path_length[v]+1;
//                }
//                else if(dist[i]==Graph->G[v][i] + dist[v])
//                {
//                    if(path_length[i]>path_length[v]+1)
//                    {
//                        path[i]=v;
//                        path_length[i]=path_length[v]+1;
//                    }
//                }
//
//            }
//        }
//    }
//    for(Vertex i=0;i<Graph->Nv;i++)
//        if(dist[i]==INFINITY)
//        {
//            dist[i]=-1;
//            path[i]=-1;
//        }
//}
//
//
//7-1 Universal Travel Sites
//
//
////
////  main.c
////  flow
////
////  Created by 吴杰 on 2019/11/29.
////  Copyright © 2019 吴杰. All rights reserved.
////
//
//#include <stdio.h>
//#include<string.h>
//#include <math.h>
//#define max 10000
//#define INF 2e9
//struct node
//{
//    int c;
//    int f;
//}edge[max][max];
//
//int visit[max],pre[max],min[max],queue[max],v,st,en,h,t,n,m,hash[max];
//
//void bfs();
//void Ford_F();
//void max_flow();
//int _min(int a,int b);
//int _abs(int a);
//void input();
//int _hash(char a[]);
//
//
//int main(int argc, const char * argv[]) {
//
//    input();
//    st=1;en=2;
//    Ford_F();
//    max_flow();
//    return 0;
//}
//
//void input()
//{
//    char temp1[4],temp2[4];
//    scanf("%s%s%d",temp1+1,temp2+1,&m);
//    st=_hash(temp1);
//    en=_hash(temp2);
//    hash[++n]=st;
//    hash[++n]=en;
//
//
//    for(int i=0;i<m;i++)
//    {
//        int t1,t2,t3;
//        int indexi,indexj;
//        scanf("%s %s %d",temp1+1,temp2+1,&t3);
//        t1=_hash(temp1);
//        t2=_hash(temp2);
//        int flag=1;
//        for(int i=1;i<=n;i++)
//        {
//            if(hash[i]==t1)
//            {
//                flag=0;
//                indexi=i;
//                break;
//            }
//        }
//        if(flag)
//        {
//            hash[++n]=t1;
//            indexi=n;
//        }
//        flag=1;
//        for(int i=1;i<=n;i++)
//        {
//            if(hash[i]==t2)
//            {
//                flag=0;
//                indexj=i;
//                break;
//            }
//        }
//        if(flag)
//        {
//            hash[++n]=t2;
//            indexj=n;
//        }
//
//
//
//        edge[indexi][indexj].c=t3;
//
//    }
//
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=n;j++)
//        {
//            if(edge[i][j].c==0)edge[i][j].c=INF;
//        }
//
//
//
//}
//
//int _hash(char a[])
//{
//    int a1,a2,a3;
//    a1=26*26*(a[1]-'A');
//    a2=26*(a[2]-'A');
//    a3=(a[3]-'A');
//    return a1+a2+a3;
//}
//
//void bfs()
//{
//    memset(visit,-1,sizeof(visit));
//    memset(pre,-1,sizeof(pre));
//    memset(min,-1,sizeof(min));
//    visit[st]=0;
//    pre[st]=0;
//    min[st]=INF;
//    h=0;
//    t=1;
//    queue[t]=st;
//    while (h<t) {
//        h++;
//        v=queue[h];
//        for(int i=1;i<=n;i++)
//        {
//            if(visit[i]==-1)
//            {
//                if(edge[v][i].c<INF && edge[v][i].f<edge[v][i].c)
//                {
//                    visit[i]=0;
//                    pre[i]=v;
//                    min[i]=_min(min[v],edge[v][i].c-edge[v][i].f);
//                    queue[++t]=i;
//                }
//                else if(edge[i][v].c<INF && edge[i][v].f>0)
//                {
//                    visit[i]=0;
//                    pre[i]=-v;
//                    min[i]=_min(min[v],edge[i][v].f);
//                    queue[++t]=i;
//                }
//            }
//        }
//        visit[v]=0;
//    }
//
//}
//
//void Ford_F()
//{
//    while(1){
//        bfs();
//        if(min[en]==0||visit[en]==-1)
//        {
//            break;
//        }
//        int k1=en,k2=_abs(pre[k1]);
//        int a=min[en];
//        while(1){
//            if(edge[k2][k1].c<INF) edge[k2][k1].f+=a;
//            else if(edge[k1][k2].c<INF) edge[k1][k2].f-=a;
//            if(k2==st) break;
//            k1=k2;k2=_abs(pre[k1]);
//        }
//        min[en]=0;
//    }
//}
//
//void max_flow()
//{
//    int maxflow=0;
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=n;j++){
//        if(i==st&&edge[i][j].f<INF) maxflow+=edge[i][j].f;
//        }
//       printf("%d",maxflow);
//}
//int _abs(int a)
//{
//    if(a<0)a=-a;
//    return a;
//}
//
//int _min(int a,int b)
//{
//    if(a>b)return b;
//    else return a;
//}
//

