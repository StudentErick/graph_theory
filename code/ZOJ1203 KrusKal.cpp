#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXN=5000;
double X[MAXN],Y[MAXN];
double sumWidget;
int verNum,arcNum;
int parent[MAXN];
struct Edge
{
    double w;
    int u,v;
}edge[MAXN];

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
    int r1=Find(x);
    int r2=Find(y);
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
    sumWidget=0.0;
    UFset();
    sort(edge,edge+arcNum,cmp);
    int num=0;
    for(int i=0;i<arcNum;i++)
    {
        if(Find(edge[i].u)!=Find(edge[i].v))
        {
            sumWidget+=edge[i].w;
            Union(edge[i].u,edge[i].v);
            num++;
        }
        if(num>verNum-1)
            break;
    }
}

int main()
{
    int t=0;
    while(scanf("%d",&verNum)&verNum)
    {
        for(int i=0;i<verNum;i++)
            scanf("%lf%lf",&X[i],&Y[i]);
        arcNum=0;
        memset(edge,0,sizeof(edge));
        for(int i=0;i<verNum-1;i++)
        {
            for(int j=i+1;j<verNum;j++)
            {
                edge[arcNum].u=i;
                edge[arcNum].v=j;
                edge[arcNum].w=sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
                arcNum++;
            }
        }
        Kruskal();
        if(t!=0)
            puts("");
        printf("Case #%d:\nThe minimal distance is: %.2f\n",++t,sumWidget);
    }
    return 0;
}
