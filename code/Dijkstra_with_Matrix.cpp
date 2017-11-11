#include<cstdio>
#include<cstring>

const int MAXN=100;
const int INF=100000;
int G[MAXN][MAXN];
int N,M;
int dist[MAXN],path[MAXN],S[MAXN];
//距离的选择基于贪心思想
/*
S：存放已经找到最短路径的顶点集合
T：存放未找到最短路径的顶点集合
dist[]：存放源点到某顶点最短路径的长度
        dist[i]=w1,表示结点i到源点最短
        的路径长度是w1.初始状态，dist是
        邻接矩阵的第v行，即源点所在行
S[]：结点在S还是集合T的区分标志。
     S[i]==1,顶点在S中；S[i]==0顶点在T中
path[]：保存顶点路径用的。paht[i]=u，表示
        源点v0到结点vi的最短路中，vi的
        前一个结点的是u
*/
void Dijkstra(int v)
{
    memset(path,0,sizeof(path));
    for(int i=0;i<N;i++)
    {
        S[i]=0;
        dist[i]=G[v][i];
        if(i!=v&&dist[i]<INF)
            path[i]=v;        //注意这里的0
        else path[i]=-1;
    }
    S[v]=1;dist[v]=0;
    //处理剩下的N-1个结点
    for(int i=0;i<N-1;i++)
    {
        int Min=INF,u=v;
        for(int j=0;j<N;j++)
        {
            if(!S[j]&&dist[j]<Min)
            {
                u=j;
                Min=dist[j];
            }
        }
        S[u]=1;      //加入集合S
        //更新距离以及路径
        for(int j=0;j<N;j++)
        {
            if(!S[j]&&G[u][j]<INF&&dist[u]+G[u][j]<dist[j])
            {
                dist[j]=dist[u]+G[u][j];
                path[j]=u;
            }
        }
    }
}

int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(i==j)G[i][j]=0;
            else G[i][j]=INF;
    for(;;)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(u<0||v<0||w<0)break;
        G[u][v]=w;
    }
    Dijkstra(0);
    int shortest[MAXN];  //倒序追踪的方法，模拟栈，与栈相比，优势在于可以查找元素
    for(int i=1;i<N;i++)
    {
        printf("%d\t",dist[i]);
        memset(shortest,0,sizeof(shortest));
        int k=0;
        shortest[k]=i;
        while(path[shortest[k]]!=0)
        {
            ++k;
            shortest[k]=path[shortest[k-1]];
        }
        ++k;
        shortest[k]=0;
        for(int j=k;j>0;j--)
            printf("%d->",shortest[j]);
        printf("%d\n",shortest[0]);
    }
    printf("path[]: ");
    for(int i=0;i<N;i++)
        printf("%d ",path[i]);
    printf("\ndist[]:\n");
     for(int i=0;i<N;i++)
        printf("%d ",dist[i]);
    return 0;
}
/*
测试数据：
6
0 2 5
0 3 30
1 0 2
1 4 8
2 5 7
2 1 15
4 3 4
5 3 10
5 4 18
-1 -1 -1
*/
