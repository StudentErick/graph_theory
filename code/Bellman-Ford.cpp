#include<cstdio>  //构造矩阵
const int MAXN=100;
const int INF=100000;
int N,M,S[MAXN],path[MAXN],dist[MAXN],G[MAXN][MAXN];
struct Edge
{
    int u,v,w;
}edge[MAXN];
void bellmanFord(int v){
    for(int i=0;i<N;i++){
        dist[i]=INF;path[i]=-1;
    }
    dist[v]=0;
    for(int k=1;k<N;k++){       //dist0递推到dist(N-1)，总共进行N-1次递推
        for(int i=0;i<M;i++){   //M是边的数目，对每一条边进行松弛操作
            if(dist[edge[i].u]!=INF&&edge[i].w+dist[edge[i].u]<dist[edge[i].v]){
                dist[edge[i].v]=edge[i].w+dist[edge[i].u];
                path[edge[i].v]=edge[i].u;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(i==j)G[i][j]=0;
            else G[i][j]=INF;
    for(int i=0;i<M;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u][v]=w;
    }
    bellmanFord(0);
    for(int i=1;i<N;i++){
        int k=0,shortest[MAXN];
        shortest[k]=i;
        while(path[shortest[k]]!=0)
            shortest[++k]=path[shortest[k-1]];
        shortest[++k]=0;
        for(int j=k;j>=0;j--)
            printf("%d ",path[j]);
        printf("\n");
    }
    return 0;
}
