#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 101;
const int MAXM = 10000;
int parent[MAXN];
bool first;
int N, M;
struct Edge
{
	int u, v, w;
	int used;    //第一次是否使用过
	int del;     //是否被删除
	int equ;     //是否有相等边的标记
}edge[MAXM];

void UFset()
{
	memset(parent, -1, sizeof(parent));
}

int Find(int x)
{
	int s;
	for (s = x;parent[s] >= 0;s = parent[s]);
	while (s != x)
	{
		int tmp = parent[x];
		parent[x] = s;
		x = tmp;
	}
	return s;
}

void Union(int x, int y)
{
	int r1 = Find(x), r2 = Find(y);
	int sum = parent[r1] + parent[r2];
	if (parent[r1] < parent[r2])
	{
		parent[r1] = sum;
		parent[r2] = r1;
	}
	else
	{
		parent[r2] = sum;
		parent[r1] = r2;
	}
}

int Kruskal()
{
	int sumWidget = 0;
	int num = 0;
	UFset();
	for (int i = 0;i < M;i++)
	{
		if (Find(edge[i].u) != Find(edge[i].v) && !edge[i].del)
		{
			Union(edge[i].u, edge[i].v);
			num++;
			sumWidget += edge[i].w;
			if (first)edge[i].used = 1;
		}
		if (num >= N - 1)
			break;
	}
	return sumWidget;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &N, &M);
		//输入并且初始化
		for (int i = 0;i < M;i++)
		{
			scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
			edge[i].equ = edge[i].used = edge[i].del = 0;
		}
		for (int i = 0;i < M - 1;i++)
		{
			if (edge[i].equ == 1)continue;
			for (int j = i + 1;j < M;j++)
			{
				if (edge[i].w == edge[j].w)
					edge[i].equ = edge[j].equ = 1;
			}
		}
		first = true;
		int w1 = Kruskal(), w2;
		first = false;
		int i;
		for (i = 0;i < M;i++)
		{
			if (edge[i].used&&edge[i].equ)
			{
				edge[i].del = 1;
				w2 = Kruskal();
				if (w2 == w1)
				{
					printf("Not Unique!\n");
					break;
				}
				edge[i].del = 0;
			}
		}
		if (i >= M)
			printf("%d\n", w1);
	}
	return 0;
}
