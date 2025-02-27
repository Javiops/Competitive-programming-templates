#include <bits/stdc++.h>
using namespace std;
 
#define int long long

vector<vector<int>> g, capacity;
vector<int> par;
int n, m; 


bool bfs(int s, int t){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        auto v = q.front();
        q.pop();
        
        for (int u : g[v]){
            if (capacity[v][u] > 0 && par[u] == -1){
                par[u] = v;
                q.push(u);
            }
        }
    }
    
    return (par[t] != -1);
}

int maximum_flow(int s, int t){
    int ans = 0;
    par.assign(n, -1);
    
    
    
    int flow = 0;
    while(bfs(s, t)){
        int v = t;
        int cur = 1e9 + 7;
        while(v != s){
            cur = min(cur, capacity[par[v]][v]);
            v = par[v];
        }
        
        v = t;
        while(v != s){
            capacity[par[v]][v] -= cur;
            capacity[v][par[v]] += cur;
            
            v = par[v];
        }
        par.assign(n, -1);
        ans += cur;
    }
    return ans;
}
 

signed main(){
    cin >> n >> m;
    
    g.resize(n);
    capacity.resize(n, vector<int> (n));
    
    for (int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        
        capacity[a][b] += c;
    }

    cout << maximum_flow(0, n - 1) << endl;
    
    
}
