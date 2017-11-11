#include<cstdio>
#include<queue>
using namespace std;

const int MAXN=101;
int T;
int nr;  //公交路线的数目
struct ArcNode
{
    int adjvex;
    struct ArcNode* next;
};

struct VNode
{
    int data;
    ArcNode* head;
};

struct LGraph
{
    VNode vertex[MAXN];
    int arcNum,verNum;
};

LGraph LG;

//链表存储图的结构
void Create()
{
    LG.arcNum=0;
    scanf("%d",&LG.verNum);  //站点的数目
    scanf("%d",&nr);         //公交路线的数目
    for(int i=0;i<LG.verNum;i++)
    {
        int mr;
        scanf("%d",&mr);
        for(int j=1;j<=mr;j++)
        {
            ArcNode* p=new ArcNode;
            int v;
            scanf("%d",&v);
            p->adjvex=v;
            p->next=nullptr;
            //处理头结点的情况
            if(i==1)
            {
                LG.vertex[i].head=p;
            }
            else
            {
                ArcNode* q=head;
                while(q->next!=nullptr)q=q->next;
                p=q->next;
            }
            LG.arcNum++;  //路线的数目增加
        }
    }
}

//宽度优先搜索，搜寻最远的距离
int BFS(int n)
{
    int dis=0; //结点n到所有站点中最远的距离
    queue<int>que;
    que.push(n);
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        ArcNode* p=LG.verNum[n].head;
    }
    return dis;
}

int main()
{
    return 0;
}
