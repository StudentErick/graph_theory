#include<cstdio>
#include<cstring>
const int MAXN=100;
const int INF=100000;
int path[MAXN][MAXN],A[MAXN][MAXN];
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
    LGraph(){arcNum=verNum=0;}
}LG;
void Create(){
    scanf("%d",&LG.verNum);
    int u,v,w;
    while(scanf("%d%d%d",&u,&v,&w)&&u>=0&&v>=0){
        LG.vertex[u].node=u;
        ArcNode* p=LG.vertex[u].head;
        if(p==nullptr)p=LG.vertex[u].head=new ArcNode;
        else{
            while(p->next!=nullptr)p=p->next;
            p->next=new ArcNode;
            p=p->next;
        }
        p->adjvex=v;p->w=w;
        p->next=nullptr;
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
void Floyd(){
    for(int i=0;i<LG.verNum;i++){
        for(int j=0;j<LG.verNum;j++){
            if(i!=j)A[i][j]=INF;
            else A[i][j]=0;
            path[i][j]=-1;
        }
    }
    for(int i=0;i<LG.verNum;i++){
        ArcNode* p=LG.vertex[i].head;
        while(p!=nullptr){
            path[i][p->adjvex]=i;
            A[i][p->adjvex]=p->w;
            p=p->next;
        }
    }
    for(int k=0;k<LG.verNum;k++){
        for(int i=0;i<LG.verNum;i++){
            ArcNode* p=LG.vertex[i].head;
            while(p!=nullptr){
                if(A[i][p->adjvex]>A[i][k]+A[k][p->adjvex]){
                    A[i][p->adjvex]=A[i][k]+A[k][p->adjvex];
                    path[i][p->adjvex]=path[k][p->adjvex];
                }
                p=p->next;
            }
        }
    }
}
int main()
{
    Create();
    Floyd();
    printf("Dis\tLen\tPath\n");
    int N=LG.verNum;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j)continue;
            printf("%d->%d\t%d\t",i,j,A[i][j]);  //数据结点之间的距离
            int shortest[MAXN];
            memset(shortest,0,sizeof(shortest));
            int k=0;
            shortest[k]=j;
            while(path[i][shortest[k]]!=i)
                shortest[++k]=path[i][shortest[k-1]];
            shortest[++k]=i;
            for(int t=k;t>0;t--)
                printf("%d->",shortest[t]);
            printf("%d\n",shortest[0]);
        }
    }
    return 0;
}
/*
4
0 1 1
0 3 4
1 2 9
1 3 2
2 0 3
2 1 5
2 3 8
3 2 6
-1 -1 -1
*/
