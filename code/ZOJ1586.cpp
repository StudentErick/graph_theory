#include<cstdio>
#include<cstring>
/*注意思路，不管限制条件怎么复杂，我们要做的，只是把复杂条件转换到边的权值上*/
const int MAXN=1001;
const int INF=1000000;
int G[MAXN][MAXN];
int adapter[MAXN];
int lowcost[MAXN],nearvex[MAXN];
int N,M;

void Prim(int u)
{
    int sumWidget=0;
    for(int i=0;i<N;i++)
    {
        lowcost[i]=G[u][i];
        nearvex[i]=u;
    }
    nearvex[u]=-1;
    for(int i=0;i<N-1;i++)
    {
        int Min=INF;
        int v=-1;
        for(int j=0;j<N;j++)
        {
            if(nearvex[j]!=-1&&lowcost[j]<Min)
            {
                Min=lowcost[j];
                v=j;
            }
        }
        if(v!=-1)
        {
            sumWidget+=lowcost[v];
            nearvex[v]=-1;
            for(int j=0;j<N;j++)
            {
                if(nearvex[j]!=-1&&lowcost[j]>G[v][j])
                {
                    lowcost[j]=G[v][j];
                    nearvex[j]=v;
                }
            }
        }
    }
    printf("%d\n",sumWidget);
}

int main()
{
    int all;
    scanf("%d",&all);
    while(all--)
    {
        scanf("%d",&N);
        M=N*(N-1)/2;
        for(int i=0;i<N;i++)
            scanf("%d",&adapter[i]);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                int u,v,w;
                scanf("%d",&w);
                if(i!=j)
                    G[i][j]=w+adapter[i]+adapter[j];
                else
                    G[i][j]=0;
            }
        }
        Prim(0);
    }
    return 0;
}
