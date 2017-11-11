#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=2000;
const int INF=100000;
int G[MAXN][MAXN],path[MAXN],dist[MAXN],T[MAXN],inq[MAXN],N;   //T是税收
void SPFA(int v,int END){
    for(int i=0;i<N;i++){
        dist[i]=INF;path[i]=v;inq[i]=0;
    }
    dist[v]=0;inq[v]++;path[v]=v;
    queue<int>Q;
    Q.push(v);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();inq[u]++;
        for(int i=0;i<N;i++){
            if(i!=u&&G[u][i]<INF){
                if(i!=END&&dist[u]+G[u][i]+T[i]<dist[i]){  //不是终点要收税
                    dist[i]=dist[u]+G[u][i]+T[i];
                    path[i]=u;
                }
                else if(i==END&&dist[u]+G[u][i]<dist[i]){  //终点不收税
                    dist[i]=dist[u]+G[u][i];
                    path[i]=u;
                }
                if(!inq[i]){
                    inq[i]++;Q.push(i);
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d",&N)&&N){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&G[i][j]);
                if(G[i][j]<0)G[i][j]=INF;
            }
        }
        for(int i=0;i<N;i++)
            scanf("%d",&T[i]);
        int u,v;
        int shortest[MAXN];
        while(scanf("%d%d",&u,&v)&&u>=0&&v>=0){
            u--;v--;
            SPFA(u,v);
            memset(shortest,0,sizeof(shortest));
            int k=0;
            shortest[k]=v;
            while(path[shortest[k]]!=u)
                shortest[++k]=path[shortest[k-1]];
            shortest[++k]=u;
            printf("From %d to %d :\nPath: ",u+1,v+1);
            for(int j=k;j>0;j--)
                printf("%d->",shortest[j]+1);
            printf("%d\n",shortest[0]+1);
            printf("Total cost : %d\n\n",dist[v]);
        }
    }
    return 0;
}
