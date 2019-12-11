#include "RedBlackTree.h"
void test1();
void test2();
void test_interval_search_tree1();
void test_interval_search_tree2();


int main (int argc, char *argv[])
{
//    test1();
//    test2();
    test_interval_search_tree2();
    
    return 0;
};

void test_interval_search_tree1()
{
    int a[][2]={{1,2},{3,4},{6,7},{8,9},{10,14}};
    RedBlackTree<int> A;
    for(int i=0;i<5;i++)
    {
        BinaryTreeNode<int> *t=new BinaryTreeNode<int>(a[i][0],a[i][1]);
        A.insert(t);
    }
    A.display();
    BinaryTreeNode<int> *temp=new BinaryTreeNode<int>(3,5);
    BinaryTreeNode<int> *res=A.IntervalTreeSearch(temp);
    std::cout<<res->low<<" ";
    std::cout<<res->high<<std::endl;
    
}
void test_interval_search_tree2()
{
    std::cout<<"Input format:"<<std::endl;
    std::cout<<"The first line includes three numbers:n low high.n is the interval tree node you need input,low and high are interval which we want to find if there is a node overlap with it.Followed by n lines,each line include two numbers which are the interval's endpoints"<<std::endl;
    std::cout<<"Output format:"<<std::endl;
    std::cout<<"Output a interval tree first(based on RBT),then output the interval we find or if we can't find it,output 'None'"<<std::endl;
    std::cout<<"Example:"<<std::endl<<"Input:"<<std::endl;
    std::cout<<"5 3 5"<<std::endl;
    std::cout<<"1 2"<<std::endl;
    std::cout<<"3 4"<<std::endl;
    std::cout<<"6 7"<<std::endl;
    std::cout<<"8 9"<<std::endl;
    std::cout<<"10 14"<<std::endl;
    std::cout<<"Output:"<<std::endl<<std::endl;
    test_interval_search_tree1();
    
    std::cout<<"Now it's your show time:"<<std::endl;
    
    int n,l,h,temp1,temp2;
    std::vector<std::vector<int> > a;
    std::vector<int> a1;
    std::cin>>n>>l>>h;
    for(int i=0;i<n;i++)
    {
        std::cin>>temp1>>temp2;
        a1.push_back(temp1);
        a1.push_back(temp2);
        a.push_back(a1);
        a1.clear();
    }
    RedBlackTree<int> A;
    for(int i=0;i<a.size();i++)
    {
        BinaryTreeNode<int> *t=new BinaryTreeNode<int>(a[i][0],a[i][1]);
        A.insert(t);
    }
    A.display();
    BinaryTreeNode<int> *temp=new BinaryTreeNode<int>(l,h);
    BinaryTreeNode<int> *res=A.IntervalTreeSearch(temp);
//    if(!(res==NULL||res->flag==0))
//    {
//        std::cout<<res->low<<" ";
//        std::cout<<res->high<<std::endl;
//    }
//    else
//        std::cout<<"None"<<std::endl;
    if(res && (res->low||res->low)){
        std::cout<<res->low<<" ";
        std::cout<<res->high<<std::endl;
    }
    else
        std::cout<<"None"<<std::endl;
    
    
    
}


void test1()
{
    BinaryTree<int> A(1);
    BinaryTree<int> B(3);
    B.insertLeft(B.getRoot(), 1);
    B.insertRight(B.getRoot(), 2);
    std::cout << "Height of B: " << B.height() << std::endl;
    B.display();
    BinaryTree<int>::Node *t = B.getRoot();
    t = t->left;
    t->color = BLACK;
    B.transplant(B.getRoot(), t);
    B.display();
}
void test2()
{
    RedBlackTree<int> B(1);
    B.display();
    B.insert(2);
    B.display();
    B.insert(3);
    B.display();
    B.insert(4);
    B.display();
    B.insert(5);
    B.display();
}
