#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<set<int>> g, rev, scc;
stack<int> s;
vector<int> visited, component;
int numComp = 0;

void dfs(int v) {
    visited[v] = 1;
    for(int u : g[v]) {
        if(!visited[u]) dfs(u);
    }
    s.push(v);
}

void dfs2(int v) {
    component[v] = numComp;
    visited[v] = 1;
    for(int u : rev[v]) {
        if(!visited[u]) dfs2(u);
    }
}



signed main() {
    int n, m; cin >> n >> m;
    g.resize(n + 1);
    rev.resize(n + 1);
    visited.assign(n + 1, 0);
    component.resize(n + 1);
    
    
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].insert(b);
        rev[b].insert(a);
    }
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) dfs(i);
    }
    
    for(int i = 1; i <= n; i++) visited[i] = 0;
    
    while(!s.empty()) {
        int u = s.top();
        s.pop();
        if(!visited[u]) {
            dfs2(u);
            ++numComp;
        }
    }
    scc.resize(numComp);
    
    for (int i = 1; i <= n; i++){
        for (int u : g[i]){
            if (component[i] != component[u]) scc[component[i]].insert(component[u]);
        }
    }
    
}
