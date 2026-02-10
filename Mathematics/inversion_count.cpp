#include <bits/stdc++.h>
using namespace std;
 
#define int long long

//Complejidad por cada caso es O(n log mx), aunque no del todo pues tienes que crear un vector de tamaño 4 * mx
//Esto puede ser suficiente como para que resulte TLE entonces empleando coordinate compresion puedes reducir bastante el tiempo de ejecución

 
vector<int> a, t;
 
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
        t[v] += val;
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
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        int mx = 0, ans = 0;
        
        a.assign(n, 0);
        
        
        for (int i = 0; i < n; i++){
            cin >> a[i];
            mx = max(a[i], mx);
        }
        
        t.assign(4 * mx, 0);
        
        //build(1, 0, mx);
        for (int i = 0; i < n; i++){
            ans += get(1, 0, mx, a[i] + 1, mx);
            //cout << a[i] << ' ' << mx << ' ' << ans << endl;
            
            update(1, 0, mx, a[i], 1);
        }
        cout << ans << endl;
    }
    
}
