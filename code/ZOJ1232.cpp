#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=101;
const int MAXM=10000;
const int INF=1000000;
int T,A,B,M,L,K;
int G[MAXN][MAXN];
int S[MAXN],path[MAXN],dist[MAXN];
struct Edge
{
    int u,v,w;
}edge[MAXM];

int cmp(const Edge &a,const Edge &b){
    return a.w<b.w;
}

void Dijkstra(int v)
{
    for(int i=1;i<=A+B;i++)
    {
        S[i]=0;
        dist[i]=G[v][i];
        if(i!=v&&dist[i]<INF)path[i]=v;
        else path[i]=-1;
    }
    dist[v]=0;S[v]=1;
    for(int i=1;i<=A+B-1;i++)
    {
        int Min=INF,u=v;
        for(int j=1;j<=A+B;j++)
        {
            if(!S[j]&&dist[j]<Min)
            {
                Min=dist[j];
                u=j;
            }
        }
        S[u]=1;
        for(int j=1;j<=A+B;j++)
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
    scanf("%d",&T);
    while(T--)
    {
        memset(path,-1,sizeof(path));
        memset(dist,0,sizeof(dist));
        memset(S,0,sizeof(S));
        memset(edge,0,sizeof(edge));
        scanf("%d%d%d%d%d",&A,&B,&M,&L,&K);
        for(int i=1;i<=A+B;i++)
            for(int j=1;j<=A+B;j++)
                if(i==j)G[i][j]=0;
                else G[i][j]=INF;
        for(int i=0;i<M;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            G[u][v]=G[v][u]=w;
        }
        Dijkstra(1);
        int shortest[MAXN];
        memset(shortest,0,sizeof(shortest));
        int k=0;
        shortest[k]=A+B;
        while(path[shortest[k]]!=1)
        {
            shortest[k+1]=path[shortest[k]];
            edge[k].u=shortest[k];
            edge[k].v=shortest[k+1];
            edge[k].w=G[shortest[k]][shortest[k+1]];
            k++;
        }
        edge[k].u=shortest[k];
        edge[k].v=1;
        edge[k].w=G[1][shortest[k]];
        edge[++k].u=0;
        edge[k].v=0;
        edge[k].w=0;  //简化处理最后特殊情况
        sort(edge,edge+k,cmp);
        int widget=0;
        int n=k;
        for(int i=0;i<=n;i++)
        {
            if(K>0)  //使用次数还有剩余
            {
                int t=edge[i].w/L;  //这条路能用几次
                K-=t;               //使用的次数减少
                if(K<0)t=K;         //处理路径特别长的情况
                edge[i].w-=t*L;     //当前路径剩余减少
                if(edge[i].w>=edge[i+1].w)   //对于当前路径还有剩余
                {
                    if(K>0)
                    {
                        edge[i].w-=L;
                        K--;
                        if(edge[i].w<0)edge[i].w=0;   //防止路径出现负数的情况
                    }
                }
            }
            widget+=edge[i].w;
        }
        printf("%d\n",widget);
    }
    return 0;
}
/*
1
4 2 6 9 1
4 6 1
5 6 10
4 5 5
3 5 4
2 3 4
1 2 3
*/
