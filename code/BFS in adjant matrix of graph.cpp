#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN=100;

//�ڽӾ���
int Edge[MAXN][MAXN];
//������飬�����жϱ��Ƿ񱻷��ʹ�
int visit[MAXN];
//ʵ�ʱߵĸ���
int arcNum;

//n�����1��Ҫ���ʵĽ��
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
                //��û�з��ʹ����ڱ߼������
                que.push(j);
                //������ʶ��о͵ȼ��ڷ��ʹ��Ľ��
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
