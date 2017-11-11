#include<cstdio>
#include<cstring>
using namespace std;

int indegree[27]; //��������
int G[27][27];    //�ڽӾ�����ɵ�ͼ
int q[27];        //��ռ�

//��������
int Topsort(int n)
{
	int Count = 0;  //��¼��ռ��У����Ϊ0�Ķ������
	int temp[27]; //������ȶ���
	int loc;      //��¼һ��0��ȶ������Ŀ
	int m;        //0��ȶ���ĸ���
	int flag;     //flag=1 ����flag=-1��ȷ��
	memcpy(temp, indegree, sizeof(temp));  //����
	for (int i = 1;i <= n;i++)
	{
		m = 0;
		for (int j = 0;j <= n;j++)  //�������Ϊ0�Ķ���ĸ���
		{
			if (temp[j] == 0)
			{
				m++;
				loc = j;  //��¼0��ȶ����λ��
			}
		}
		if (m == 0)   //�л�
			return 0;
		if (m > 1)  //0��ȵĶ����������1�����ǲ�֪���Ƿ��л������ü��������ж�
		{
			flag = -1;
		}
		q[Count++] = loc;  //0��ȶ������
		temp[loc] = -1;    //0��ȶ�����Ϊ-1
		for (int j = 1;j <= n;j++)
		{
			if (G[loc][j] == 1)
				temp[j]--;   //���ӵ�����-1
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
		if (s == 0)    //�л�
		{
			printf("Inconsistency found after %d relations.\n", i);
			sign = 1;
		}
		if (s == 1)    //����
		{
			printf("Sorted sequence determined after %d relations: ", i);
			for (int j = 0; j < n; j++)
			{
				putchar(q[j] + 'A' - 1); //����ַ� putchar(ASCII)
			}
			printf(".\n");
			sign = 1;
		}
	}
	if (!sign)     //�޷��ó����
	{
		printf("Sorted sequence cannot be determined.\n");
	}
	return 0;
}


