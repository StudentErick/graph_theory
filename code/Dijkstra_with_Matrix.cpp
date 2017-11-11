#include<cstdio>
#include<cstring>

const int MAXN=100;
const int INF=100000;
int G[MAXN][MAXN];
int N,M;
int dist[MAXN],path[MAXN],S[MAXN];
//�����ѡ�����̰��˼��
/*
S������Ѿ��ҵ����·���Ķ��㼯��
T�����δ�ҵ����·���Ķ��㼯��
dist[]�����Դ�㵽ĳ�������·���ĳ���
        dist[i]=w1,��ʾ���i��Դ�����
        ��·��������w1.��ʼ״̬��dist��
        �ڽӾ���ĵ�v�У���Դ��������
S[]�������S���Ǽ���T�����ֱ�־��
     S[i]==1,������S�У�S[i]==0������T��
path[]�����涥��·���õġ�paht[i]=u����ʾ
        Դ��v0�����vi�����·�У�vi��
        ǰһ��������u
*/
void Dijkstra(int v)
{
    memset(path,0,sizeof(path));
    for(int i=0;i<N;i++)
    {
        S[i]=0;
        dist[i]=G[v][i];
        if(i!=v&&dist[i]<INF)
            path[i]=v;        //ע�������0
        else path[i]=-1;
    }
    S[v]=1;dist[v]=0;
    //����ʣ�µ�N-1�����
    for(int i=0;i<N-1;i++)
    {
        int Min=INF,u=v;
        for(int j=0;j<N;j++)
        {
            if(!S[j]&&dist[j]<Min)
            {
                u=j;
                Min=dist[j];
            }
        }
        S[u]=1;      //���뼯��S
        //���¾����Լ�·��
        for(int j=0;j<N;j++)
        {
            if(!S[j]&&G[u][j]<INF&&dist[u]+G[u][j]<dist[j])
            {
                dist[j]=dist[u]+G[u][j];
                path[j]=u;
            }
        }
    }
}

int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(i==j)G[i][j]=0;
            else G[i][j]=INF;
    for(;;)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(u<0||v<0||w<0)break;
        G[u][v]=w;
    }
    Dijkstra(0);
    int shortest[MAXN];  //����׷�ٵķ�����ģ��ջ����ջ��ȣ��������ڿ��Բ���Ԫ��
    for(int i=1;i<N;i++)
    {
        printf("%d\t",dist[i]);
        memset(shortest,0,sizeof(shortest));
        int k=0;
        shortest[k]=i;
        while(path[shortest[k]]!=0)
        {
            ++k;
            shortest[k]=path[shortest[k-1]];
        }
        ++k;
        shortest[k]=0;
        for(int j=k;j>0;j--)
            printf("%d->",shortest[j]);
        printf("%d\n",shortest[0]);
    }
    printf("path[]: ");
    for(int i=0;i<N;i++)
        printf("%d ",path[i]);
    printf("\ndist[]:\n");
     for(int i=0;i<N;i++)
        printf("%d ",dist[i]);
    return 0;
}
/*
�������ݣ�
6
0 2 5
0 3 30
1 0 2
1 4 8
2 5 7
2 1 15
4 3 4
5 3 10
5 4 18
-1 -1 -1
*/
