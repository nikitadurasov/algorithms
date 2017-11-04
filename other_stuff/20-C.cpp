#include <bits/stdc++.h>
#define INF 2e18

typedef long long ll;
typedef std::pair<ll,int> ii;

int n,m,p[100005];
std::vector<ii> g[100005];
ll d[100005];
std::priority_queue<ii> q;

void trace(int k){if(p[k]!=-1) trace(p[k]); printf("%d ",k);}

int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        int u,v,l;scanf("%d%d%d",&u,&v,&l);
        g[u].push_back(ii(l,v)); g[v].push_back(ii(l,u));
    }
    std::fill(p,p+n+5,-1);std::fill(d,d+n+5,INF);
    q.push(ii(d[1]=0,1));
    while(!q.empty()){
        int u=q.top().second; q.pop();
        for(ii e: g[u]){
            int v=e.second; ll t=d[u]+e.first;
            if(t<d[v]) {p[v]=u;q.push(ii(-(d[v]=t),v));}
        }
    }
    if(d[n]==INF) {printf("-1\n"); return 0;}
    trace(p[n]);
    printf("%d\n",n);
    return 0;
}

void tr(int x){
    if(p[x]+1) tr(p[x]);
    std::cout << x+1 << ' ';}
