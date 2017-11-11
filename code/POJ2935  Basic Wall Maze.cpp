#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;

const int MAXN = 8;
int Maze[MAXN][MAXN];
int visit[MAXN][MAXN];
int Wall[MAXN][MAXN];
int offset[4][2] = { -1,0,0,-1,1,0,0,1 };
struct Pos
{
	int x, y;
};

void BFS(int sx, int sy, int ex, int ey)
{
	Pos p, q;
	p.x = sx, p.y = sy;
	q = p;
	queue<Pos>que;
	que.push(p);
	while (!que.empty() && (q.x != ex&&q.y != ey))
	{
		p = que.front();
		que.pop();
		for (int k = 0;k < 4;k++)
		{
			int x = p.x + offset[k][0];
			int y = p.y + offset[k][0];
			//访问过或者由围墙没法过去
			if (visit[x][y] || (k == 0 && Wall[p.x - 1][p.y]) || (k == 1 && Wall[p.x][p.y - 1]) || (k == 2 && Wall[p.x][p.y]) || (k == 3 && Wall[p.x][p.y]))
				continue;
			visit[x][y] = 1;;
			//距离增加一个
			Maze[x][y] = Maze[p.x][p.y] + 1;
			q.x = x;
			q.y = y;
			que.push(q);
		}
	}
	for(int i=1;i<=6;i++)
    {
        for(int j=1;j<=6;j++)
            printf("%d ",Maze[i][j]);
        puts("");
    }
	stack<Pos>sta;
	p.x = ex;
	p.y = ey;
	sta.push(p);
	while (p.x != sx&&p.y != sy)
	{
		for (int i = 0;i < 4;i++)
		{
			int x = p.x + offset[i][0];
			int y = p.y + offset[i][1];
			if (Maze[x][y] == Maze[p.x][p.y] - 1 && Maze[x][y] != 0)
			{
				Pos q;
				q.x = x;q.y = y;
				sta.push(q);
				q.x = x;q.y = y;
				break;
			}
		}
	}
	p.x = sx;p.y = sy;
	while (!sta.empty())
	{
		q = sta.top();
		sta.pop();
		if (p.x < q.x)
			printf("S");
		else if (p.x > q.x)
			printf("N");
		else if (p.y < q.y)
			printf("E");
		else
			printf("W");
		p = q;
	}
}

int main()
{
	memset(Wall, 0, sizeof(Wall));
	memset(visit, 0, sizeof(visit));
	memset(Maze, 0, sizeof(Maze));
	int SX, SY, EX, EY;
	//注意题目条件，行与列是相反的输入的
	while (scanf("%d%d", &SX, &SY) && SX != 0 && SY != 0)
	{
		scanf("%d%d", &EX, &EY);
		Maze[SX][SY] = 0;
		visit[SX][SY] = 1;
		int w1, w2, w3, w4;
		//设置围墙
		for (int i = 0;i < 3;i++)
		{
			scanf("%d%d%d%d", &w2, &w1, &w4, &w3);
			if (w1 == w3)
			{
				for (int i = w2;i <= w4;i++)
					Wall[w1][i] = Wall[w3][i] = 1;
			}
			else
			{
				for (int i = w1;i <= w3;i++)
					Wall[i][w2] = Wall[i][w4] = 1;
			}
		}
		BFS(SX, SY, EX, EY);
	}
	return 0;
}
