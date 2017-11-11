#include<cstdio>
#include<cstring>
///把问题转换成有向图的最短路径问题的Dijkstra算法
const int MAXN=1002;  //最多1000个
const int INF=1000000;
struct Idio
{
    char first[5];
    char last[5];  //前4个后四个字符
    int w;                  //寻找字符花费的代价
}Id[MAXN];
int G[MAXN][MAXN];
int N,M;
int S[MAXN],dist[MAXN];

void Dijkstra(int v)
{
    for(int i=0;i<N;i++)
    {
        dist[i]=G[v][i];
        S[i]=0;
    }
    S[v]=1;dist[v]=0;
    for(int i=0;i<N-1;i++)
    {
        int Min=INF,u=0;
        for(int j=0;j<N;j++)
        {
            if(!S[j]&&dist[j]<Min)
            {
                Min=dist[j];
                u=j;
            }
        }
        S[u]=1;
        for(int j=0;j<N;j++)
        {
            if(!S[j]&&G[u][j]<INF&&dist[u]+G[u][j]<dist[j])
            {
                dist[j]=dist[u]+G[u][j];
            }
        }
    }
}

int main()
{
    while(scanf("%d",&N)!=EOF)
    {
        if(N==0)break;
        for(int k=0;k<N;k++)
        {
            char s[100];
            int t;
            scanf("%d%s",&Id[k].w,s);  //读取代价和字符
            int l=strlen(s);
            for(int i=0,j=l-1;i<4;i++,j--)   //读取前4个和后4个字符
            {
                Id[k].first[i]=s[i];
                Id[k].last[3-i]=s[j];
            }
            Id[k].first[4]=Id[k].last[4]='\0';
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                G[i][j]=INF;
                if(i==j)G[i][j]=0;
                else if(strcmp(Id[i].last,Id[j].first)==0)
                    G[i][j]=Id[i].w;
            }
        }
        Dijkstra(0);
        if(dist[N-1]!=INF)
            printf("%d\n",dist[N-1]);
        else printf("-1\n");
    }
    return 0;
}
/*
5
5 12345978ABCD2341
5 23415608ACBD3412
7 34125678AEFD4123
15 23415673ACC34123
4 41235673FBCD2156
2
20 12345678ABCD
30 DCBF5432167D
0
*/
