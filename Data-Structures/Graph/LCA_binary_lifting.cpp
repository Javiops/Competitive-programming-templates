#include <bits/stdc++.h>
using namespace std;
#define int long long

const int LOG = 30;

vector<vector<int>> g, parent;
vector<int> depth;

void dfs(int v, int par, int cnt){
    
    if (par != -1) parent[v][0] = par;

    for (int i = 0; i < LOG; i++){
        if (parent[v][i] != -1 && parent[parent[v][i]][i] != -1){
            parent[v][i + 1] = parent[parent[v][i]][i];
        }else break;
    }
    
    
    depth[v] = cnt;
    for (int u : g[v]){
        if (u != par){
            dfs(u, v, cnt + 1);
        }
    }
}

int find_lca(int a, int b){
    if (depth[a] > depth[b]) swap(a, b);
    for (int i = LOG - 1; i >= 0; i--){
        if (parent[b][i] != -1 && depth[parent[b][i]] >= depth[a]){
            b = parent[b][i];
        }
    }
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; i--){
        if (parent[b][i] != -1 && parent[a][i] != -1 && parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    a = parent[a][0];
    return a;
}

