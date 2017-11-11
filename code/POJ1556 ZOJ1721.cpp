#include<cstdio>
const int MAXN=100;
const int INF=1000000;
struct Edge{
    int u,v;
    double w;
};
struct Dis{
    double x,y;
}d[MAXN][4];
int N,M;
double dist[MAXN];
void bellman_ford(int v){
    for(int i=0;i<N;i++)
        dist[i]=INF;
    for(int k=1;k<N;k++){
        for(int i=0;i<M;i++){
            if(dist[edge[i].u]!=INF&&dist[edge[i].u]+edge[i].w<dist[edge[i].v])
                dist[edge[i].v]=dist[edge[i].u]+edge[i].w;
        }
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n>=0){
        if(n==0){   //处理没有墙的特殊情况
            printf("10.00\n");
            continue;
        }
        int line=1;  //是否可以走直线而没有墙的阻挡
        for(int i=0;i<n;i++){   //读入所有的坐标
           double x,y;
           scanf("%lf",&x);
           for(int j=0;j<4;j++){
                scanf("%lf",y);
                d[i][j].x=x;d[i][j].y=y;
                N++;
           }
        }
        int t=0;
        for(int i=0;i<N-1;i++){
            for(int j=i+1;j<N;j++){
                edge[t].u=i;edge[t].v=j;
                edge[t].w=(d[i].x-d[j].x)*(d[i].x-d[j].x)+(d[i].y-d[j].y)*(d[i].x-d[j].x);
            }
        }
    }
    return 0;
}
