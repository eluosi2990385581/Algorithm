#ifndef __QUICKSORT__
#define __QUICKSORT__

#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>
void quicksort(std::vector<int> &A,int p,int q);

int partition(std::vector<int> &A,int p,int q);

void generate_array(int N,std::vector<int> &A);
void test();

#else
//do nothing

#endif
