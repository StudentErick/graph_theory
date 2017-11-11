#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
const int MAXN=1000;
const int INF=10000000;
struct Edge
{
    int u,v;
    double w;
}edge[MAXN];
char Name[MAXN][20],a[20],b[20];
int N,M,flag;
double dist[MAXN];
//��Ҫ����˼���Ӧ��
void bellman_ford(int v){
    flag=0;
    memset(dist,0,sizeof(dist));  //��ʼ��
    dist[v]=1.0;
    for(int k=1;k<=N;k++){   //ע������ܹ�����N�Σ����ÿ��԰���Դ�㣬֮ǰ��N-1�ǲ����� Դ������
        for(int i=0;i<M;i++){  //�ܹ���M���ߣ���ÿ���߶������ɳڲ���
            if(edge[i].w*dist[edge[i].u]>dist[edge[i].v]){
                dist[edge[i].v]=dist[edge[i].u]*edge[i].w;
            }
        }
    }
    if(dist[v]>1.0)flag=1;
}
int main()
{
    int t=1;
    while(scanf("%d",&N)&&N){
        for(int i=0;i<N;i++)
            scanf("%s",Name[i]);
        scanf("%d",&M);
        for(int k=0;k<M;k++){
            double w=0.0;
            scanf("%s %lf %s",a,&w,b);
            int i,j;
            for(i=0;strcmp(Name[i],a);i++);
            for(j=0;strcmp(Name[j],b);j++);
            edge[k].u=i;edge[k].v=j;edge[k].w=w;
        }
        for(int i=0;i<N;i++){
            bellman_ford(i);
            if(flag)break;
        }
        if(flag)printf("Case %d: Yes\n",t++);
        else printf("Case %d: No\n",t++);
    }
    return 0;
}
