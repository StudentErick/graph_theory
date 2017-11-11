#include<cstdio>
#include<cstring>

const int MAXN=21;
const int MAXL=100;
int D,S,L,N;
int grid[MAXN*MAXN];
int gridbak[MAXN*MAXN];

struct SnakeAndLabber
{
    int from,to;;
}SL[MAXL];

int main()
{
    scanf("%d",&D);
    while(D--)
    {
        scanf("%d%d%d",&N,&S,&L);
        for(int i=0;i<S+L;i++)
            scanf("%d%d",&SL[i].from,&SL[i].to);
        memset(grid,0,sizeof(grid));
        grid[1]=1;
        int step=0;
        while(grid[N*N]==0)
        {
            memcpy(gridbak,grid,sizeof(grid));
            memset(grid,0,sizeof(grid));
            for(int i=1;i<N*N;i++)
            {
                if(!gridbak[i])continue;
                //ÖÀÉ«×Ó
                for(int j=1;j<=6;j++)
                {
                    if(i+j>=N*N)break;
                    int flag=true;
                    for(int k=0;k<S+L;k++)
                    {
                        if(SL[k].from==i+j)
                        {
                            grid[SL[k].to]=1;
                            flag=false;
                            break;
                        }
                    }
                    if(flag&&!grid[i+j])
                        grid[i+j]=1;
                }
            }
            step++;
        }
        printf("%d\n",step);
    }
    return 0;
}
/*
1
6 1 3
35 25
3 23 5 16 20 33
*/
