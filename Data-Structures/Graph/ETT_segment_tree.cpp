//https://cses.fi/problemset/task/1137/


#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;

int n, m;
int a[N];
int t[N * 4];
int st[N], en[N];
int cur = 0;
vector<int> g[N];

void dfs(int v, int par) {
    st[v] = cur;
    cur++;
    for (int u : g[v]) {
        if (u != par)
            dfs(u, v);
    }
    en[v] = cur - 1;
}

void update(int v, int vl, int vr, int pos, int val) {
    if (vr < pos || vl > pos) return;
    
    if (vl == vr) {
        t[v] = val;
        return;
    }
    
    int vm = (vl + vr) / 2;
    update(2 * v, vl, vm, pos, val);
    update(2 * v + 1, vm + 1, vr, pos, val);
    
    t[v] = t[2 * v] + t[2 * v + 1];
}

int get(int v, int vl, int vr, int l, int r) {
    if (vl > r || vr < l) return 0;
    
    if (vl >= l && vr <= r) {
        return t[v];
    }
    
    int vm = (vl + vr) / 2;
    return get(2 * v, vl, vm, l, r) + get(2 * v + 1, vm + 1, vr, l, r);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1);

    for (int i = 0; i < n; i++) {
        update(1, 0, n - 1, st[i], a[i]);
    }

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s, x;
            cin >> s >> x;
            s--;
            update(1, 0, n - 1, st[s], x);
        } else {
            int s;
            cin >> s;
            s--;
            cout << get(1, 0, n - 1, st[s], en[s]) << endl;
        }
    }

}
