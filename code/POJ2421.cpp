#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=101;
const int MAXM=10000;
int N,M,Q;

struct Edge
{
    int u,w,v;
}edge[MAXM];  //³õÊ¼»¯µÄ±ß

int X[MAXM],Y[MAXM];

int G[100][100];  //¾àÀë¾ØÕó
int parent[MAXN];

int cmp(const Edge &a,const Edge &b)
{
    return a.w<b.w;
}

void UFset()
{
    memset(parent,-1,sizeof(parent));
}

int Find(int x)
{
    int s;
    for(s=x;parent[s]>=0;s=parent[s]);
    while(s!=x)
    {
        int tmp=parent[x];
        parent[x]=s;
        x=tmp;
    }
    return s;
}

void Union(int x,int y)
{
    int r1=Find(x),r2=Find(y);
    int sum=parent[r1]+parent[r2];
    if(parent[r1]<parent[r2])
    {
        parent[r1]=sum;
        parent[r2]=r1;
    }
    else
    {
        parent[r2]=sum;
        parent[r1]=r2;
    }
}

void Kruskal()
{
    int sumWidget=0;
    int num=0;
    UFset();
    sort(edge,edge+M,cmp);
    for(int i=0;i<M;i++)
    {
        if(Find(edge[i].u)!=Find(edge[i].v))
        {
            Union(edge[i].u,edge[i].v);
            num++;
            sumWidget+=edge[i].w;
        }
        if(num>N-1)
            break;
    }
    printf("%d",sumWidget);
}

int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&G[i][j]);
    int k=0;
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            edge[k].u=i;
            edge[k].v=j;
            edge[k].w=G[i][j];
            k++;
        }
    }
    M=k;
    scanf("%d",&Q);
    for(int i=0;i<Q;i++)
        scanf("%d%d",&X[i],&Y[i]);
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<Q;j++)
        {
            if(edge[i].u==X[j]-1&&edge[i].v==Y[j]-1)
                edge[i].w=0;
        }
    }
    Kruskal();
    return 0;
}
