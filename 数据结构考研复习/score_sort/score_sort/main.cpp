#include<iostream>
#include<string.h>
using namespace std;
char name[50][50];
int score[50];
void input(int N);
void increase(int N);
void decrease(int N);
void print(int N);
void swap(char *x, char *y);
int main()
{
    int N,M;
    cin>>N>>M;
    input(N);
    switch(M)
    {
        case 0:
            decrease(N);
            break;
        case 1:
            increase(N);
            break;
    }
    print(N);
    return 0;
}

void input(int N)
{
    for(int i=0;i<N;i++)
    {
        cin>>name[i]>>score[i];
    }
}

//void decrease(int N)
//{
//    for(int i=0;i<N;i++)
//    {
//        for(int j=i+1;j<N;j++)
//        {
//            if(score[i]<score[j])
//            {
//                int temp=score[i];
//                score[i]=score[j];
//                score[j]=temp;
//
//                swap(name[i],name[j]);
//            }
//        }
//    }
//}

void decrease(int N)
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N-i-1;j++)
        {
            if(score[j]<score[j+1])
            {
                int temp=score[j];
                score[j]=score[j+1];
                score[j+1]=temp;
                
                swap(name[j],name[j+1]);
            }
        }
}

//void increase(int N)
//{
//    for(int i=0;i<N;i++)
//    {
//        for(int j=i+1;j<N;j++)
//        {
//            if(score[i]>score[j])
//            {
//                int temp=score[i];
//                score[i]=score[j];
//                score[j]=temp;
//
//                swap(name[i],name[j]);
//            }
//        }
//    }
//}

void increase(int N)
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N-i-1;j++)
        {
            if(score[j]>score[j+1])
            {
                int temp=score[j];
                score[j]=score[j+1];
                score[j+1]=temp;
                
                swap(name[j],name[j+1]);
            }
        }
}

void print(int N)
{
    for(int i=0;i<N;i++)
    {
        cout<<name[i]<<" "<<score[i]<<endl;
    }
}

void swap(char *x, char *y)
{
    int L,i;
    char c;
    L = strlen(x);
    if (strlen(y) > L) L = strlen(y);
        for (i=0;i<L;i++){ c=x[i];x[i]=y[i];y[i]=c;};
}
