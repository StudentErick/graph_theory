#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int Board[10][10];
int offset[8][2] = { { -2,-1 },{ -2,1 },{ -1,2 },{ -1,-2 },{ 1,-2 },{ 1,2 },{ 2,-1 },{ 2,1 } };  //8个偏移方向
int visit[10][10];
int step = 0;
struct pos
{
	int x, y;
	int step;
};
int BFS(int sx, int sy, int ex, int ey)
{
	queue<pos>que;
	struct pos p, q;
	p.step = 0;
	q.step = 0;
	p.x = sx;p.y = sy;
	que.push(p);
	memset(visit, 0, sizeof(visit));
	while (!que.empty())
	{
		p = que.front();
		que.pop();
		int x, y;
		for (int k = 0;k < 8;k++)
		{
			q.x = p.x + offset[k][0];
			q.y = p.y + offset[k][1];
			q.step = p.step + 1;
			if (q.x < 1 || q.x>8 || q.y < 1 || q.y>8 || visit[q.x][q.y])continue;
			visit[q.x][q.y] = 1;  //标记为访问过的
			if (q.x == ex&&q.y == ey)
			{
				goto loop;
			}
			que.push(q);
		}
	}
loop:return q.step;
}

int main()
{
	char p1, p3;
	char p2, p4;
	while (scanf("%c%c %c%c", &p1, &p2, &p3, &p4) != EOF)
	{
		char c;
		scanf("%c", &c);  //读取行尾部的换行符
		int sx, sy, ex, ey;
		sx = p1 - 'a' + 1;
		sy = p2 - '1' + 1;
		ex = p3 - 'a' + 1;
		ey = p4 - '1' + 1;
		if (p1 == p3&&p2 == p4)
			printf("To get from %c%c to %c%c takes 0 knight moves.\n", p1, p2, p3, p4);
		else
			printf("To get from %c%c to %c%c takes %d knight moves.\n", p1, p2, p3, p4, BFS(sx, sy, ex, ey));
	}
	return 0;
}
