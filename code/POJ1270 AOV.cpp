#include<cstdio>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;

char Line[2][27];  //��ǹ�ϵ,���300��
char Order[26][26];//��λ���飬��һά���ڴ洢˳�򣬵ڶ�ά���ڴ洢ͬ����ĸ���
int Loc[26];   //��¼Ԫ����ͼ�е�λ��

struct Node
{
    char C[26];
    int Loc;
    Node(){Loc=0;}
}GNode[26];

struct ArcNode
{
    char adjvex;
    struct ArcNode* next;
    ArcNode(){next=NULL;adjvex='\0';}
};

struct VNode
{
    char node;
    int Count;    //�������
    ArcNode* head;
    VNode(){head=NULL;node='\0';Count=0;}
};

struct LGraph
{
    VNode vertex[20];
    int arcNum,verNum;
};

void Create()
{
   int l=strlen(Line[0]);  //��ȡԪ�ظ���
   LG.verNum=l;
   //�������ڻ�ȡԪ�ظ���
   sort(Line[0],Line[0]+l);
   memset(Loc,-1,sizeof(Loc));
   //ÿ��Ԫ�ض���һ��Ψһ��λ��ӳ��
   for(int i=0;i<l;i++)
   {
       int t=Line[i]-'a';
       Loc[t]=i;
   }
   //��ȡ���Ԫ��
   for(int i=0;i<l;i++)
   {
       LG.vertex[i].node=Line[i];
   }
   l=strlen(Line[1]);
   LG.arcNum[l]=l;
   //�������鶨λ������ʱ�俪��
   for(int i=0;i<l;i+=2)
   {
       int u=Loc[Line[1][i]-'a'];
       int v=Loc[Line[1][i+1]-'a'];
       LG.vertex[i].node=Line[1][i];
       ArcNode* p=LG.vertex[u].head;
       if(p==NULL)
       {
           p=LG.vertex[u].head=new ArcNode;
           p->adjvex=Line[1][i+1];
           p->next=NULL;
           LG.vertex[v].Count++;
       }
       else
       {
           while(p->next!=NULL)
            p=p->next;
           p->next=new ArcNode;
           p->adjvex=Line[1][i+1];  //���
           p->next=NULL;
           LG.vertex[v].Count++;
       }
   }
}

void DeleteGraph()
{
    for(int i=0;i<LG.verNUm;i++)
    {
        ArcNode* p=LG.verNum;
        while(p!=NULL)
        {
            ArcNode* q=p;
            delete p;
            p=q;
        }
        LG.vertex[i].head=NULL;
    }
}

void AOV()
{
    stack<int>sta;
    for(int i=0;i<LG.verNum;i++)
    {
        if(LG.vertex[i].Count==0)
        {
            GNode[0].C[Loc++]
        }
    }
}

int main()
{
    int i=-1;
    while(scanf("%s",Line[0])!=EOF&&scanf("%s",Line[1])!=EOF)
    {
        Create();
    }
    return 0;
}
