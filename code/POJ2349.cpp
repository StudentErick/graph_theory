#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN=501;
const int INF=100000;
double lowcost[MAXN],nearvex[MAXN];
double G[MAXN][MAXN];
double edge[MAXN];   //MST边的权值
int N,M;   //结点和卫星的总数
int X[MAXN],Y[MAXN];

void Prim(int u)
{
    int sumWidget=0;
    int num=-1;
    for(int i=0;i<N;i++)
    {
        lowcost[i]=G[u][i];
        nearvex[i]=u;
    }
    nearvex[u]=-1;
    for(int i=0;i<N-1;i++)
    {
        int Min=INF,v=-1;
        //选择最近的结点
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
            edge[++num]=lowcost[v];  //保留边的权重
            nearvex[v]=-1;
            //更新数组
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
    double D=0.0;
    //从小到大排序
    sort(edge,edge+num+1);
    int t=N-M;  //需要接收机的边数
    printf("%.2f\n",edge[t-1]);
}

int main()
{
    int all;
    scanf("%d",&all);
    while(all--)
    {
        scanf("%d%d",&M,&N);
        for(int i=0;i<N;i++)
            scanf("%d%d",&X[i],&Y[i]);
        //构造图
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(i==j)G[i][j]=0;
                else G[i][j]=sqrt(double((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j])));
        Prim(0);
    }
    return 0;
}
