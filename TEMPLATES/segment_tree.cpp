#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int N = 2e5 + 5;
int n, m;
vector<int> a(N), t(N * 4);
 
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
 
 
void update(int v, int vl, int vr, int pos, int val) {
    if (vr < pos || vl > pos) return;
    
    if (vl == vr) {
        t[v] = val;
        a[vl] = val;
        return;
    }
    int vm = (vl + vr) / 2;
    
    update(2 * v, vl, vm, pos, val);
    update(2 * v + 1, vm + 1, vr, pos, val);
 
    t[v] = t[2 * v] + t[2 * v + 1];
}
 
int get(int v, int vl, int vr, int l, int r) {
    if (vl > r || vr < l) return 0;
    if (vr <= r && l <= vl){
        return t[v];
    }
    int vm = (vl + vr) / 2;
    
    return get(2 * v, vl, vm, l, r) + get(2 * v + 1, vm + 1, vr, l, r);
}
 
signed main()
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    build(1, 0, n - 1);
    while(m--){
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1){
            update(1, 0, n - 1, l, r);
        }else{
            r--;
            cout << get(1, 0, n - 1, l, r) << endl;
        }
    }
}
