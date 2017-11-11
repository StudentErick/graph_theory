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
//四个移动方向
int offset[4][2]={0,-1,0,1,1,0,-1,0};

void DFS(int x,int y)
{
	if(x<0||x>H||y<0||y>W||visit[x][y])
		return;
	//是需要统计的点，而且之前没有进行过统计
	if(Maze[x][y]=='.'&&!count[x][y])
	{
		count[x][y]=1;  //标记为统计过的
		res++;
	}
	int i=x,j=y;
	//标记为访问过的
	visit[x][y]=1;
	for(int k=0;k<4;k++)
	{
		i=x+offset[k][0];
		j=y+offset[k][1];
		if(Maze[i][j]=='.')
			DFS(i,j);
		i=x;j=y;
	}
	//取消标记
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