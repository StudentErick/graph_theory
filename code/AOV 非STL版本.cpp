#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=100;  //������������ֵ

struct ArcNode
{
    int to;
    struct ArcNode* next;
};

int N,M;              //���ĸ������ߵĸ���
ArcNode* List[MAXN];  //ÿ������ı������ͷָ��
int Count[MAXN];      //����������
char output[MAXN];    //�������

void AOV()
{
    int top=-1;
    bool bcycle=false;  //�Ƿ��л��ı��
    int pos=0;
    for(int i=0;i<N;i++)
    {
        if(Count[i]==0)
        {
            Count[i]=top;
            top=i;
        }
    }
    for(int i=0;i<N;i++)
    {
        if(top==-1)  //ջΪ�գ����������·
        {
            bcycle=true;
            break;
        }
        int j=top;    //ջ������j��ջ
        top=Count[top];
        pos+=sprintf(output+pos,"%d",j+1);
        ArcNode* temp=List[j];
        //��������j�ı�����ÿ�����ߵ��յ�����-1
        while(temp!=nullptr)
        {
            int k=temp->to;
            if(--Count[k]==0)  //�յ���ȼ�Ϊ0����ջ
            {
                Count[k]=top;
                top=k;
            }
            temp=temp->next;
        }
    }
    if(bcycle)
        printf("Network has a cycle\n");
    else
    {
        int len=strlen(output);
        output[len-1]=0;  //ȥ�����Ŀո�
        printf("%s\n",output);
    }
}

int main()
{
    return 0;
}
