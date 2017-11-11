#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=15;

struct vertex
{
    int degree;  //����Ķ���
    int index;   //�±�
}V[N];

//���ݼ���������һ�����ݵĸ���
int T,n;
//�ڽӾ���
int Edge[N][N];

int cmp(const vertex &a,const vertex &b)
{
    return a.degree>b.degree;
}

void solve()
{
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
       scanf("%d",&V[i].degree);
       V[i].index=i;
   }
   memset(Edge,0,sizeof(Edge));
   //flag=0����ͼ
   int flag=1;
   for(int k=0;k<n&&flag;k++)
   {
       sort(V+k,V+n,cmp);
       int d1=V[k].degree;
       int i=V[k].index;
       //��ǰ���Ķ�������ʣ����ĸ���
       if(d1>n-k-1)flag=0;
       //�жϵ�ǰ���֮���d1��������-1���Ƿ���Ȼ��С��0
       for(int r=1;r<=d1&&flag;r++)
       {
           if(V[k+r].degree<=0)flag=0;
           V[k+r].degree--;
           int j=V[k+r].index;
           //�����ڽӾ���
           Edge[i][j]=Edge[j][i]=1;
       }
   }
   if(flag)
   {
       printf("YES\n");
       for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          printf("%d%c",Edge[i][j],j==n-1?'\n':' ');

   }
   else
    printf("NO\n");
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        solve();
        //ע���ʽ
        if(T) puts("");

    }
    return 0;
}

/*
�����ǲ�������
input:
3
7
4 3 1 5 4 2 1
6
4 3 1 4 2 0
6
2 3 1 1 2 1
output:
YES
0 1 0 1 1 0 1
1 0 0 1 1 0 0
0 0 0 1 0 0 0
1 1 1 0 1 1 0
1 1 0 1 0 1 0
0 0 0 1 1 0 0
1 0 0 0 0 0 0

NO

YES
0 1 0 0 1 0
1 0 0 1 1 0
0 0 0 0 0 1
0 1 0 0 0 0
1 1 0 0 0 0
0 0 1 0 0 0
*/
