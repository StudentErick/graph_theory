#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1000;
int sumWidget=0;     //Ȩ�ص��ܺ�
int parent[MAXN];    //���鼯
int verNum,arcNum;   //�����Ŀ���ߵ���Ŀ

struct Edge
{
    int u,w,v;       //u��v�ǽ�㣻w��Ȩ��
}edge[MAXN];

//����ȽϺ���
int cmp(const Edge &a,const Edge &b)
{
    return a.w<b.w;
}

//���鼯��ʼ��
void UFset()
{
    memset(parent,-1,sizeof(parent));
}

//����ѹ��·���ĺϲ��㷨
int Find(int x)
{
    int s;
    for(s=x;parent[s]>=0;s=parent[s]);  //Ѱ����������
    while(s!=x)
    {
        int tmp=parent[x];
        parent[x]=s;
        x=tmp;
    }
    return s;
}

//����Ȩ�صĺϲ��㷨
void Union(int x,int y)
{
    int r1=Find(x);
    int r2=Find(y);
    int sum=parent[r1]+parent[r2];
    if(parent[r1]<parent[r2])  //r1��Ԫ�ض�
    {
        parent[r2]=r1;
        parent[r1]=sum;
    }
    else                       //r2��Ԫ�ض�
    {
        parent[r1]=r2;
        parent[r2]=sum;
    }
}

void Kruskal()
{
    sort(edge,edge+arcNum,cmp);
    int num=0;    //��ѡ�ñߵ���Ŀ
    UFset();
    sumWidget=0;
    for(int i=0;i<arcNum;i++)
    {
        int u=edge[i].u;
        int v=edge[i].v;
        if(Find(u)!=Find(v))
        {
            sumWidget+=edge[i].w;
            Union(u,v);  //�ϲ����
            num++;       //MST�ı�����
            printf("%d->%d: %d\n",u,v,edge[i].w);
        }
        //�Ѿ�������MST
        if(num>verNum-1)
            break;
    }
}

int main()
{
    scanf("%d%d",&verNum,&arcNum);  //����ߺͽ�������
    for(int i=0;i<arcNum;i++)
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    Kruskal();
    printf("widget of MST is %d\n",sumWidget);
    return 0;
}
/*
��������
7 9
1 2 28
1 6 10
2 3 16
2 7 14
3 4 12
4 5 22
4 7 18
5 6 25
5 7 24
*/
