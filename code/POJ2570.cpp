#include<cstdio>
const int MAXN=200;
int m[MAXN][MAXN],A,B,N;
char str[27];  //��ȡ��˾����
void Floyd(){
    while(scanf("%d%d",&A,&B)&&A&&B){
        scanf("%s",str);
        for(int i=0;str[i];++i)
            m[A][B]|=1<<(str[i]-'a');  //���ܴ�0��ʼ��������Զ��0
    }
    for(int k=1;k<N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                m[i][j]|=(m[i][k]&&m[k][j]);
}
int main()
{
    while(scanf("%d",&N)&&N){
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                m[i][j]=0;
        Floyd();
        while(scanf("%d%d",&A,&B)&&A&&B){  //��ѯ����
            for(char ch='a';ch<'z';ch++){
                if(m[A][B]&(1<<ch-'a'))
                    putchar(ch);
                if(!m[A][B])putchar('-');
                puts("");
            }
            puts("");
        }
    }
    return 0;
}
