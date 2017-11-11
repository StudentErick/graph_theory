#include<cstdio>
#include<cstdlib>
const int INF=1000000;
const int MAXN=100;
int lowcost[MAXN],nearvex[MAXN];
struct ArcNode{
    int w,adjvex;
    struct ArcNode* next;
    ArcNode(){next=nullptr;}
};
struct  VNode{
    int node;
    struct ArcNode* head;
    VNode(){head=nullptr;}
};
struct LGraph{
    VNode vertex[MAXN];
    int arcNum,verNum;
}LG;
void Create(){  //建立无向图
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
        ArcNode* q=LG.vertex[v].head;
        if(q==nullptr){
            q=LG.vertex[v].head=new ArcNode;
            q->adjvex=u;q->w=w;
            q->next=nullptr;
        }
        else{
            while(q->next!=nullptr)q=q->next;
            q->next=new ArcNode;
            q=q->next;
            q->adjvex=u;q->w=w;
            q->next=nullptr;
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
}
void Prim(int v){
    int sumWidget=0;
    for(int i=0;i<LG.verNum;i++){
        ArcNode* p=LG.vertex[v].head;
        while(p!=nullptr&&p->adjvex!=i)p=p->next;
        if(p==nullptr)lowcost[i]=INF;
        else lowcost[i]=p->w;
        nearvex[i]=v;
    }
    nearvex[v]=-1;
    for(int i=1;i<LG.verNum;i++){
        int Min=INF,u=v;
        for(int j=0;j<LG.verNum;j++){
            if(nearvex[j]!=-1&&Min>lowcost[j]){
                Min=lowcost[j];u=j;
            }
        }
        printf("<%d,%d> %d\n",nearvex[u],u,lowcost[u]);
        sumWidget+=lowcost[u];
        nearvex[u]=-1;
        for(int j=0;j<LG.verNum;j++){
            ArcNode* p=LG.vertex[u].head;
            while(p!=nullptr&&p->adjvex!=j)p=p->next;
            if(nearvex[j]!=-1&&p!=nullptr&&lowcost[j]>p->w){
                lowcost[j]=p->w;
                nearvex[j]=u;
            }
        }
    }
    printf("Thee widget of MST is %d\n",sumWidget);
}
int main()
{
    scanf("%d%d",&LG.verNum,&LG.arcNum);
    Create();
    Prim(0);
    Delete();
    return 0;
}
/*
7 9
0 1 28
0 5 10
1 2 16
1 6 14
2 3 12
3 4 22
3 6 18
4 5 25
4 6 24
*/
