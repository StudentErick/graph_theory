#include<cstdio>
#include<cstring>

const int MAXN=1000;

int flag=0;

char Maze[MAXN][MAXN];
int visit[MAXN][MAXN];
//the size of maze and limited time
int M,N,T;
//4 directions
int offset[4][2]={0,-1,0,1,-1,0,1,0};
//number of step
int n;
//start and end position
int StartX,StartY,EndX,EndY;

//depth first search
bool DFS(int sx,int sy,int n)
{
    if(n>T)
        return false;
    if(sx==EndX&&sy==EndY&&n==T)
        return true;
    for(int k=0;k<4;k++)
    {
        int x=sx+offset[k][0];
        int y=sy+offset[k][1];
        if(x>=0&&x<M&&y>=0&&y<N&&Maze[x][y]!='X'&&!visit[x][y])
        {
            visit[x][y]=1;
            if(DFS(x,y,n+1))
                return true;
            visit[x][y]=0;
        }
    }
    return false;
}

int main()
{
    while(scanf("%d%d%d\n",&M,&N,&T)&&!(M==0&&N==0&&T==0))
    {
        //remeber to initlalize them every time
        memset(Maze,0,sizeof(Maze));
        memset(visit,0,sizeof(visit));
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                scanf("%c",&Maze[i][j]);
                //record dog's position
                if(Maze[i][j]=='S')
                {
                    StartX=i;
                    StartY=j;
                }
                if(Maze[i][j]=='D')
                {
                    EndX=i;
                    EndY=j;
                }
            }
            /////////
            //scanf will read in enter,so we need to use this to avid enter in every end of line
            char c;
            scanf("%c",&c);
            ///////////////////
        }
        if(DFS(StartX,StartY,0))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
