#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1001;
const int MAXM=15001;
int sumWidget=0;
int parent[MAXN];
int verNum,arcNum;

struct Res
{
    int u,v;
}res[MAXM];

struct Edge
{
    int u,v,w;
    Edge(){u=v=w=0;}
}edge[MAXM];

int cmp(const Edge &a,const Edge &b)
{
    return a.w<b.w;
}

int cmp1(const Res &a,const Res &b)
{
    return a.u<b.u;
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
    UFset();
    sumWidget=0;
    sort(edge,edge+arcNum,cmp);
    int num=0;  //边的实际连接数量
    int minedge=0;
    for(int i=0;i<arcNum;i++)
    {
        if(Find(edge[i].u)!=Find(edge[i].v))
        {
           Union(edge[i].u,edge[i].v);
           res[num].u=edge[i].u;
           res[num].v=edge[i].v;
           if(minedge<edge[i].w)
              minedge=edge[i].w;
           num++;
        }
        if(num>verNum-1)
            break;
    }
    sort(res,res+num,cmp1);
    printf("%d\n%d\n",minedge,num);
    for(int i=0;i<num;i++)
        printf("%d %d\n",res[i].u,res[i].v);
}

int main()
{
    scanf("%d%d",&verNum,&arcNum);
    for(int i=0;i<arcNum;i++)
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    Kruskal();
    return 0;
}

/*
4 6
1 2 1
1 3 1
1 4 2
2 3 1
3 4 1
2 4 1

5 8
1 2 5
1 4 2
1 5 1
2 3 6
2 4 3
3 4 5
3 5 4
4 5 6
*/
