#include<cstdio>
#include<stack>
using namespace std;

const int MAXN = 10;

struct ArcNode
{
	int adjvex;
	struct ArcNode* next;
};

struct VNode
{
	int node;
	int Count;  //�ߵ����
	struct ArcNode* head;
	VNode() { head = nullptr;Count = 0; }
};

struct LGraph
{
	VNode vertex[MAXN];
	int arcNum, verNum;
}LG;

void Create()
{
	scanf("%d%d", &LG.verNum, &LG.arcNum); //�����ĸ����ͱߵĸ���
	int u, v;
	while (scanf("%d%d", &u, &v) && u != 0 && v != 0)
	{
		ArcNode* p = LG.vertex[u].head;
		LG.vertex[u].node = u;
		if (p == nullptr)
		{
		    //ע�������ָ��ʹ�÷�ʽ
			LG.vertex[u].head = new ArcNode;
			LG.vertex[u].head->adjvex = v;
			LG.vertex[u].head->next = nullptr;
		}
		else
		{
			while (p->next != nullptr)
				p = p->next;
			p->next = new ArcNode;
			p = p->next;
			p->adjvex = v;
			p->next = nullptr;
		}
		LG.vertex[v].Count++; //�����������һ��
		LG.vertex[v].node = v;
	}
}

void DeleteGraph()
{
	for (int i = 0;i < LG.verNum;i++)
	{
		ArcNode* p = LG.vertex[i].head;
		while (p != nullptr)
		{
			ArcNode* q = p->next;
			delete p;
			p = q;
		}
	}
	delete[] LG.vertex;
}

void TopSort()
{
	stack<int>sta;
	bool loop = false;
	int n = 0;
	//���Ϊ0�Ķ�����ջ
	for (int i = 1;i <= LG.verNum;i++)
	{
		if (LG.vertex[i].Count == 0)
			sta.push(i);
	}
	while (!sta.empty())
	{
		int j = sta.top();
		sta.pop();
		printf("%d ", LG.vertex[j].node);
		n++;
		ArcNode* p = LG.vertex[j].head;
		while (p != nullptr)
		{
			//�ڽӱߵĶ���-1
			LG.vertex[p->adjvex].Count--;
			//�������Ϊ0����������ջ
			if (LG.vertex[p->adjvex].Count == 0)
				sta.push(LG.vertex[p->adjvex].node);
			p = p->next;
		}
	}
	//����Ķ����������ͼ���ĸ���
	if (n < LG.verNum)
		loop = true;
	if (loop)
		puts("\nNetwork has loop");
}

int main()
{
	Create();
	TopSort();
	DeleteGraph();
	return 0;
}
/*
��������1����ͨ����
6 8
1 2
1 4
2 6
3 2
3 6
5 1
5 2
5 6
6 8
1 3
1 2
2 5
3 4
4 2
4 6
5 4
5 6
0 0
��������2��ͨ����
6 8
1 2
1 4
2 6
3 2
3 6
5 1
5 2
5 6
0 0
*/
