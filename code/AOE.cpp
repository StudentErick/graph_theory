#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

const int MAXN=1000;   //最大结点数
const int INF=1000000;

//事件最早开始、最晚开始的时间
int ve[MAXN],vl[MAXN];
//活动最早开始、最晚开始的时间
int e[MAXN],l[MAXN];

struct ArcNode
{
    int adjvex;             //邻接点
    int widget;             //边的权重
    int edge;               //边的标号
    struct ArcNode* next;   //邻接边指针
    ArcNode(){adjvex=0;widget=0;next=nullptr;}
};

struct VNode
{
    int node;                 //首结点
    int CountIn,CountOut;     //入度，出度
    ArcNode *headIn,*headOut; //入边头结点，出边头结点
    VNode(){node=0;CountIn=CountOut=-1;headIn=headOut=nullptr;}
};

struct LGraph
{
    VNode vertex[MAXN];   //结点数组
    int arcNum,verNum;    //边的数目、结点的数目
};

LGraph LG;

/*Create函数根据输入，一次性处理完入边和出边的关系，
两者的操作正好相反，就是u、v标号的区别*/
void Create()
{
    memset(ve,0,sizeof(ve));
    memset(vl,0,sizeof(vl));
    memset(e,0,sizeof(e));
    memset(l,0,sizeof(l));
    scanf("%d%d",&LG.verNum,&LG.arcNum);
    int u,v,widget,edge;
    for(int i=0;i<LG.arcNum;i++)
    {
        scanf("%d%d%d%d",&u,&edge,&widget,&v);
        LG.verNum=u;//////////////////////////////
        ArcNode* p=LG.vertex[u].headOut;
        //处理入边的
        if(p==nullptr)
        {
            LG.vertex[u].CountOut++;
            p=LG.vertex[u].headOut=new ArcNode;
            p->widget=widget;
            p->edge=edge;
            p->adjvex=v;
            p->next=nullptr;
        }
        else
        {
            while(p->next!=nullptr)
                p=p->next;
            LG.vertex[u].CountOut++;
            p->next=new ArcNode;
            p->adjvex=v;
            p->edge=edge;
            p->widget=widget;
            p->next=nullptr;
        }

        //处理出边的，如入边正好相反
        LG.vertex[v].CountIn++;  //顶点的入度增加1
        p=LG.vertex[v].headIn;
        if(p==nullptr)
        {
            p=LG.vertex[v].headIn=new ArcNode;
            p->adjvex=u;
            p->widget=widget;
            p->edge=edge;
            p->next=nullptr;
        }
        else
        {
            while(p->next!=nullptr)
                p=p->next;
            p->next=new ArcNode;
            p=p->next;
            p->adjvex=u;
            p->edge;
            p->widget=widget;
            p->next=nullptr;
        }
    }
}

void DeleteGraph()
{
    for(int i=0;i<LG.verNum;i++)
    {
        //删除入边
        ArcNode* p=LG.vertex[i].headIn;
        while(p!=nullptr)
        {
            ArcNode* q=p->next;
            delete p;
            p=q;
        }
        //删除出边
        p=LG.vertex[i].headOut;
        while(p!=nullptr)
        {
            ArcNode* q=p->next;
            delete p;
            p=q;
        }
        //度数和指针清零
        LG.vertex[i].CountIn=LG.vertex[i].CountOut=-1;
        LG.vertex[i].headIn=LG.vertex[i].headOut=nullptr;
    }
    LG.verNum=LG.arcNum=0;
}

void AOE()
{
    int s=0;
    //寻找源点，只有源点的入度是0
    for(int i=0;i<LG.verNum;i++)
    {
        if(LG.vertex[i].CountIn==0)
        {
            s=i;
            break;
        }
    }
    stack<int>sta;
    sta.push(s);
    int res=0;
    //在拓扑排序的过程中，完成ve的统计
    while(!sta.empty())
    {
        int j=sta.top();
        sta.pop();
        ArcNode* p=LG.vertex[j].headOut;
        res++;
        while(p!=nullptr)
        {
            //正好是一个求逆的过程，完成ve的赋值
            ArcNode* q=LG.vertex[p->adjvex].headIn;
            while(q!=nullptr)
            {
                if(ve[q->adjvex]+q->widget>ve[p->adjvex])
                    ve[p->adjvex]=ve[q->adjvex]+q->widget;
                q=q->next;
            }
            if((--LG.vertex[p->adjvex].CountIn)==0)
                sta.push(p->adjvex);
            p=p->next;
        }
    }
    //有环
    if(res<LG.verNum)
    {
        printf("Network has loop!\n");
        return;
    }

    vl[LG.verNum-1]=ve[LG.verNum-1];
    //逆拓扑排序，求解vl，与求解ve的方向正好相反
    for(int i=9;i<LG.verNum;i++)
    {
        if(LG.vertex[i].CountOut==0)
        {
            s=i;
            break;
        }
    }
    sta.push(s);
    while(!sta.empty())
    {
        int j=sta.top();
        sta.pop();
        ArcNode* p=LG.vertex[j].headIn;
        while(p!=nullptr)
        {
            ArcNode* q=LG.vertex[p->adjvex].headOut;
            while(q!=nullptr)
            {
                ArcNode* r=LG.vertex[q->adjvex].headOut;
                while(r!=nullptr)
                {
                    if(vl[r->adjvex]+r->widget<vl[q->adjvex])
                        vl[q->adjvex]=vl[r->adjvex]+r->widget;
                    r=r->next;
                }
                q=q->next;
            }
            if((--LG.vertex[p->adjvex].CountIn)==0)
                sta.push(p->adjvex);
            p=p->next;
        }
    }

}

int main()
{
    return 0;
}
    Create();  //建立邻接表存储图的结构
    AOE();
    for(int i=0;i<LG.verNum;i++)
    {
        ArcNode* p=LG.vertex[i].headOut;
        while(p!=nullptr)
        {
            if(e[p->widget]==l[p->widget])
                printf("%d ",p->edge);
            p=p->next;
        }
    }
    printf("\n");
    DeleteGraph();
    return 0;
}
/*
9 11
0 1 6 1
0 2 4 2
0 3 5 3
1 4 1 4
2 5 1 4
3 6 2 5
4 7 9 6
4 8 7 7
5 9 4 7
6 10 2 8
7 11 4 8
*/
