#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN=101;

int parent[MAXN];
int N,M;

struct Sta
{
    double x,y,z,r;
}S[MAXN];

struct Edge
{
    int u,v;
    double w;
}edge[MAXN*MAXN];

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

void Union(int x,int  y)
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
    double sumWidget=0.0;
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
        if(num>=N-1)
            break;
    }
    printf("%.3f\n",sumWidget);
}

int main()
{
    while(scanf("%d",&N)&&N)
    {
        for(int i=0;i<N;i++)
        {
            scanf("%lf%lf%lf%lf",&S[i].x,&S[i].y,&S[i].z,&S[i].r);
        }
        M=0;
        memset(edge,0,sizeof(edge));
        for(int i=0;i<N-1;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                double dis=sqrt((S[i].x-S[j].x)*(S[i].x-S[j].x)+(S[i].y-S[j].y)*(S[i].y-S[j].y)+(S[i].z-S[j].z)*(S[i].z-S[j].z))-S[i].r-S[j].r;
                if(dis<0)
                    dis=0.0;
                edge[M].u=i;
                edge[M].v=j;
                edge[M].w=dis;
                M++;
            }
        }
        Kruskal();
    }
    return 0;
}
