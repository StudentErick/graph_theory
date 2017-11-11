#include<cstdio>

#define MAXN 100

//边结点
struct ArcNode
{
    int adjvex;  //有向边的另一个邻接点的序号
    struct ArcNode* nextArc;  //指向下一边结点的指针
};

//顶点
struct VNode
{
    int data;  //顶点信息
    ArcNode* headOut;  //出边表的表头指针
    ArcNode* headIn;   //入边表的表头指针
};

//图的邻接表的存储结构
struct LGraph
{
    VNode vertex[MAXN];   //顶点数组
    int vexNum,arcNum;    //顶点数和边数
};

LGraph LG;

//创建邻接表存储图的结构
void CreateLG()
{
    //获取顶点数量和边的数量
    scanf("%d%d",&LG.vexNum,&LG.arcNum);
    //初始化
    for(int i=0;i<LG.vexNum;i++)
        LG.vertex[i].headOut=LG.vertex[i].headIn=nullptr;
    //输入数据
    for(int i=0;i<LG.arcNum;i++)
    {
        int v1,v2;  //存储边的起点和终点
        scanf("%d%d",&v1,&v2);
        ArcNode* pi; //用来构造边链表的边结点指针
        pi=new ArcNode;
        pi->adjvex=v2;
        pi->nextArc=LG.vertex[v1].headOut; //插入链表
        LG.vertex[v1].headOut=pi;
        pi=new ArcNode;
        pi->adjvex=v1;
        pi->nextArc=LG.vertex[v2].headIn;  //插入链表
        LG.vertex[v2].headIn=pi;
    }
}

int main()
{
    return 0;
}
