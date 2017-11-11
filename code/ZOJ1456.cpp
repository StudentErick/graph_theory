#include<cstdio>
#include<cstring>
const int MAXN=200;
const int INF=10000;
int G[200][200],N,M,path[200];
long long dist[200],T[200];
void BF(int v,int END){
    for(int i=0;i<N;i++){
        dist[i]=G[v][i]+T[i];   //������˰��
        if(i==END)dist[i]-=T[i];//�յ㲻������˰��
        if(i!=v&&dist[i]<INF)path[i]=v;
        else path[i]=-1;
    }
    dist[v]=0;
    for(int k=0;k<N-1;k++){
        for(int u=0;u<N;u++){   //�޸�ÿ�����������
            if(u==v)continue;
            for(int j=0;j<N;j++){
                if(G[u][j]<INF&&dist[u]+G[u][j]<dist[j]){
                    if(j!=END)   //�����յ���У���Ҫ���ϵ�j�����е�˰��
                        dist[j]=dist[u]+G[u][j]+T[j];
                    else dist[j]=dist[u]+G[u][j];  //���յ���У�����˰��
                    path[j]=u;
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
                if(G[i][j]==-1)G[i][j]=INF;
            }
        }
        for(int i=0;i<N;i++)scanf("%ld",&T[i]);
        int u,v;
        while(scanf("%d%d",&u,&v)){
            if(u<0||v<0)break;
            u--;v--;
            BF(u,v);
            int shortest[MAXN];
            memset(shortest,0,sizeof(shortest));
            int k=0;shortest[k]=v;
            while(path[shortest[k]]!=u)
                shortest[++k]=path[shortest[k-1]];
            shortest[++k]=u;
            printf("From %d to %d:\nPath:",u+1,v+1);
            for(int j=k;j>0;j--)
                printf("%d->",shortest[j]+1);
            printf("%d\n",shortest[0]+1);
            printf("Total cost: %ld\n\n",dist[v]);
        }
    }
    return 0;
}
