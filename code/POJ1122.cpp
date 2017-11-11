#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const double INF=1000000.0;
const int MAXN=25;
int G[MAXN][MAXN],N;
int dist[MAXN],S[MAXN],path[MAXN];
struct point{
    int num,len;
}points[MAXN];
bool cmp(const point &a,const point &b){
    return a.len<b.len;
}
void Dijkstra(int v){
    for(int i=0;i<N;i++){
        dist[i]=G[v][i];S[i]=0;
        if(i!=v&&dist[i]<INF)path[i]=v;
        else path[i]=-1;
    }
    S[v]=1;dist[v]=0;
    for(int i=0;i<N-1;i++){
        int Min=INF,u=v;
        for(int j=0;j<N;j++){
            if(!S[j]&&dist[j]<Min){
                Min=dist[j];u=j;
            }
        }
        S[u]=1;
        for(int k=0;k<N;k++){
            if(!S[k]&&G[u][k]<INF&&dist[u]+G[u][k]<dist[k]){
                dist[k]=dist[u]+G[u][k];
                path[k]=u;
            }
        }
    }
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&G[i][j]);
            if(G[i][j]==-1)G[i][j]=INF;
        }
    }
    int Begin;
    scanf("%d",&Begin);
    Begin--;
    Dijkstra(Begin);
    int u=0,t=0;
    while(scanf("%d",&u)!=EOF){
        points[t].num=--u;
        points[t].len=dist[u];
        t++;
    }
    sort(points,points+t,cmp);
    printf("Org\tDest\tTime\tPath\n");
    for(int i=0;i<t;i++){
        printf("%d\t%d\t%d\t",points[i].num+1,Begin+1,points[i].len);
        int shortest[MAXN];
        memset(shortest,0,sizeof(shortest));
        int k=0;
        shortest[k]=points[i].num;
        while(path[shortest[k]]!=Begin)
            shortest[++k]=path[shortest[k-1]];
        shortest[++k]=Begin;
        for(int j=0;j<=k;j++)
            if(j==0)printf("%d",shortest[j]+1);
            else printf("\t%d",shortest[j]+1);
        printf("\n");
    }
    return 0;
}
/*
6
0  3  4 -1 -1 -1
-1 0  4  5 -1 -1
2  3  0 -1 -1  2
8  9  5  0  1 -1
7  2  1 -1  0 -1
5 -1  4  5  4  0
2  4  5  6

Org	Dest	Time	Path
5	2	2	5	2
4	2	3	4	5	2
6	2	6	6	5	2
*/
