//https://cses.fi/problemset/task/1688

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 4e5 + 100;

int n, m;
int a[N];
vector<int> t(4 * N);
int ett[N], st[N];
int cur = 0;
vector<int> g[N];
vector<int> depth(N, 1e9);

void dfs(int v, int par, int d) {
    st[v] = cur;
    ett[cur++] = v;
    depth[v] = d;
    
    for (int u : g[v]) {
        if (u != par){
            dfs(u, v, d + 1);
            ett[cur++] = v;
        }
    }
}

int mn_id(int x, int y){
    if (x == -1) return y;
    if (y == -1) return x;
    
    if (depth[x] < depth[y]) return x;
    else return y;
}

void build(int v, int vl, int vr) {
    
    if (vl == vr) {
        t[v] = ett[vl];
        return;
    }
    
    int vm = (vl + vr) / 2;
    build(2 * v, vl, vm);
    build(2 * v + 1, vm + 1, vr);
    
    t[v] = mn_id(t[2 * v], t[2 * v + 1]);
}



int get(int v, int vl, int vr, int l, int r) {
    if (vl > r || vr < l) return -1;
    
    if (vl >= l && vr <= r) {
        return t[v];
    }
    
    int vm = (vl + vr) / 2;
    return mn_id(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm + 1, vr, l, r));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        p--;
        g[p].push_back(i);
    }

    dfs(0, -1, 0);

    build(1, 0, 2 * n - 1);

    while (m--) {
       int x, y; cin >> x >> y;
       x--; y--;
       int l = min(st[x], st[y]);
       int r = max(st[x], st[y]);
            
        cout << get(1, 0, 2*n - 1, l, r) + 1 << endl;
        
    }

}
