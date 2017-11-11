#include<cstdio>
#include<cstring>

const int MAXN = 2001;
const int INF = 100000;
int N;
int lowcost[MAXN], nearvex[MAXN];
int G[MAXN][MAXN];
char name[MAXN][7];  //车编号

void Prim(int u)
{
	int sumWidget = 0;
	for (int i = 0;i < N;i++)
	{
		lowcost[i] = G[u][i];
		nearvex[i] = u;
	}
	nearvex[u] = -1;
	for (int i = 0;i < N - 1;i++)
	{
		int Min = INF;
		int v = -1;
		//选择最小边
		for (int j = 0;j < N;j++)
		{
			if (nearvex[j] != -1 && lowcost[j] < Min)
			{
				Min = lowcost[j];
				v = j;
			}
		}
		if (v != -1)
		{
			sumWidget += lowcost[v];
			nearvex[v] = -1;
			//更新数组
			for (int j = 0;j < N;j++)
			{
				if (nearvex[j] != -1 && lowcost[j] > G[v][j])
				{
				    lowcost[j] = G[v][j];
					nearvex[j] = v;
				}
			}
		}
	}
	printf("The highest possible quality is 1/%d.\n", sumWidget);
}

int main()
{
	while (scanf("%d", &N) && N)
	{
		for (int i = 0;i < N;i++)
		{
			scanf("%s", name[i]);
		}
		for (int i = 0;i < N;i++)
			for (int j = 0;j < N;j++)
				if (i != j)G[i][j] = INF;
				else G[i][j] = 0;
        //计算结点的距离
		for (int i = 0;i < N - 1;i++)
		{
			for (int j = i + 1;j < N;j++)
			{
				int d = 0;
				for (int k = 0;k < 7;k++)
				{
					if (name[i][k] != name[j][k])  //找不同的字母个数
						++d;
				}
				G[i][j] = G[j][i] = d;
			}
		}
		Prim(0);
	}
	return 0;
}

/*
4
aaaaaaa
baaaaaa
abaaaaa
aabaaaa
0
*/
