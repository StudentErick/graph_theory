#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1000;
int sumWidget=0;     //权重的总和
int parent[MAXN];    //并查集
int verNum,arcNum;   //结点数目，边的数目

struct Edge
{
    int u,w,v;       //u、v是结点；w是权重
}edge[MAXN];

//排序比较函数
int cmp(const Edge &a,const Edge &b)
{
    return a.w<b.w;
}

//并查集初始化
void UFset()
{
    memset(parent,-1,sizeof(parent));
}

//带有压缩路径的合并算法
int Find(int x)
{
    int s;
    for(s=x;parent[s]>=0;s=parent[s]);  //寻找最早祖先
    while(s!=x)
    {
        int tmp=parent[x];
        parent[x]=s;
        x=tmp;
    }
    return s;
}

//带有权重的合并算法
void Union(int x,int y)
{
    int r1=Find(x);
    int r2=Find(y);
    int sum=parent[r1]+parent[r2];
    if(parent[r1]<parent[r2])  //r1的元素多
    {
        parent[r2]=r1;
        parent[r1]=sum;
    }
    else                       //r2的元素多
    {
        parent[r1]=r2;
        parent[r2]=sum;
    }
}

void Kruskal()
{
    sort(edge,edge+arcNum,cmp);
    int num=0;    //以选用边的数目
    UFset();
    sumWidget=0;
    for(int i=0;i<arcNum;i++)
    {
        int u=edge[i].u;
        int v=edge[i].v;
        if(Find(u)!=Find(v))
        {
            sumWidget+=edge[i].w;
            Union(u,v);  //合并结点
            num++;       //MST的边增加
            printf("%d->%d: %d\n",u,v,edge[i].w);
        }
        //已经构成了MST
        if(num>verNum-1)
            break;
    }
}

int main()
{
    scanf("%d%d",&verNum,&arcNum);  //输入边和结点的总数
    for(int i=0;i<arcNum;i++)
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    Kruskal();
    printf("widget of MST is %d\n",sumWidget);
    return 0;
}
/*
测试数据
7 9
1 2 28
1 6 10
2 3 16
2 7 14
3 4 12
4 5 22
4 7 18
5 6 25
5 7 24
*/
