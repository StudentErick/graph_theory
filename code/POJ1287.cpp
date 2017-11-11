#include<cstdio>
#include<cstring>

const int INF=100000;
const int MAXN=55;
int G[MAXN][MAXN];
int lowcost[MAXN],nearvex[MAXN];
int N,M;

void Prim(int u)
{
    int sumWidget=0;
    for(int i=1;i<=N;i++)
    {
        lowcost[i]=G[u][i];
        nearvex[i]=u;
    }
    nearvex[u]=-1;
    for(int i=1;i<=N-1;i++)
    {
        int Min=INF,v=-1;
        for(int j=1;j<=N;j++)
        {
            if(nearvex[j]!=-1&&lowcost[j]<Min)
            {
                Min=lowcost[j];
                v=j;
            }
        }
        sumWidget+=lowcost[v];
        nearvex[v]=-1;
        for(int j=1;j<=N;j++)
        {
            if(nearvex[j]!=-1&&lowcost[j]>G[v][j])
            {
                nearvex[j]=v;
                lowcost[j]=G[v][j];
            }
        }
    }
    printf("%d\n",sumWidget);
}

int main()
{
    while(scanf("%d",&N)&&N)
    {
        scanf("%d",&M);
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                if(i==j)G[i][j]=0;
                else G[i][j]=INF;
        for(int i=1;i<=M;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(G[u][v]==INF)
                G[u][v]=G[v][u]=w;
            else if(G[u][v]!=INF&&w<G[u][v])
                G[u][v]=G[v][u]=w;
        }
        Prim(1);
    }
    return 0;
}
