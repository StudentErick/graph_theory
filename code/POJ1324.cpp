#include<cstdio>
#include<cstring>
#define Body 1
#define Block -1
const int MAXN=21;
int Lair[MAXN][MAXN];
int m,n,L,K;
int res=0;//�����Ĳ���
int N=0;  //���������
int Length[MAXN];
int dir[4][2]={-1,0,1,0,0,-1,0,1};
int visit[MAXN][MAXN];
/*����DFS��Ѱ�����е�·����Ȼ���ҳ���̵�·��*/

struct Snake
{
    int x,y;
}S[MAXN];

Snake tail;

void DFS(int sx,int sy,int ex,int ey,int step)
{
    if(sx<0||sx>=m||sy<0||sy>=n||Lair[sx][sy]!=0||visit[sx][sy])
        return;
    //�ҵ��յ㣬�������
    if(sx==ex&&sy==ey)
    {
        Length[N++]=step;
        return;
    }
    int x=0,y=0;
    for(int k=0;k<4;k++)
    {
        x=sx+dir[k][0];
        y=sy+dir[k][1];
        tail=S[L-1];  //����β���ۼ�
        //ģ��������ƶ�
        for(int t=1;t<L;t++)
        {
            S[t]=S[t-1];
        }
        S[0].x=x;  //�ƶ�ͷ
        S[0].y=y;
        Lair[S[0].x][S[0].y]=Body;
        Lair[tail.x][tail.y]=0;  //β���ƶ��󣬱�ɿյ�
        visit[x][y]=1;
        DFS(x,y,ex,ey,step+1);
        visit[x][y]=0;
        //�ظ�ԭ���ķ���
        x-=dir[k][0];
        y-=dir[k][1];
        Lair[S[0].x][S[0].y]=0;  //�ָ�ͷ����λ��
        S[L-1]=tail;  //�ָ�β��
        Lair[tail.x][tail.y]=Body;
        S[L-1]=tail;
        //�ָ�ģ�������ƶ�
        for(int t=0;t<L-1;t++)
        {
            S[t]=S[t+1];
        }
    }
}

int main()
{
    int round=0;
    while(scanf("%d%d%d",&m,&n,&L)&&n!=0&&m!=0&&L!=0)
    {
        memset(Lair,0,sizeof(Lair));
        memset(visit,0,sizeof(visit));
        memset(S,0,sizeof(S));
        N=0;
        for(int i=0;i<L;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            S[i].x=a;
            S[i].y=b;
            Lair[a][b]=Body;
        }
        scanf("%d",&K);
        for(int j=0;j<K;j++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            Lair[a][b]=Block;
        }
        DFS(S[0].x,S[0].y,1,1,0);
        res=0;
        for(int i=1;i<N;i++)
        {
            if(Length[i]!=0&&Length[i]<Length[i-1])
                res=Length[i-1];
        }
        if(res!=0)
            printf("Case %d:%d\n",++round,res);
        else
            printf("Case %d:-1\n",++round);
    }
    return 0;
}
/*
5 6 4
4 1
4 2
3 2
3 1
3
2 3
3 3
3 4

4 4 4
2 3
1 3
1 4
2 4
4
2 1
2 2
3 4
4 2

0 0 0
*/
