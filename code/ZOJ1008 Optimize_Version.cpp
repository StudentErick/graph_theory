#include<cstdio>
#include<cstring>
/*这里用一种全新的思路来解决问题，
不在是之前的逐一测试了，而是根据种类来判断。*/
const int MAXN=5;
int type;  //归并后，方块的种类
int N;     //行列数
struct BLOCK
{
    int cnt;  //记录相同方块的个数
    int up,down,left,right;
    bool operator==(const BLOCK &a)  //重载，判断块是否相等
    {
        return (up==a.up&&down==a.down&&left==a.left&&right==a.right);
    }
};

BLOCK Block[MAXN*MAXN];
int Map[MAXN][MAXN];

bool DFS(int cur)
{
    //利用一维表示2维的方式，经常用到
    int row=cur/N;
    int col=cur%N;
    if(cur==N*N)    //递归结束
        return true;
    //试探所有种类的方块
    for(int i=0;i<type;i++)
    {
        if(Block[cur].cnt==0)    //该类型的方块被用尽
            continue;
        if(row>0&&Block[cur].up!=Block[Map[row-1][col]].down)
            continue;
        if(col>0&&Block[cur].left!=Block[Map[row][col-1]].down)
            continue;
        Map[row][col]=i;        //在这个小方格放置第i种方块
        Block[i].cnt--;             //原来方块的种类-1
        if(DFS(cur+1))
            return true;
        Block[i].cnt++;
    }
    return false;
}

int main()
{
    int t=0;
    while(scanf("%d",&N)&&N)
    {
        type=0;
        memset(Map,-1,sizeof(Map));
        memset(Block,0,sizeof(Block));
        for(int i=0;i<N*N;i++)
        {
            int up,down,left,right;
            scanf("%d%d%d%d",&up,&left,&down,&right);
            for(int i=0;i<type;i++)
            {
                if(Block[i].up==up&&Block[i].down==down&&Block[i].left==left&&Block[i].right==right)
                {
                    Block[i].cnt++;
                    break;   //只有一个种类，找到了直接退出
                }
                if(i==type)  //出现了一种新的方块
                {
                    type++;
                    Block[i].up=up;Block[i].down=down;
                    Block[i].left=left;Block[i].right=right;
                    Block[i].cnt++;
                }
            }
        }
        if(t==0)
            puts("");
        if(DFS(0))
            printf("Game %d: Possible\n",t);
        else
            printf("Game %d: Impossible\n",t);
        t++;
;    }
    return 0;
}
