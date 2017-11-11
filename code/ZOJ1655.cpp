#include<cstdio>
#include<cstring>
const double INF=1000000.0;
const int MAXN=100;
double G[MAXN][MAXN],dist[MAXN*MAXN];
int S[MAXN*MAXN],path[MAXN*MAXN],city[MAXN*MAXN],N,M;
void Dijkstra(int v){
    for(int i=0;i<N;i++){
        S[i]=0;dist[i]=G[v][i];
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
        for(int j=0;j<N;j++){
            if(!S[j]&&G[u][j]<INF&&dist[u]+G[u][j]<dist[j]){
                dist[j]=dist[u]+G[u][j];
                path[j]=u;
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF){
        double sumAll=0.0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==j)G[i][j]=0.0;
                else G[i][j]=INF;
            }
        }
        for(int i=0;i<N-1;i++)
            scanf("%d",&city[i]);
        for(int i=0;i<M;i++){
            int u,v;
            double w;
            scanf("%d%d%lf",&u,&v,&w);
            if(w<G[u-1][v-1])
                G[u-1][v-1]=G[v-1][u-1]=w; ///注意这里是无向图!!!注意重边
        }
        Dijkstra(N-1);
        for(int i=0;i<N-1;i++){  //总共N个城市，逐个累加，算上损失率
            int shortest[MAXN];
            memset(shortest,0,sizeof(shortest));
            int k=0;
            shortest[k]=i;
            while(path[shortest[k]]!=N-1)
                shortest[++k]=path[shortest[k-1]];
            shortest[++k]=N-1;
            double sum=city[i];
            for(int j=0;j<k;j++){   //计算每个城市到首都的损失
                sum*=(1-G[shortest[j]][shortest[j+1]]);
            }
            sumAll+=sum;
        }
        printf("%.2f\n",sumAll);
    }
}
/*
Sample Input

5 6
10
10
10
10
1 3 0
1 4 0
2 3 0
2 4 0
3 5 0
4 5 0


Sample Output

40.00


*/
