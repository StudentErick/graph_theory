#include<cstdio>
#include<cstring>
const int INF=1000000;
const int MAXN=100;
int N,G[MAXN][MAXN],A[MAXN][MAXN],path[MAXN][MAXN];  //path[i][j]��ʾ���i�����j��·���ϣ�����jǰһ������ľ��룻A�Ǿ���������飬G��ͼ�Ĵ洢�ṹ
void Floyd(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            A[i][j]=G[i][j];
            if(i!=j&&G[i][j]<INF)path[i][j]=i;
            else path[i][j]=-1;
        }
    }
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==k||j==k)continue; //�����Լ����ɻ�
                if(A[i][j]>A[i][k]+A[k][j]){
                    A[i][j]=A[i][k]+A[k][j];
                    path[i][j]=path[k][j];
                }
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
    int u,v,w;
    while(scanf("%d%d%d",&u,&v,&w)&&u>=0&&v>=0)
        G[u][v]=w;
    Floyd();
    printf("Dis\tLen\tPath\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j)continue;
            printf("%d->%d\t%d\t",i,j,A[i][j]);  //���ݽ��֮��ľ���
            int shortest[MAXN];
            memset(shortest,0,sizeof(shortest));
            int k=0;
            shortest[k]=j;
            while(path[i][shortest[k]]!=i)
                shortest[++k]=path[i][shortest[k-1]];
            shortest[++k]=i;
            for(int t=k;t>0;t--)
                printf("%d->",shortest[t]);
            printf("%d\n",shortest[0]);
        }
    }
    return 0;
}
/*
4
0 1 1
0 3 4
1 2 9
1 3 2
2 0 3
2 1 5
2 3 8
3 2 6
-1 -1 -1
*/
