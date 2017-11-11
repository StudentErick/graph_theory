#include<cstdio>
#include<cstring>

const int MAXN=10000;
int parent[MAXN];

//初始化
void UFset()
{
    memset(parent,-1,sizeof(parent));
}

//带有压缩路径的查找函数
int Find(int x)
{
    int s=x;
    //一直找到根结点
    for(s=x;parent[s]>=0;s=parent[s]);
    //压缩路径
    while(s!=x)
    {
        int tmp=parent[x];
        parent[x]=s;
        x=tmp;
    }
    return s;
}

//带有权重的合并算法
void Union(int x,int y)
{
    int r1=Find(x);
    int r2=Find(y);
    if(r1==r2)return;       ///一定要增加元素判重！！！！！有时可能合并了相同的元素
    int sum=parent[r1]+parent[r2];
    if(parent[r1]<parent[r2])   //x根结点的元素多
    {
        parent[r2]=r1;
        parent[r1]=sum;
    }
    else                        //y根结点的元素多
    {
        parent[r1]=r2;
        parent[r2]=sum;
    }
}

int main()
{
    return 0;
}
