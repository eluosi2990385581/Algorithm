#include "RedBlackTree.h"
void test1();
void test2();


int main (int argc, char *argv[])
{
    test1();
    test2();
    return 0;
};


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
