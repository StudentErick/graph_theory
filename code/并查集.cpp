#include<cstdio>
#include<cstring>

const int MAXN=10000;
int parent[MAXN];

//��ʼ��
void UFset()
{
    memset(parent,-1,sizeof(parent));
}

//����ѹ��·���Ĳ��Һ���
int Find(int x)
{
    int s=x;
    //һֱ�ҵ������
    for(s=x;parent[s]>=0;s=parent[s]);
    //ѹ��·��
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
    if(r1==r2)return;       ///һ��Ҫ����Ԫ�����أ�����������ʱ���ܺϲ�����ͬ��Ԫ��
    int sum=parent[r1]+parent[r2];
    if(parent[r1]<parent[r2])   //x������Ԫ�ض�
    {
        parent[r2]=r1;
        parent[r1]=sum;
    }
    else                        //y������Ԫ�ض�
    {
        parent[r1]=r2;
        parent[r2]=sum;
    }
}

int main()
{
    return 0;
}
