#include<cstdio>    //不构造矩阵
#include<cstring>
const int MAXN=100;
const int INF=1000000;
int path[MAXN],dist[MAXN],N,M;
struct Edge{
    int u,v,w;
}edge[MAXN];
void BellmanFord(int v){
    for(int i=0;i<N;i++){
        dist[i]=INF;path[i]=-1;
    }
    dist[v]=0;
    for(int k=1;k<N;k++){     //总共进行N-1次松弛操作
        for(int i=0;i<M;i++){ //判断第i条边的引入是否会缩短源点到顶点的最短路径长度
            if(dist[edge[i].u]!=INF&&dist[edge[i].u]+edge[i].w<dist[edge[i].v]){
                dist[edge[i].v]=dist[edge[i].u]+edge[i].w;
                path[edge[i].v]=edge[i].u;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++)
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    BellmanFord(0);
    int shortest[MAXN];
    for(int i=1;i<N;i++){
        memset(shortest,0,sizeof(shortest));
        int k=0;
        shortest[k]=i;
        while(path[shortest[k]]!=0)
            shortest[++k]=path[shortest[k-1]];
        shortest[++k]=0;
        for(int j=k;j>0;j--)
            printf("%d->",shortest[j]);
        printf("%d\n",shortest[0]);
    }
    for(int i=0;i<N;i++)
        printf("%d ",path[i]);
    puts("");
    for(int i=0;i<N;i++)
        printf("%d ",dist[i]);
    puts("");
    return 0;
}
/*
7 10
0 1 6
0 2 5
0 3 5
1 4 -1
2 1 -2
2 4 1
3 2 -2
3 5 -1
4 6 3
5 6 3
*/
