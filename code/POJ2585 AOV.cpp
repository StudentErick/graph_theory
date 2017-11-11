#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

const char start[]="START";
const char End[]="END";
const char endofinput[]="ENDOFINPUT";

int Screen[16];  //屏幕的存储
int Cover[16][3]={{1,-1,-1},{1,2,-1},{2,3,-1},{3,-1,-1},
                {1,4,-1},{1,2,4},{2,3,5},{3,6,-1},
                {4,7,-1},{4,5,7},{5,6,8},{6,9,-1},
                {7,-1,-1},{7,8,-1},{8,9,-1},{9,-1,-1}};

struct ArcNode
{
    int adjvex;
    struct ArcNode* next;
    ArcNode(){next=NULL;}
};

struct VNode
{
    int node;
    int Count;  //结点的入度
    ArcNode* head;
    VNode(){head=NULL;Count=0;}
};

struct LGraph
{
    VNode vertex[10];
    int verNum,arcNum;
};

struct LGraph LG;

void Create()  //建立出边表图
{
    for(int i=1;i<=9;i++)
    {
        LG.vertex[i].node=Screen[i-1];
        for(int j=0;j<3;j++)
        {
            if(Cover[i-1][j]!=-1&&Cover[i-1][j]!=Screen[i-1])
            {
                ArcNode* p=NULL;
                if(LG.vertex[i].head==NULL)
                {
                    p=LG.vertex[i].head=new ArcNode;
                    p->adjvex=Cover[i-1][j];
                    p->next=NULL;
                    LG.vertex[p->adjvex].Count++;  //入度增加1
                }
                else
                {
                    p=LG.vertex[i].head;
                    while(p->next!=NULL)
                        p=p->next;
                    p->next=new ArcNode;
                    p=p->next;
                    p->adjvex=Cover[i-1][j];
                    p->next=NULL;
                    LG.vertex[p->adjvex].Count++;  //入度增加1
                }
            }
        }
    }
}

bool AOV()  //拓扑排序，是否有环
{
    int res=0;
    stack<int>sta;
    int m=0;
    //在最上面的屏幕，入度肯定是0
    for(int i=1;i<=9;i++)
    {
        if(LG.vertex[i].Count==0)
        {
            sta.push(i);
        }
    }
    while(!sta.empty())
    {
        int j=sta.top();
        sta.pop();
        res++;
        ArcNode* p=LG.vertex[j].head;
        while(p!=NULL)
        {
            LG.vertex[p->adjvex].Count--;   //入度减1
            if(LG.vertex[p->adjvex].Count==0)
            {
                sta.push(p->adjvex);   //度数为0的结点入栈
            }
            p=p->next;
        }
    }
    if(res<16)
        return false;
    return true;
}

void DeleteGraph()
{
    for(int i=0;i<9;i++)
    {
        ArcNode* p=LG.vertex[i].head;
        while(p!=NULL)
        {
            ArcNode* q=p->next;
            delete p;
            p=q;
        }
        LG.vertex[i].head=NULL;
    }
}

int main()
{
    char START[11];
    char END[11];
    char ENDOFINPUT[11];
    memcpy(START,start,sizeof(start));
    memcpy(END,End,sizeof(End));
    memcpy(ENDOFINPUT,endofinput,sizeof(endofinput));
    char input[11],output[11];
    while(scanf("%s",input)&&strcmp(input,START)==0)
    {
        for(int i=0;i<16;i++)  //读取屏幕数据
            scanf("%d",&Screen[i]);
        scanf("%s",END);
        Create();
        if(AOV())
            puts("THEASE WINDOW ARE CLEARN");
        else
            puts("THESE WINDOW ARE BROKEN");
        DeleteGraph();
    }
    return 0;
}
