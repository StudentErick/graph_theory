#include<cstdio>

#define MAXN 100

//�߽��
struct ArcNode
{
    int adjvex;  //����ߵ���һ���ڽӵ�����
    struct ArcNode* nextArc;  //ָ����һ�߽���ָ��
};

//����
struct VNode
{
    int data;  //������Ϣ
    ArcNode* headOut;  //���߱�ı�ͷָ��
    ArcNode* headIn;   //��߱�ı�ͷָ��
};

//ͼ���ڽӱ�Ĵ洢�ṹ
struct LGraph
{
    VNode vertex[MAXN];   //��������
    int vexNum,arcNum;    //�������ͱ���
};

LGraph LG;

//�����ڽӱ�洢ͼ�Ľṹ
void CreateLG()
{
    //��ȡ���������ͱߵ�����
    scanf("%d%d",&LG.vexNum,&LG.arcNum);
    //��ʼ��
    for(int i=0;i<LG.vexNum;i++)
        LG.vertex[i].headOut=LG.vertex[i].headIn=nullptr;
    //��������
    for(int i=0;i<LG.arcNum;i++)
    {
        int v1,v2;  //�洢�ߵ������յ�
        scanf("%d%d",&v1,&v2);
        ArcNode* pi; //�������������ı߽��ָ��
        pi=new ArcNode;
        pi->adjvex=v2;
        pi->nextArc=LG.vertex[v1].headOut; //��������
        LG.vertex[v1].headOut=pi;
        pi=new ArcNode;
        pi->adjvex=v1;
        pi->nextArc=LG.vertex[v2].headIn;  //��������
        LG.vertex[v2].headIn=pi;
    }
}

int main()
{
    return 0;
}
