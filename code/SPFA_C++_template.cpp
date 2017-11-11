#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int INF=1000000;
const int MAXN=100;
int dist[MAXN],path[MAXN],inq[MAXN];   //inq是判断数据是否在队列中的标志
struct ArcNode{
    int adjvex,w;
    struct ArcNode* next;
    ArcNode(){next=nullptr;}
};
struct VNode{
    int node;
    ArcNode* head;
    VNode(){head=nullptr;}
};
struct LGraph{
    VNode vertex[MAXN];
    int arcNum,verNum;
}LG;
void  Create(){
    scanf("%d",&LG.verNum);
    int u,v,w;
    while(scanf("%d%d%d",&u,&v,&w)&&u>=0&&v>=0){
        ArcNode* p=LG.vertex[u].head;
        if(p==nullptr){
            p=LG.vertex[u].head=new ArcNode;
            p->adjvex=v;p->w=w;
            p->next=nullptr;
        }
        else{
            while(p->next!=nullptr)p=p->next;
            p->next=new ArcNode;
            p=p->next;
            p->adjvex=v;p->w=w;
            p->next=nullptr;
        }
        LG.arcNum++;
    }
}
void Delete(){
    for(int i=0;i<LG.verNum;i++){
        ArcNode* p=LG.vertex[i].head;
        while(p!=nullptr){
            ArcNode* q=p->next;
            delete p;
            p=q;
        }
        LG.vertex[i].head=nullptr;
    }
    LG.arcNum=LG.verNum=0;
}
void SPFA(int v){
    memset(inq,0,sizeof(inq));
    for(int i=0;i<MAXN;i++){
        dist[i]=INF;path[i]=v;
    }
    dist[v]=0;path[v]=v;inq[v]++;     //注意这里的是否在队列中的判断方式
    queue<int>Q;                      //队列的真正作用是存储需要更新的顶点的边
    Q.push(v);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();inq[u]--;
        ArcNode* p=LG.vertex[u].head;
        while(p!=nullptr){
            int tmp=p->adjvex;
            if(dist[u]+p->w<dist[tmp]){
                dist[tmp]=dist[u]+p->w;path[tmp]=u;
                if(!inq[tmp]){   //距离调整后，必然要把调整后的结点加入队列，判断与之相连的顶点是否有调整
                    Q.push(tmp);inq[tmp]++;
                }
            }
            p=p->next;
        }
    }
}
int main()
{
    Create();
    SPFA(0);
    int shortest[MAXN];
    printf("Num\tlength\tpath\n");
    for(int i=1;i<LG.verNum;i++){
        memset(shortest,0,sizeof(shortest));
        int k=0;
        shortest[k]=i;
        while(path[shortest[k]]!=0)
            shortest[++k]=path[shortest[k-1]];
        shortest[++k]=0;
        printf("%d\t%d\t",i,dist[i]);
        for(int j=k;j>0;j--)printf("%d->",shortest[j]);
        printf("%d\n",shortest[0]);
    }
    Delete();
    return 0;
}
/*
7
0 1 6
0 2 5
0 3 5
1 4 -1
2 1 -2
2 4 1
3 2 -2
3 5 -1
4 6 3
5 6 3
-1 -1 -1
*/
