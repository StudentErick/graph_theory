#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=100000;
const int MAXN=1005;
int dist[2][MAXN],inq[MAXN],N,M,X;
struct ArcNode{
    int v,w;
    struct ArcNode* next;
    ArcNode(){next=NULL;}
};
struct VNode{
    int node;
    ArcNode* head[2];  //0是出边表，1是入边表
    VNode(){head[0]=head[1]=NULL;}
}List[MAXN];
void Create(){
    for(int i=0;i<M;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        --u;--v;
        ArcNode* p=List[u].head[0];   //构造出边表
        List[u].node=u;
        if(p==NULL)p=List[u].head[0]=new ArcNode;
        else{
            while(p->next!=NULL)p=p->next;
            p->next=new ArcNode;
            p=p->next;
        }
        p->v=v;p->w=w;
        p->next=NULL;
        ArcNode* q=List[v].head[1];           //构造入边表
        List[v].node=v;
        if(q==NULL)q=List[v].head[1]=new ArcNode;
        else{
            while(q->next!=NULL)q=q->next;
            q->next=new ArcNode;
            q=q->next;
        }
        q->v=u;q->w=w;
        q->next=NULL;
    }
}
void Delete(){
    for(int i=0;i<N;i++){
        ArcNode *p0=List[i].head[0],*p1=List[i].head[1];
        while(p0!=NULL){
            ArcNode *q0=p0->next;
            delete p0;
            p0=q0;
        }
        while(p1!=NULL){
            ArcNode* q1=p1->next;
            delete p1;
            p1=q1;
        }
        List[i].head[0]=List[i].head[1]=NULL;
    }
}
void SPFA(int dir){
    for(int i=0;i<MAXN;i++){
        dist[dir][i]=INF;inq[i]=0;
    }
    dist[dir][X]=0;inq[X]++;
    queue<int>Q;
    Q.push(X);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();inq[u]--;
        ArcNode* p=List[u].head[dir];
        while(p!=NULL){
            if(dist[dir][u]+p->w<dist[dir][p->v]){
                dist[dir][p->v]=dist[dir][u]+p->w;
                if(!inq[p->v]){
                    Q.push(p->v);inq[p->v]++;
                }
            }
            p=p->next;
        }
    }
}
int main(){
    while(scanf("%d%d%d",&N,&M,&X)!=EOF){
        --X;
        Create();
        int Max=-INF;
        SPFA(0);SPFA(1);
        for(int i=0;i<N;i++){
            if(dist[0][i]+dist[1][i]>Max)
                Max=dist[0][i]+dist[1][i];
        }
        printf("%d\n",Max);
        Delete();
    }
    return 0;
}
/*
4 6 4
1 2 1
2 4 1
2 3 1
3 2 1
3 4 1
4 1 1
*/
