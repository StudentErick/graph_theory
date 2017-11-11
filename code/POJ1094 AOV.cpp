#include<cstdio>
#include<cstring>
using namespace std;

int indegree[27]; //顶点的入度
int G[27][27];    //邻接矩阵组成的图
int q[27];        //解空间

//拓扑排序
int Topsort(int n)
{
	int Count = 0;  //记录解空间中，入度为0的顶点个数
	int temp[27]; //备份入度顶点
	int loc;      //记录一个0入度顶点的数目
	int m;        //0入度顶点的个数
	int flag;     //flag=1 有序，flag=-1不确定
	memcpy(temp, indegree, sizeof(temp));  //备份
	for (int i = 1;i <= n;i++)
	{
		m = 0;
		for (int j = 0;j <= n;j++)  //查找入度为0的顶点的个数
		{
			if (temp[j] == 0)
			{
				m++;
				loc = j;  //记录0入度顶点的位置
			}
		}
		if (m == 0)   //有环
			return 0;
		if (m > 1)  //0入度的顶点个数大于1，但是不知道是否有环，还得继续向下判断
		{
			flag = -1;
		}
		q[Count++] = loc;  //0入度顶点入队
		temp[loc] = -1;    //0入度顶点置为-1
		for (int j = 1;j <= n;j++)
		{
			if (G[loc][j] == 1)
				temp[j]--;   //连接点的入度-1
		}
	}
	return flag;
}

int main()
{
	int n, m;
	int sign;
	char str[5];
	while (scanf("%d%d", &n, &m) && m&&n)
	{
		memset(G, 0, sizeof(G));
		memset(indegree, 0, sizeof(indegree));
		sign = 0;
		scanf("%s", str);
		int u = str[0] - 'A' + 1;
		int v = str[1] - 'A' + 1;
		G[u][v] = 1;
		indegree[v]++;
		int s = Topsort(n);
		if (s == 0)    //有环
		{
			printf("Inconsistency found after %d relations.\n", i);
			sign = 1;
		}
		if (s == 1)    //有序
		{
			printf("Sorted sequence determined after %d relations: ", i);
			for (int j = 0; j < n; j++)
			{
				putchar(q[j] + 'A' - 1); //输出字符 putchar(ASCII)
			}
			printf(".\n");
			sign = 1;
		}
	}
	if (!sign)     //无法得出结果
	{
		printf("Sorted sequence cannot be determined.\n");
	}
	return 0;
}


