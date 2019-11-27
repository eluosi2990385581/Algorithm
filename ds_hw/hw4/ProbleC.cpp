#include<iostream>
#include<vector>
using namespace std;

#define Maxnum 301;
int hash_arr[Maxnum];//这里键为0～Maxnum，值为开始输入的数值

void init_arr(int p);
int hash_collsion(int p,int n);

int main()
{
    
    int p,n;
    cin>>p>>n;
    init_arr(p);
    cout<<hash_collsion(p,n)<<endl;
    
    return 0;
}

void init_arr(int p)
{
    for(int i=0;i<p;i++)
        hash_arr[i]=-1;
}

int hash_collsion(int p,int n)
{
    long num,fnum;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        fnum=num%p;
        if(hash_arr[fnum]>=0)return i;
        hash_arr[fnum]=1;
    }
    return -1;
}
