#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=100;
const int INF=100000;
int G[MAXN][MAXN],dist[MAXN],path[MAXN],inq[MAXN],N;
void SPFA(int v){
    for(int i=0;i<MAXN;i++){
        dist[i]=INF;path[i]=-1;inq[i]=0;
    }
    dist[v]=0;inq[v]=1;path[v]=v;
    queue<int>Q;
    Q.push(v);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();inq[u]--;
        for(int i=0;i<N;i++){
            if(i!=u&&G[u][i]<INF&&dist[u]+G[u][i]<dist[i]){
                dist[i]=dist[u]+G[u][i];
                path[i]=u;
                if(!inq[i]){
                    inq[i]++;Q.push(i);
                }
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
            if(i==j)G[i][j]=0;
        }
    }
    SPFA(0);
    int shortest[MAXN];
    for(int i=1;i<N;i++){
        memset(shortest,0,sizeof(shortest));
        int k=0;
        shortest[k]=i;
        while(path[shortest[k]]!=0)
            shortest[++k]=path[shortest[k-1]];
        shortest[++k]=0;
        for(int j=k;j>=0;j--)
            printf("%d ",shortest[j]);
        puts("");
    }
    return 0;
}
