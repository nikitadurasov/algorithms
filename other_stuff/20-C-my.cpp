#include <bits/stdc++.h>
//#include<vector>
//#include<queue>
//#include <iostream>

typedef long long ll;
typedef std::pair<ll, int> ii;

const ll INF = (const ll) 2e18;

int n, m, p[100005];
ll d[100005];

std::vector<ii> graph[100005];

inline void jump_back(int x){if(p[x]+1) jump_back(p[x]); std::cout << x+1 << ' ';}

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, l;
        std::cin >> u >> v >> l;
        graph[--u].push_back({l, --v}); graph[v].push_back({l, u});
    }

//    for (int i = 0; i < n; i++) {
//        p[i] = -1;
//        d[i] = INF;
//    }

    std::fill(p, p+n+5, -1); std::fill(d, d+n+5, INF);

    std::priority_queue<ii> queue;
    queue.push({d[0] = 0, 0});

    while (!queue.empty()) {
        int u = queue.top().second; queue.pop();
        for (ii neighbour: graph[u]) {
            ll t = neighbour.first + d[u]; int v = neighbour.second;
            if (d[v] > t) {p[v] = u; queue.push({-(d[v] = t), v});
            }
        }
    }

    if(p[n-1]+1) jump_back(n-1); else std::cout << -1;


}


