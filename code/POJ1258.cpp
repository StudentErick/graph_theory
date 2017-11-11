#include<cstdio>

const int INF=1000000;
const int MAXN=101;
int lowcost[MAXN],nearvex[MAXN];
int G[MAXN][MAXN];
int N;

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
        int Min=INF,v=-1;
        //选择权重最小的边处理
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
                    nearvex[j]=v;
                    lowcost[j]=G[v][j];
                }
            }
        }
    }
    printf("%d\n",sumWidget);
}

int main()
{
    while(scanf("%d",&N)!=EOF)
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                scanf("%d",&G[i][j]);
        Prim(0);
    }
    return 0;
}
