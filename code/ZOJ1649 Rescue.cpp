#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

//最大尺寸
const int MAXN=201;
//迷宫的每个地方的初始时间设置为无穷大
const int INF=10000;
//迷宫
char Maze[MAXN][MAXN];
//记录最小时间
int MiniTime[MAXN][MAXN];
//坐标点的数据
struct point
{
    int x,y;   //当前坐标
    int step;  //走到当前坐标的步数
    int time;  //走到当前坐标的时间
};
//偏移方向
int offset[4][2]={0,1,0,-1,1,0,-1,0};
//Angel的坐标,朋友的坐标
int ax,ay,rx,ry;
//迷宫的尺寸
int M,N;

//从x y的位置开始寻找
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
    //第一个while循环，用于确定迷宫中所有可以到达的点的最短时间
    while(!que.empty())
    {
        p=que.front();
        que.pop();
        for(int k=0;k<4;k++)
        {
            int x=p.x+offset[k][0];
            int y=p.y+offset[k][1];
            //排除边界和墙壁
            if(x>=0&&x<M&&y>=0&&y<N&&Maze[x][y]!='#')
            {
                point t;
                t.x=x;
                t.y=y;
                t.step=p.step+1;
                t.time=p.time+1;
                //有警察时间加1
                if(Maze[x][y]=='x')
                    t.time++;
                /*如果这种走法比之前花费的时间少，则把该走法
                加入队列，否则不予处理。*/
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
            //读取行尾的换行符
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
