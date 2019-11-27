#include<iostream>
#include<vector>
using namespace std;

#define Maxnum 100000
int hash_arr[Maxnum];//这里键为0～Maxnum，值为开始输入的数值

void init_arr(int h);
int hash_collsion(int h,int m,int n);

int main()
{
    
    int h,m,n;
    cin>>h>>m>>n;
    init_arr(h);
    cout<<hash_collsion(h,m,n)<<endl;
    
    return 0;
}

void init_arr(int h)
{
    for(int i=0;i<h;i++)
        hash_arr[i]=-1;
}

int hash_collsion(int h,int m,int n)
{
    char str;
    int k,fk,i;
    int count=0;
    for(int j=0;j<n;j++)
    {
        cin>>str;
        switch (str) {
            case '+':
                cin>>k>>fk;
                if(hash_arr[fk]<0)
                {
                    hash_arr[fk]=k;
                }
                else
                {
                    while(hash_arr[fk]>=0)
                    {
                        count++;
                        fk=(fk+m)%h;
                    }
                    hash_arr[fk]=k;
                }
                break;
                
            case '-':
                cin>>k;
                for(i=0;i<h;i++)
                {
                    if(hash_arr[i]>=0 && hash_arr[i]==k)break;
                }
                hash_arr[i]=-1;
                break;
        }
    }
    return count;
}
