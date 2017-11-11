#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

//���ߴ�
const int MAXN=201;
//�Թ���ÿ���ط��ĳ�ʼʱ������Ϊ�����
const int INF=10000;
//�Թ�
char Maze[MAXN][MAXN];
//��¼��Сʱ��
int MiniTime[MAXN][MAXN];
//����������
struct point
{
    int x,y;   //��ǰ����
    int step;  //�ߵ���ǰ����Ĳ���
    int time;  //�ߵ���ǰ�����ʱ��
};
//ƫ�Ʒ���
int offset[4][2]={0,1,0,-1,1,0,-1,0};
//Angel������,���ѵ�����
int ax,ay,rx,ry;
//�Թ��ĳߴ�
int M,N;

//��x y��λ�ÿ�ʼѰ��
void BFS(int startX,int startY,int endX,int endY)
{
    point p;
    p.x=startX;
    p.y=startY;
    p.step=0;
    p.time=0;
    MiniTime[p.x][p.y]=0;
    queue<point>que;
    que.push(p);
    //��һ��whileѭ��������ȷ���Թ������п��Ե���ĵ�����ʱ��
    while(!que.empty())
    {
        p=que.front();
        que.pop();
        for(int k=0;k<4;k++)
        {
            int x=p.x+offset[k][0];
            int y=p.y+offset[k][1];
            //�ų��߽��ǽ��
            if(x>=0&&x<M&&y>=0&&y<N&&Maze[x][y]!='#')
            {
                point t;
                t.x=x;
                t.y=y;
                t.step=p.step+1;
                t.time=p.time+1;
                //�о���ʱ���1
                if(Maze[x][y]=='x')
                    t.time++;
                /*��������߷���֮ǰ���ѵ�ʱ���٣���Ѹ��߷�
                ������У������账��*/
                if(t.time<MiniTime[x][y])
                {
                    MiniTime[x][y]=t.time;
                    que.push(t);
                }
            }
        }
    }
}

int main()
{
    while(scanf("%d%d\n",&M,&N)!=EOF)
    {
        memset(Maze,0,sizeof(Maze));
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                scanf("%c",&Maze[i][j]);
                if(Maze[i][j]=='a')
                {
                    ax=i;
                    ay=j;
                }
                else if(Maze[i][j]=='r')
                {
                    rx=i;
                    ry=j;
                }
                MiniTime[i][j]=INF;
            }
            char c;
            //��ȡ��β�Ļ��з�
            scanf("%c",&c);
        }
        MiniTime[rx][ry]=0;
        BFS(rx,ry,ax,ay);
        if(MiniTime[rx][ry]<INF)
            printf("Poor ANGLE has to stay in the prison all his life\n");
        else
            printf("%d\n",MiniTime[ax][ay]);
    }
    return 0;
}
