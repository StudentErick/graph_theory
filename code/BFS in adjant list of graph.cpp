#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;

const int MAXN=100;
//标记数组，用于标记结点是否被访问过
int visit[MAXN];

struct ArcNode
{
    int adjvex;            //存储当前结点数据
    struct ArcNode* next;  //存储链接指针
};

struct VNode
{
    int data;       //存储顶点数据
    ArcNode *head;  //存储邻接表数据
};


struct LGraph
{
    VNode vertex[MAXN];//首结点
    int verNum,arcNum; //顶点和边的数量
};

LGraph LG;

//建立邻接表
void Create()
{
    for(int i=0;i<LG.verNum;i++)
    {
        LG.vertex[i].data=i;
        LG.vertex[i].head=nullptr;
    }
    for(int i=0;i<LG.arcNum;i++)
    {
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        auto p=LG.vertex[v1].head;
        if(p==nullptr)
        {
            //这里不能直接使用p进行开辟结点，因为都是空结点没法直接赋值
            LG.vertex[v1].head=new ArcNode;
            LG.vertex[v1].head->adjvex=v2;
            LG.vertex[v1].head->next=nullptr;
        }
        else
        {
            while(p->next!=nullptr)p=p->next;
            p->next=new ArcNode;
            p=p->next;
            p->adjvex=v2;
            p->next=nullptr;
        }
    }
}

//删除邻接表
void DeleteGraph()
{
    for(int i=0;i<LG.verNum;i++)
    {
        auto p=LG.vertex[i].head;
        while(p!=nullptr)
        {
            auto q=p->next;
            delete p;
            p=q;
        }
    }
}

//从结点n开始宽度优先搜索
void BFS(int n)
{
    queue<int>que;
    que.push(n);
    while(!que.empty())
    {
        int v1=que.front();
        visit[v1]=1;
        que.pop();
        printf("%d ",v1);
        auto p=LG.vertex[v1].head;
        while(p!=nullptr)
        {
            if(!visit[p->adjvex])
            {
                visit[p->adjvex]=1;
                que.push(p->adjvex);
            }
            p=p->next;
        }
    }
}

int main()
{
    scanf("%d%d",&LG.verNum,&LG.arcNum); //输入结点和边的数量
    Create();
    BFS(0);
    DeleteGraph();
    return 0;
}
