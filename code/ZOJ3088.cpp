#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=1005;
const int INF=1000000;
int dist1[MAXN][MAXN],dist2[MAXN][MAXN];   //dist1是之间的最大值，dist2是之间的最小值
int path1[MAXN][MAXN],path2[MAXN][MAXN];   //path1是最大值路径，path2是最小值路径
int inq[MAXN];
int N,M,K;
struct ArcNode{
    int v,w;
    struct ArcNode* next;
    ArcNode(){next=nullptr;}
}List1[MAXN],List2[MAXN];  //List1是最大值，List2是最小值
void Create(){
    scanf("%d%d%d",&N,&M,&K);
    int u,v,w;
    for(int i=0;i<M;i++){  //最大值路径，滑雪
        scanf("%d%d%d",&u,&v,&w);
        ArcNode* p=List1[u].next;
        if(p==nullptr)p=List1[u].next=new ArcNode;
        else{
            while(p->next!=nullptr)p=p->next;
            p->next=new ArcNode;
            p=p->next;
        }
        p->v=v;p->w=w;
        p->next=nullptr;
    }
    for(int j=0;j<K;j++){  //最小值路径，雪橇
        scanf("%d%d%d",&u,&v,&w);
        ArcNode* p=List2[u].next;
        if(p==nullptr)p=List2[u].next=new ArcNode;
        else{
            while(p->next!=nullptr)p=p->next;
            p->next=new ArcNode;
            p=p->next;
        }
        p->v=v;p->w=w;
        p->next=nullptr;
    }
}
void Delete(){
    for(int i=0;i<M;i++){
        ArcNode* p=List1[i].next;
        while(p!=nullptr){
            ArcNode* q=p->next;
            delete p;
            p=q;
        }
        List1[i].next=nullptr;
    }
    for(int i=0;i<K;i++){
        ArcNode* p=List2[i].next;
        while(p!=nullptr){
            ArcNode* q=p->next;
            delete p;
            p=q;
        }
        List2[i].next=nullptr;
    }
}
void SPFA1(int v){  //求解最长路径
    for(int i=0;i<MAXN;i++){
        dist1[v][i]=0;path1[v][i]=-1;inq[i]=0;
    }
    dist1[v][v]=0;inq[v]++;
    queue<int>Q;
    Q.push(v);
    while(!Q.empty()){
        int u=Q.front();
        inq[u]--;Q.pop();
        ArcNode* p=List1[u].next;
        while(p!=nullptr){
            if(dist1[v][u]+p->w>dist1[v][p->v]){
                dist1[v][p->v]=dist1[v][u]+p->w;
                path1[v][p->v]=u;
                if(!inq[p->v]){
                    Q.push(p->v);inq[p->v]++;
                }
            }
            p=p->next;
        }
    }
}
void SPFA2(int v){  //求解最短路径
    for(int i=0;i<MAXN;i++){
        dist2[v][i]=INF;path2[v][i]=-1;inq[i]=0;
    }
    dist2[v][v]=0;inq[v]++;
    queue<int>Q;
    Q.push(v);
    while(!Q.empty()){
        int u=Q.front();
        inq[u]--;Q.pop();
        ArcNode* p=List2[u].next;
        while(p!=nullptr){
            if(dist2[v][u]+p->w<dist2[v][p->v]){
                dist2[v][p->v]=dist2[v][u]+p->w;
                path2[v][p->v]=u;
                if(!inq[p->v]){
                    Q.push(p->v);inq[p->v]++;
                }
            }
            p=p->next;
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        Create(); //构图
        for(int i=1;i<=N;i++){  //先计算所有结点的距离
            SPFA1(i);
            SPFA2(i);
        }
        double tmp=-INF*1.0;
        int s=0,t=0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(i==j||dist1[i][j]==INF||dist2[j][i]==0)continue;
                if(dist1[i][j]*1.0/(1.0*dist2[j][i])>tmp){
                    tmp=dist1[i][j]*1.0/dist2[j][i];   //记录最大值和两个点的坐标
                    s=i;t=j;
                }
            }
        }
    /*    printf("%d ",s);
        int k=0,i=s,j=t;
        int a[MAXN];     //记录答案路径
        while(path2[i][j]!=s){
            a[k++]=path2[i][j];
            j=path2[i][j];
        }
        for(i=k-1;i>=0;i--)
            printf("%d ",a[i]);
        printf("%d ",t);
        i=t;j=s;k=0;
        while(path1[i][j]!=t){
            a[k++]=path1[i][j];
            j=path1[i][j];
        }
        for(i=k-1;i>=0;i--)
            printf("%d ",a[i]);
        printf("%d\n",s);  */
        printf("%.3f\n",tmp);
        Delete();
    }
}
/*
1
5 4 3
1 3 12
2 3 6
3 4 9
5 4 9
4 5 12
5 1 12
4 2 18
dist1:
0 0 12 21 0
0 0 6 15 0
0 0 0 9 0
0 0 0 0 0
0 0 0 9 0
dist2:
0 & & & &
& 0 & & &
& & 0 & &
24 18 & 0 12
12 & & & 0
*/
