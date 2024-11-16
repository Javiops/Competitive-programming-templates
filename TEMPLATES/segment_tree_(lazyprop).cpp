//Adition and sum
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 10;
vector<int> a;
vector<int> t(4 * N), lazy(4 * N);

void push(int v, int vl, int vr){
    if (lazy[v]){
            int vm = (vl + vr) / 2;
            t[2 * v] += lazy[v] * (vm - vl + 1);
            t[2 * v + 1] += lazy[v] * (vr - vm);   
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
            lazy[v] = 0;   
    }
}

void build(int v, int vl, int vr) {
    if (vl == vr) {
        t[v] = a[vl];
        return;
    }
    int vm = (vl + vr) / 2;
    
    build(2 * v, vl, vm);
    build(2 * v + 1, vm + 1, vr);
    t[v] = t[2 * v] + t[2 * v + 1];
}

void update(int v, int vl, int vr, int l, int r, int x){
    if (vl > r || vr < l) return;
    if (vl >= l && vr <= r){
        t[v] += x * (vr - vl + 1);
        lazy[v] += x;
        return;
    }
    push(v, vl ,vr);
    int vm = (vl + vr) / 2;
    
    update(2 * v, vl, vm, l, r, x);
    update(2 * v + 1, vm + 1, vr, l, r, x);

    t[v] = t[2 * v] + t[2 * v + 1];
}

int get(int v, int vl, int vr, int l, int r){
    if (vl > r || vr < l) return 0;
    if (vr <= r && l <= vl){
        
        return t[v];
    }
    push(v, vl, vr);
    int vm = (vl + vr) / 2;
    
    return get(2 * v, vl, vm, l, r) + get(2 * v + 1, vm + 1, vr, l, r);
    
}

signed main()
{
    int n, m; cin >> n >> m;

    while(m--){
        int tt; cin >> tt;
        if (tt == 1){
            int l, r, x;
            cin >> l >> r >> x;
            r--;
            update(1,0 , n - 1, l, r, x);
        }else{
            int l, r; cin >> l >> r;
            r--;
            cout << get(1, 0, n - 1, l, r) << endl;
        }
    }
}
