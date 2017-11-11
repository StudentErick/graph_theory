#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN=20;
int W,H;
char Maze[MAXN][MAXN];
int visit[MAXN][MAXN];
int count[MAXN][MAXN];
int res=0;
//�ĸ��ƶ�����
int offset[4][2]={0,-1,0,1,1,0,-1,0};

void DFS(int x,int y)
{
	if(x<0||x>H||y<0||y>W||visit[x][y])
		return;
	//����Ҫͳ�Ƶĵ㣬����֮ǰû�н��й�ͳ��
	if(Maze[x][y]=='.'&&!count[x][y])
	{
		count[x][y]=1;  //���Ϊͳ�ƹ���
		res++;
	}
	int i=x,j=y;
	//���Ϊ���ʹ���
	visit[x][y]=1;
	for(int k=0;k<4;k++)
	{
		i=x+offset[k][0];
		j=y+offset[k][1];
		if(Maze[i][j]=='.')
			DFS(i,j);
		i=x;j=y;
	}
	//ȡ�����
	visit[x][y]=0;
}

int main()
{
	int i,j;
	char c;
	while(scanf("%d%d\n",&W,&H)&&W!=0)
	{
		memset(Maze,0,sizeof(Maze));
		memset(visit,0,sizeof(visit));
		memset(count,0,sizeof(count));
		for(i=0;i<H;i++)
		{
			for(j=0;j<W;j++)
			{
				scanf("%c",&Maze[i][j]);
			}
			scanf("%c",&c);
		}
		for(i=0;i<W;i++)
		{
			for(j=0;j<H;j++)
			{
				if(Maze[i][j]=='@')
				{
					DFS(i,j);
					visit[i][j]=1;
					goto loop1;
				}
			}
		}
		loop1:printf("%d\n",res);
		res=0;
	}
	return 0;
}