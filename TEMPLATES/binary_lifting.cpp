#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> g;
vector<vector<int>> parent;

void dfs(int v, int par){

    if (v != 1) parent[v][0] = par; //root?
    
    for (int bit = 1; bit < 20; bit++){
        if (parent[v][bit - 1] == -1 || parent[parent[v][bit - 1]][bit - 1] == -1) break;
        
        parent[v][bit] = parent[parent[v][bit - 1]][bit - 1];
    }
    
    
    
    
    for (int u : g[v]){
        if (u != par){
            dfs(u, v);
        }
    }
}

signed main()
{
    int n, q; cin >> n >> q;
    g.resize(n + 1);
    parent.resize(n + 1, vector<int> (20, -1));
    
    for (int i = 2; i <= n; i++){
        
        int x; cin >> x;
        g[x].push_back(i);
        
    }
    
    dfs(1, 0);
    
    while(q--){
        int x, k; cin >> x >> k;
        
        //cout << x << ' ' << k << endl;
        
        for (int bit = 19; bit >= 0 && x != -1; bit--){
            if (k & (1LL << bit)){
                x = parent[x][bit];
                k -= (1LL << bit);
            }
        }
        cout << x << endl;
    }
    
}
