#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

const int MAXN=100;
int visit[MAXN];

struct ArcNode
{
    int adjvex;
    struct ArcNode* nextArc;
    ArcNode(){nextArc=nullptr;}
};

struct VNode
{
    int data;
    ArcNode* head;
    VNode(){head=nullptr;}
};

struct LGraph
{
    VNode vertex[MAXN];
    int arcNum,verNum;
};

LGraph LG;

//create link list to store graph
void Create()
{
    scanf("%d%d",&LG.arcNum,&LG.verNum);
    int n=LG.arcNum;
    for(int i=0;i<n;i++)
    {
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        LG.vertex[v1].data=v1;
        if(LG.vertex[v1].head==nullptr)
        {
            ArcNode* p=LG.vertex[v1].head=new ArcNode;
            p->adjvex=v2;
            p->nextArc=nullptr;
        }
        else
        {
            ArcNode* p=LG.vertex[v1].head;
            while(p->nextArc!=nullptr)p=p->nextArc;
            p->nextArc=new ArcNode;
            p=p->nextArc;
            p->adjvex=v2;
            p->nextArc=nullptr;
        }
    }
}

//delete graph list
void DeleteGraph()
{
    for(int i=0;i<LG.verNum;i++)
    {
        ArcNode* p=LG.vertex[i].head;
        if(p==nullptr)continue;
        ArcNode* q=p->nextArc;
        delete p;
        while(q!=nullptr)
        {
            p=q;
            q=q->nextArc;
            delete p;
        }
    }
}

//depth first search
void DFS(int i)
{
    printf("%d ",i);
    visit[i]=1;
    ArcNode* p=LG.vertex[i].head;
    while(p!=nullptr)
    {
        int j=p->adjvex;
        if(!visit[j])
        {
            DFS(j);
        }
        p=p->nextArc;
    }
}

int main()
{
    memset(visit,0,sizeof(visit));
    //create link list to store graph
    Create();
    DFS(0);
    DeleteGraph();
    return 0;
}
