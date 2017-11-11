#include<cstdio>
#include<cstdlib>
#include<cstring>
const int MAXN=100;
const int INF=10000;
int dist[MAXN],path[MAXN],S[MAXN];
struct ArcNode{
    int w,adjvex;
    struct ArcNode*  next;
    ArcNode(){next=nullptr;}
};
struct VNode{
    int node;
    struct ArcNode* head;
    VNode(){head=nullptr;}
};
struct LGraph{
    VNode vertex[MAXN];
    int arcNum,verNum;
    LGraph(){arcNum=verNum=0;}
}LG;
void Create(){  //这里是针对有向图的建模
    int u,v,w;
    for(int i=0;i<LG.arcNum;i++){
        scanf("%d%d%d",&u,&v,&w);
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
void Dijkstra(int v){
    for(int i=0;i<MAXN;i++){
        S[i]=0;dist[i]=INF;path[i]=-1;
    }
    ArcNode* p=LG.vertex[v].head;
    while(p!=nullptr){
      dist[p->adjvex]=p->w;
      path[p->adjvex]=v;
      p=p->next;
    }
    S[v]=1;dist[v]=0;
    for(int i=0;i<LG.verNum-1;i++){
        int Min=INF,u=v;
        for(int j=0;j<LG.verNum;j++){
            if(!S[j]&&dist[j]<Min){
                Min=dist[j];u=j;
            }
        }
        S[u]=1;
        p=LG.vertex[u].head;
        while(p!=nullptr){
            if(!S[p->adjvex]&&dist[u]+p->w<dist[p->adjvex]){
                dist[p->adjvex]=dist[u]+p->w;
                path[p->adjvex]=u;
            }
            p=p->next;
        }
    }
}
int main()
{
    scanf("%d%d",&LG.verNum,&LG.arcNum);
    Create();
    Dijkstra(0);
    int shortest[MAXN];
    for(int i=1;i<LG.verNum;i++){
        memset(shortest,0,sizeof(shortest));
        int k=0;
        shortest[k]=i;
        while(path[shortest[k]]!=0)
            shortest[++k]=path[shortest[k-1]];
        shortest[++k]=0;
        for(int j=k;j>0;j--)
            printf("%d->",shortest[j]);
        printf("%d\n",shortest[0]);
    }
    printf("path[]: ");
    for(int i=0;i<LG.verNum;i++)
        printf("%d ",path[i]);
    puts("");
    printf("dist[]: ");
    for(int i=0;i<LG.verNum;i++)
        printf("%d ",dist[i]);
    puts("");
    Delete();
    return 0;
}
/*
测试数据：
6 9
0 2 5
0 3 30
1 0 2
1 4 8
2 5 7
2 1 15
4 3 4
5 3 10
5 4 18

0->2->1
0->2
0->2->5->3
0->2->1->4
0->2->5

*/
//-1 2 0 5 1 2
//0 20 5 22 28 12
