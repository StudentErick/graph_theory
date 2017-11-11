#include<cstdio>
#include<cstring>

const int MAXN=1000;
char Blocks[MAXN][MAXN];
int visit[MAXN][MAXN];
int M,N;
//8 directions
int offset[8][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};

void DFS(int x,int y)
{
    if(x<0||x>=M||y<0||y>=N||Blocks[x][y]!='@'||visit[x][y])
        return;
    visit[x][y]=1;
    for(int k=0;k<8;k++)
    {
        DFS(x+offset[k][0],y+offset[k][1]);
    }
}

int main()
{
    while(scanf("%d%d",&M,&N)&&M!=0)
    {
        memset(visit,0,sizeof(visit));
        memset(Blocks,0,sizeof(Blocks));
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                scanf("%c",&Blocks[i][j]);
            }
            char c;
            scanf("%c",&c);
        }
        int n=0;
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(Blocks[i][j]=='@'&&!visit[i][j])
                {
                    DFS[i][j];
                    n++;
                }
            }
        }
        printf("%d\n",n);
    }
    return 0;
}
