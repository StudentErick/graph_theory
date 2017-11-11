#include<cstdio>

const int MAXN=51;
char G[MAXN][MAXN];
int visit[MAXN][MAXN];
int M,N;

struct Block
{
    int up,down,left,right;  //四个方向是否可行
    Block(){up=down=left=right=0;}
}B[MAXN][MAXN];

void DFS(int x,int y)
{
    if(x<0||x>=M||y<0||y>=N||visit[x][y])
        return;
    visit[x][y]=1;
    //水流向左
    if(B[x][y].left&&y-1>=0&&!visit[x][y-1]&&B[x][y-1].right)
        DFS(x,y-1);
    //水流向右
    if(B[x][y].right&&y+1<N&&!visit[x][y+1]&&B[x][y+1].left)
        DFS(x,y+1);
    //水流向上
    if(B[x][y].up&&x-1>=0&&!visit[x-1][y]&&B[x-1][y].down)
        DFS(x-1,y);
    //水流向下
    if(B[x][y].down&&x+1<N&&!visit[x+1][y]&&B[x+1][y].up)
        DFS(x+1,y);
}

int main()
{
    int t=0;
    while(scanf("%d%d",&M,&N)&&M!=-1&&N!=-1)
    {
        getchar();  //读取第一个空格
        for(int i=0;i<MAXN;i++)
            for(int j=0;j<MAXN;j++)
            visit[i][j]=0;
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                scanf("%c",&G[i][j]);
                getchar();  //读取最后的换行
                switch(G[i][j])
                {
                case 'A':
                    B[i][j].left=B[i][j].up=1;
                    B[i][j].down=B[i][j].right=0;
                    break;
                case 'B':
                    B[i][j].right=B[i][j].up=1;
                    B[i][j].left=B[i][j].down=0;
                    break;
                case 'C':
                    B[i][j].left=B[i][j].down=1;
                    B[i][j].up=B[i][j].right=0;
                    break;
                case 'D':
                    B[i][j].down=B[i][j].right=1;
                    B[i][j].up=B[i][j].left=0;
                    break;
                case 'E':
                    B[i][j].up=B[i][j].down=1;
                    B[i][j].left=B[i][j].right=0;
                    break;
                case 'F':
                    B[i][j].left=B[i][j].right=1;
                    B[i][j].up=B[i][j].down=0;
                    break;
                case 'G':
                    B[i][j].up=B[i][j].left=B[i][j].right=1;
                    B[i][j].down=0;
                    break;
                case 'H':
                    B[i][j].left=B[i][j].up=B[i][j].down=1;
                    B[i][j].right=0;
                    break;
                case 'I':
                    B[i][j].down=B[i][j].left=B[i][j].right=1;
                    B[i][j].up=0;
                    break;
                case 'J':
                    B[i][j].up=B[i][j].down=B[i][j].right=1;
                    B[i][j].left=0;
                    break;
                case 'K':
                    B[i][j].up=B[i][j].down=B[i][j].left=B[i][j].right=1;
                    break;
                }
            }
        }
        int n=0;
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(!visit[i][j])
                    n++;
                DFS(i,j);
            }
        }
        printf("%d\n",n);
    }
    return 0;
}
