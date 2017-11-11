#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

const int MAXN=1000;   //�������
const int INF=1000000;

//�¼����翪ʼ������ʼ��ʱ��
int ve[MAXN],vl[MAXN];
//����翪ʼ������ʼ��ʱ��
int e[MAXN],l[MAXN];

struct ArcNode
{
    int adjvex;             //�ڽӵ�
    int widget;             //�ߵ�Ȩ��
    int edge;               //�ߵı��
    struct ArcNode* next;   //�ڽӱ�ָ��
    ArcNode(){adjvex=0;widget=0;next=nullptr;}
};

struct VNode
{
    int node;                 //�׽��
    int CountIn,CountOut;     //��ȣ�����
    ArcNode *headIn,*headOut; //���ͷ��㣬����ͷ���
    VNode(){node=0;CountIn=CountOut=-1;headIn=headOut=nullptr;}
};

struct LGraph
{
    VNode vertex[MAXN];   //�������
    int arcNum,verNum;    //�ߵ���Ŀ��������Ŀ
};

LGraph LG;

/*Create�����������룬һ���Դ�������ߺͳ��ߵĹ�ϵ��
���ߵĲ��������෴������u��v��ŵ�����*/
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
        //������ߵ�
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

        //������ߵģ�����������෴
        LG.vertex[v].CountIn++;  //������������1
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
        //ɾ�����
        ArcNode* p=LG.vertex[i].headIn;
        while(p!=nullptr)
        {
            ArcNode* q=p->next;
            delete p;
            p=q;
        }
        //ɾ������
        p=LG.vertex[i].headOut;
        while(p!=nullptr)
        {
            ArcNode* q=p->next;
            delete p;
            p=q;
        }
        //������ָ������
        LG.vertex[i].CountIn=LG.vertex[i].CountOut=-1;
        LG.vertex[i].headIn=LG.vertex[i].headOut=nullptr;
    }
    LG.verNum=LG.arcNum=0;
}

void AOE()
{
    int s=0;
    //Ѱ��Դ�㣬ֻ��Դ��������0
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
    //����������Ĺ����У����ve��ͳ��
    while(!sta.empty())
    {
        int j=sta.top();
        sta.pop();
        ArcNode* p=LG.vertex[j].headOut;
        res++;
        while(p!=nullptr)
        {
            //������һ������Ĺ��̣����ve�ĸ�ֵ
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
    //�л�
    if(res<LG.verNum)
    {
        printf("Network has loop!\n");
        return;
    }

    vl[LG.verNum-1]=ve[LG.verNum-1];
    //�������������vl�������ve�ķ��������෴
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
    Create();  //�����ڽӱ�洢ͼ�Ľṹ
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
