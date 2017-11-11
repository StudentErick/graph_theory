#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

const int MAXN = 27;
const int MAXM = 1000;
int parent[MAXN];

int N, M;

struct Edge
{
	int u, v, w;
}edge[MAXN];

int cmp(const Edge &a, const Edge &b)
{
	return a.w < b.w;
}

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
	int r1 = Find(x);
	int r2 = Find(y);
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

void Kruskal()
{
	UFset();
	int num = 0;
	int sumWidget = 0;
	sort(edge, edge + M, cmp);
	for (int i = 0;i < M;i++)
	{
		if (Find(edge[i].u) != Find(edge[i].v))
		{
			num++;
			Union(edge[i].u, edge[i].v);
			sumWidget += edge[i].w;
		}
		if (num > N - 1)
			break;
	}
	printf("%d\n", sumWidget);
}

int main()
{
	while (scanf("%d", &N))
	{
		getchar();
		memset(edge, 0, sizeof(edge));
		if (N == 0)break;
		M = 0;
		int k = 0;
		for (int l = 0;l < N - 1;l++)
		{
			char u;
			int n;
			scanf("%c %d", &u, &n);
			getchar();
			M += n;
			for (int i = 0;i < n;i++)
			{
				char c;
				int d;
				edge[k].u = u - 'A';
				scanf("%c %d", &c, &d);
				getchar();
				edge[k].v = c - 'A';
				edge[k].w = d;
				k++;
			}
		}
		Kruskal();
	}
	system("pause");
	return 0;
}
/*
input
9
A 2 B 12 I 25
B 3 C 10 H 40 I 8
C 2 D 18 G 55
D 1 E 44
E 2 F 60 G 38
F 0
G 1 H 35
H 1 I 35
3
A 2 B 10 C 40
B 1 C 20
0
output
216
30
*/
