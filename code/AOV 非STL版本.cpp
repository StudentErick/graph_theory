#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=100;  //顶点个数的最大值

struct ArcNode
{
    int to;
    struct ArcNode* next;
};

int N,M;              //结点的个数，边的个数
ArcNode* List[MAXN];  //每个顶点的边链表表头指针
int Count[MAXN];      //各顶点的入度
char output[MAXN];    //输出内容

void AOV()
{
    int top=-1;
    bool bcycle=false;  //是否有环的标记
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
        if(top==-1)  //栈为空，存在有向回路
        {
            bcycle=true;
            break;
        }
        int j=top;    //栈顶顶点j出栈
        top=Count[top];
        pos+=sprintf(output+pos,"%d",j+1);
        ArcNode* temp=List[j];
        //遍历顶点j的边链表，每条出边的终点的入度-1
        while(temp!=nullptr)
        {
            int k=temp->to;
            if(--Count[k]==0)  //终点入度减为0，入栈
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
        output[len-1]=0;  //去掉最后的空格
        printf("%s\n",output);
    }
}

int main()
{
    return 0;
}
