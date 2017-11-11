#include<cstdio>
#include<queue>
using namespace std;

const int MAXN=101;
int T;
int nr;  //����·�ߵ���Ŀ
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

//����洢ͼ�Ľṹ
void Create()
{
    LG.arcNum=0;
    scanf("%d",&LG.verNum);  //վ�����Ŀ
    scanf("%d",&nr);         //����·�ߵ���Ŀ
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
            //����ͷ�������
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
            LG.arcNum++;  //·�ߵ���Ŀ����
        }
    }
}

//���������������Ѱ��Զ�ľ���
int BFS(int n)
{
    int dis=0; //���n������վ������Զ�ľ���
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
