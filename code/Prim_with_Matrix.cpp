#include<cstdio>
#include<cstring>

const int INF=1000000;
const int MAXN=1000;
int N,M;     //���������ߵĸ���
int G[MAXN][MAXN];
int lowcost[MAXN],nearvex[MAXN];

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
        //ѡ����С�ı��Լ�����
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
            printf("<%d,%d> %d\n",nearvex[v],v,lowcost[v]);
            nearvex[v]=-1;  //���뼯��T
            sumWidget+=lowcost[v];
            //���¾�������
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
    printf("The Widget of MST is %d\n",sumWidget);
}

int main()
{
    scanf("%d%d",&N,&M);
    int u,v,w;
    memset(G,0,sizeof(G));
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        G[u][v]=G[v][u]=w;
    }
    for(int i=0;i<N-1;i++)
        for(int j=0;j<N;j++)
            if(G[i][j]==0)
                G[i][j]=G[j][i]=INF;
    Prim(0);
    return 0;
}
/*
�������ݣ�
7 9
0 1 28
0 5 10
1 2 16
1 6 14
2 3 12
3 4 22
3 6 18
4 5 25
4 6 24
*/
