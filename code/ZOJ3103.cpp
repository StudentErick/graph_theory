#include<cstdio>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
const int INF=100000;
const int MAXN=62;
int dist[31][31],W,H;
char G[MAXN][MAXN];
int offset[8][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};  //8��ƫ�Ʒ���
void Create(){
    queue<int>Q;
    for(int i=0;i<W;i++){   //ɨ����ײ㣬ѡ����Կ�ʼ�ĵص㣬����ͼ
        if(G[H][i]!='S')continue;
        Q.push((H)*W+i);
        while(!Q.empty()){
            int u=Q.front();
            int fx=u/W,fy=u%W;
            int rx,ry;
            for(int k=0;k<8;k++){

                while()
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&W,&H)&&W&&H){
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++)
                scanf("%c",&G[i][j]);
            getchar();  //��ȡ��β���з�
        }
    }
    return 0;
}
