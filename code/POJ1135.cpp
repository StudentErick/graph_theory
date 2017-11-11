#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 501;
const double INF = 1000000.0;
double G[MAXN][MAXN];
int N, M;   //点的个数，边的个数
double dist[MAXN];
int S[MAXN];
struct edge
{
	int u, v;
	double w;
}E[MAXN];

void Dijkstra(int v)
{
	for (int i = 1;i <= N;i++)
	{
		S[i] = 0;
		dist[i] = G[v][i];
	}
	S[v] = 1;
	for (int i = 0;i < N - 1;i++)
	{
		int Min = INF, u = v;
		for (int j = 1;j <= N;j++)
		{
			if (!S[j] && dist[j] < Min)
			{
				Min = dist[j];
				u = j;
			}
		}
		S[u] = 1;
		for (int j = 1;j <= N;j++)
		{
			if (!S[j] && G[u][j]<N&&dist[j]>dist[u] + G[u][j])
			{
				dist[j] = dist[u] + G[u][j];
			}
		}
	}
}

int main()
{
	int t = 1;
	while (scanf("%d%d", &N, &M) && N)
	{
        if(M==0)
        {
            int u,v;double w;
          //  scanf("%d%d%lf",&u,&v,&w);
            printf("System #%d\nThe last domino falls after 0.0 seconds, at key domino 1.\n\n", t++);
        }
        else
        {
            for(int i=1;i<=N;i++)
                for(int j=1;j<=N;j++)
                    if(i==j)G[i][j]=0;
                    else G[i][j]=INF;
            for(int i=0;i<M;i++)
            {
                int u,v;double w;
                scanf("%d%d%lf",&u,&v,&w);
                G[u][v]=G[v][u]=w;
            }
            Dijkstra(1);
            double Max1=-INF,Max2=-INF;
            int no,no1,no2;
            for(int i=1;i<=N;i++)
            {
                if(dist[i]>Max1)
                {
                    Max1=dist[i];
                    no=i;
                }
            }
            for(int i=1;i<=N;i++)
            {
                for(int j=1;j<=N;j++)
                {
                    if(G[i][j]<INF&&i!=j&&Max2<(dist[i]+dist[j]+G[i][j])/2.0)
                    {
                        Max2=(dist[i]+dist[j]+G[i][j])/2.0;
                        no1=i;no2=j;
                    }
                }
            }
            if(N==1)
                printf("System #%d\nThe last domino falls after 0.0 seconds, at key domino 1.\n\n", t++);
            else if(Max1>=Max2)
                printf("System #%d\nThe last domino falls after %.1f seconds, at key domino %d.\n\n", t++, Max1, no);
            else
                printf("System #%d\nThe last domino falls after %.1f seconds, between key dominoes %d and %d.\n\n", t++, Max2, no1, no2);
        }
	}
	return 0;
}
/*
2 1
1 2 27
3 3
1 2 5
1 3 5
2 3 5
0 0
*/
