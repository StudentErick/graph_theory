#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN=751;
const double INF=1000000.0;
int N,M;  //��Ҫ�޽��ģ��Ѿ����ڵ�
double lowcost[MAXN];
int nearvex[MAXN];
double G[MAXN][MAXN];
int X[MAXN],Y[MAXN];
struct Edge
{
    int u,v;
}edge[MAXN];

int cmp(const Edge &a,const Edge &b)
{
    return a.u<b.u;
}

void Prim(int u)
{
    int num=0;
    for(int i=1;i<=N;i++)
    {
        lowcost[i]=G[u][i];
        nearvex[i]=u;
    }
    nearvex[u]=-1;
    for(int i=1;i<=N-1;i++)
    {
        double Min=INF;
        int v=-1;
        //ѡ������ı�
        for(int j=1;j<=N;j++)
        {
            if(nearvex[j]!=-1&&lowcost[j]<Min)
            {
                Min=lowcost[j];
                v=j;
            }
        }
        if(v!=-1)
        {
            if(G[nearvex[v]][v]!=0)  //�����ڹ�·����
            {
                edge[num].u=nearvex[v];
                edge[num].v=v;
                num++;
            }
            nearvex[v]=-1;
            //���������Ȩֵ
            for(int j=1;j<=N;j++)
            {
                if(nearvex[j]!=-1&&lowcost[j]>G[v][j])
                {
                    lowcost[j]=G[v][j];
                    nearvex[j]=v;
                }
            }
        }
    }
    if(num!=0)
    {
        //������߲����򣬶�����ν
    //    sort(edge,edge+num,cmp);  //����Ҫ������
        for(int i=0;i<num;i++)
        {
            printf("%d %d\n",edge[i].u,edge[i].v);
        }
    }
    else  //�������⣬û��ҲҪ���
        printf("");
}

int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%d%d",&X[i],&Y[i]);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            if(i==j)G[i][j]=0.0;
            else G[i][j]=sqrt(double((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j])));
    scanf("%d",&M);
    for(int i=0;i<M;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x][y]=G[y][x]=0.0;
    }
    Prim(1);
    return 0;
}
