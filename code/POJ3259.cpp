#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=100000;
const int MAXN=550;
int N,M,W,dist[MAXN],inq[MAXN],T[MAXN];   //顶点个数，双向边，单向边
struct ArcNode{
    int v,w;
    struct ArcNode* next;
    ArcNode(){next=NULL;}
};
struct VNode{
    int node;
    struct ArcNode* head;
    VNode(){head=NULL;}
}List[MAXN];
void Create(){
    scanf("%d%d%d",&N,&M,&W);
    for(int i=0;i<M;i++){   //读入双向边
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        ArcNode* p=List[u].head;
        if(p==NULL)p=List[u].head=new ArcNode;
        else{
            while(p->next!=NULL)p=p->next;
            p->next=new ArcNode;
            p=p->next;
        }
        p->v=v;p->w=w;
        p->next=NULL;
        p=List[v].head;
        if(p==NULL)p=List[v].head=new ArcNode;
        else{
            while(p->next!=NULL)p=p->next;
            p->next=new ArcNode;
            p=p->next;
        }
        p->v=u;p->w=w;
        p->next=NULL;
    }
    for(int i=0;i<W;i++){   //读入单向边
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        ArcNode* p=List[u].head;
        if(p==NULL)p=List[u].head=new ArcNode;
        else{
            while(p->next!=NULL)p=p->next;
            p->next=new ArcNode;
            p=p->next;
        }
        p->v=v;p->w=-w;   //注意这里的负号
        p->next=NULL;
    }
}
void Delete(){
    for(int i=0;i<=N;i++){
        ArcNode* p=List[i].head;
        while(p!=NULL){
            ArcNode* q=p->next;
            delete p;
            p=q;
        }
        List[i].head=NULL;
    }
}
bool SPFA(int v){
    for(int i=0;i<MAXN;i++){
        dist[i]=INF;inq[i]=0;T[i]=0;
    }
    dist[v]=0;inq[v]++;T[v]++;
    queue<int>Q;
    Q.push(v);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();inq[u]--;
        ArcNode* p=List[u].head;
        while(p!=NULL){
            if(dist[u]+p->w<dist[p->v]){
                dist[p->v]=dist[u]+p->w;
                if(!inq[p->v]){
                    Q.push(p->v);
                    inq[p->v]++;T[p->v]++;
                    if(T[p->v]>N)return true;
                }
            }
            p=p->next;
        }
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        Create();
        if(SPFA(1))puts("YES");
        else puts("NO");
        Delete();
    }
    return 0;
}
