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
	int Count;  //边的入度
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
	scanf("%d%d", &LG.verNum, &LG.arcNum); //输入点的个数和边的个数
	int u, v;
	while (scanf("%d%d", &u, &v) && u != 0 && v != 0)
	{
		ArcNode* p = LG.vertex[u].head;
		LG.vertex[u].node = u;
		if (p == nullptr)
		{
		    //注意这里的指针使用方式
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
		LG.vertex[v].Count++; //顶点度数增加一个
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
	//入度为0的顶点入栈
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
			//邻接边的度数-1
			LG.vertex[p->adjvex].Count--;
			//如果度数为0，则重新入栈
			if (LG.vertex[p->adjvex].Count == 0)
				sta.push(LG.vertex[p->adjvex].node);
			p = p->next;
		}
	}
	//输出的顶点个数少于图结点的个数
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
测试数据1，不通过：
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
测试数据2，通过：
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
