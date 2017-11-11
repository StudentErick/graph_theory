#include<cstdio>
#include<cstring>

const int MAXN=6;
struct BLOCK
{
    int used;
    int up,down,left,right;
};
//the big square
BLOCK S[MAXN][MAXN];
//the small square
BLOCK B[MAXN*MAXN];
//number of small square
int N;

//row:  the row number in big square
//col:  the colume number int the big square
bool DFS(int row,int col)
{
    if((N==1)||(row>N-1))
        return true;
    bool flag=false;
    for(int k=0;k<N*N;k++)
    {
        if(!B[k].used)
        {
            //first square
            if(row==0&&col==0)
            {
                B[k].used=1;
                S[row][col]=B[k];
                flag=DFS(row,col+1);
                B[k].used=0;
            }
            //first row square
            else if(row==0&&col<=N-1)
            {
                if(B[k].left==S[row][col-1].right)
                {
                    B[k].used=1;
                    S[row][col]=B[k];
                    if(col==N-1)//last col need to change a row
                        flag=DFS(row+1,0);
                    else
                        flag=DFS(row,col+1);
                    B[k].used=0;
                }
            }
            //first colume square
            else if(row<=N-1&&col==0)
            {
                if(B[k].up==S[row-1][col].down)
                {
                    S[row][col]=B[k];
                    B[k].used=1;
                    flag=DFS(row,col+1);
                    B[k].used=0;
                }
            }
            //the normal condition
            else
            {
                if(B[k].left==S[row][col-1].right&&B[k].up==S[row-1][col].down)
                {
                    S[row][col]=B[k];
                    B[k].used=1;
                    if(col!=N-1)
                        flag=DFS(row,col+1);
                    else
                        flag=DFS(row+1,0);
                    B[k].used=0;
                }
            }
        }
    }
    if(!flag)
        return false;
    return true;
}

int main()
{
    int n=1;
    while(scanf("%d",&N)&&N>0)
    {
        for(int i=0;i<N*N;i++)
        {
            scanf("%d%d%d%d",&B[i].up,&B[i].right,&B[i].down,&B[i].left);
         //   B[i].used=0;
        }
        printf("Game %d:",n);
        if(DFS(0,0))
            printf(" Possible\n");
        else
            printf(" Impossible\n");
        n++;
    }
    return 0;
}
/*
5
3 2 1 4
4 8 7 4
9 6 3 2
7 8 9 5
1 2 3 6
7 4 5 8
9 8 6 0
1 4 7 8
9 5 4 6
7 8 5 2
1 2 3 6
7 4 5 8
9 8 7 4
5 2 1 0
1 2 6 9
7 8 5 1
1 4 7 9
4 8 5 2
6 9 8 7
4 1 2 3
7 8 9 5
7 4 5 8
6 2 6 8
4 1 2 5
4 7 8 9
0
*/
