#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;

const int MAXN=100;
//������飬���ڱ�ǽ���Ƿ񱻷��ʹ�
int visit[MAXN];

struct ArcNode
{
    int adjvex;            //�洢��ǰ�������
    struct ArcNode* next;  //�洢����ָ��
};

struct VNode
{
    int data;       //�洢��������
    ArcNode *head;  //�洢�ڽӱ�����
};


struct LGraph
{
    VNode vertex[MAXN];//�׽��
    int verNum,arcNum; //����ͱߵ�����
};

LGraph LG;

//�����ڽӱ�
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
            //���ﲻ��ֱ��ʹ��p���п��ٽ�㣬��Ϊ���ǿս��û��ֱ�Ӹ�ֵ
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

//ɾ���ڽӱ�
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

//�ӽ��n��ʼ�����������
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
    scanf("%d%d",&LG.verNum,&LG.arcNum); //������ͱߵ�����
    Create();
    BFS(0);
    DeleteGraph();
    return 0;
}
