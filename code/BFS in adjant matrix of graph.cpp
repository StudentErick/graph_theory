#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN=100;

//邻接矩阵
int Edge[MAXN][MAXN];
//标记数组，用于判断边是否被访问过
int visit[MAXN];
//实际边的个数
int arcNum;

//n代表第1个要访问的结点
void BFS(int n)
{
    queue<int>que;
    que.push(n);
    while(!que.empty())
    {
        int v=que.front();
        printf("%d ",v);
        visit[v]=1;
        que.pop();
        for(int j=0;j<arcNum;j++)
        {
            if(Edge[v][j]&&!visit[j])
            {
                //把没有访问过的邻边加入队列
                que.push(j);
                //加入访问队列就等价于访问过的结点
                visit[j]=1;
            }
        }
    }
}

int main()
{
    memset(Edge,0,sizeof(Edge));
    memset(visit,0,sizeof(visit));
    scanf("%d",&arcNum);
    for(int i=0;i<arcNum;i++)
    {
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        Edge[v1][v2]=Edge[v2][v1]=1;
    }
    BFS(0);
	return 0;
}
