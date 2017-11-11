#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

const int N=100;
int n;  //number of vertex
int Edge[N][N];
int visit[N];

void dfs(int i)
{
    visit[i]=1;
    printf("%d ",i);
    for(int j=0;j<n;j++)
    {
        if(Edge[i][j]&&!visit[j])
            dfs(j);
    }
}

int main()
{
    scanf("%d",&n);
    memset(Edge,0,sizeof(Edge));
    memset(visit,0,sizeof(visit));
    //input edge information
    for(int i=0;i<n;i++)
    {
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        Edge[v1][v2]=Edge[v2][v1]=1;
    }
    dfs(0);
    return 0;
}
