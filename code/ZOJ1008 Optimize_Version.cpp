#include<cstdio>
#include<cstring>
/*������һ��ȫ�µ�˼·��������⣬
������֮ǰ����һ�����ˣ����Ǹ����������жϡ�*/
const int MAXN=5;
int type;  //�鲢�󣬷��������
int N;     //������
struct BLOCK
{
    int cnt;  //��¼��ͬ����ĸ���
    int up,down,left,right;
    bool operator==(const BLOCK &a)  //���أ��жϿ��Ƿ����
    {
        return (up==a.up&&down==a.down&&left==a.left&&right==a.right);
    }
};

BLOCK Block[MAXN*MAXN];
int Map[MAXN][MAXN];

bool DFS(int cur)
{
    //����һά��ʾ2ά�ķ�ʽ�������õ�
    int row=cur/N;
    int col=cur%N;
    if(cur==N*N)    //�ݹ����
        return true;
    //��̽��������ķ���
    for(int i=0;i<type;i++)
    {
        if(Block[cur].cnt==0)    //�����͵ķ��鱻�þ�
            continue;
        if(row>0&&Block[cur].up!=Block[Map[row-1][col]].down)
            continue;
        if(col>0&&Block[cur].left!=Block[Map[row][col-1]].down)
            continue;
        Map[row][col]=i;        //�����С������õ�i�ַ���
        Block[i].cnt--;             //ԭ�����������-1
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
                    break;   //ֻ��һ�����࣬�ҵ���ֱ���˳�
                }
                if(i==type)  //������һ���µķ���
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
