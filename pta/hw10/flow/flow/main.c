//
//  main.c
//  flow
//
//  Created by 吴杰 on 2019/11/29.
//  Copyright © 2019 吴杰. All rights reserved.
//

#include <stdio.h>
#include<string.h>
#include <math.h>
#define max 501
#define INF 2e9
struct node
{
    int c;
    int f;
}edge[max][max];

int visit[max],pre[max],min[max],queue[max],v,st,en,h,t,n,m,hash[max];

void bfs();
void Ford_F();
void max_flow();
int _min(int a,int b);
int _abs(int a);
void input();
int _hash(char a[]);


int main(int argc, const char * argv[]) {

    input();
    st=1;en=2;
    Ford_F();
    max_flow();
    return 0;
}

void input()
{
    char temp1[4],temp2[4];
    scanf("%s%s%d",temp1+1,temp2+1,&m);
    st=_hash(temp1);
    en=_hash(temp2);
    hash[++n]=st;
    hash[++n]=en;
    
    
    for(int i=0;i<m;i++)
    {
        int t1,t2,t3;
        int indexi,indexj;
        scanf("%s %s %d",temp1+1,temp2+1,&t3);
        t1=_hash(temp1);
        t2=_hash(temp2);
        int flag=1;
        for(int i=1;i<=n;i++)
        {
            if(hash[i]==t1)
            {
                flag=0;
                indexi=i;
                break;
            }
        }
        if(flag)
        {
            hash[++n]=t1;
            indexi=n;
        }
        flag=1;
        for(int i=1;i<=n;i++)
        {
            if(hash[i]==t2)
            {
                flag=0;
                indexj=i;
                break;
            }
        }
        if(flag)
        {
            hash[++n]=t2;
            indexj=n;
        }
        
        
        
        edge[indexi][indexj].c=t3;
        
    }
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(edge[i][j].c==0)edge[i][j].c=INF;
        }
    
    
    
}

int _hash(char a[])
{
    int a1,a2,a3;
    a1=26*26*(a[1]-'A');
    a2=26*(a[2]-'A');
    a3=(a[3]-'A');
    return a1+a2+a3;
}

void bfs()
{
    memset(visit,-1,sizeof(visit));
    memset(pre,-1,sizeof(pre));
    memset(min,-1,sizeof(min));
    visit[st]=0;
    pre[st]=0;
    min[st]=INF;
    h=0;
    t=1;
    queue[t]=st;
    while (h<t) {
        h++;
        v=queue[h];
        for(int i=1;i<=n;i++)
        {
            if(visit[i]==-1)
            {
                if(edge[v][i].c<INF && edge[v][i].f<edge[v][i].c)
                {
                    visit[i]=0;
                    pre[i]=v;
                    min[i]=_min(min[v],edge[v][i].c-edge[v][i].f);
                    queue[++t]=i;
                }
                else if(edge[i][v].c<INF && edge[i][v].f>0)
                {
                    visit[i]=0;
                    pre[i]=-v;
                    min[i]=_min(min[v],edge[i][v].f);
                    queue[++t]=i;
                }
            }
        }
        visit[v]=0;
    }
    
}

void Ford_F()
{
    while(1){
        bfs();
        if(min[en]==0||visit[en]==-1)
        {
            break;
        }
        int k1=en,k2=_abs(pre[k1]);
        int a=min[en];
        while(1){
            if(edge[k2][k1].c<INF) edge[k2][k1].f+=a;
            else if(edge[k1][k2].c<INF) edge[k1][k2].f-=a;
            if(k2==st) break;
            k1=k2;k2=_abs(pre[k1]);
        }
        min[en]=0;
    }
}

void max_flow()
{
    int maxflow=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
        if(i==st&&edge[i][j].f<INF) maxflow+=edge[i][j].f;
        }
       printf("%d",maxflow);
}
int _abs(int a)
{
    if(a<0)a=-a;
    return a;
}

int _min(int a,int b)
{
    if(a>b)return b;
    else return a;
}
