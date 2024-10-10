#include <bits/stdc++.h>
using namespace std;


vector<int> p, s;
//vector<set<int>> g;


int get(int a){
    if (a != p[a]){
        p[a] = get(p[a]);
    }
    return p[a];
}

void unio(int a, int b){
    a = get(a);
    b = get(b);
    if (a != b){
    	if (s[a] > s[b]) swap(a, b);
    	p[a] = b;
    	s[b] += s[a];
    }
}


int main()
{
    int n, q;
    cin >> n >> q;
    //g.resize(n + 1);
    p.resize(n + 1);
    s.resize(n + 1);
    for (int i = 0; i <= n; i++) p[i] = i;
    for (int i = 0; i <= n; i++) s[i] = 1;
    for (int i = 0; i < q; i++){
        int t; cin >> t;
        if (t == 0){
            int u, v;
            cin >> u >> v;
            unio(u, v);
        }else{
            int u, v;
            cin >> u >> v;
            get(u);
            get(v);
            if (p[u] == p[v]) cout << "1" << endl;
            else cout << "0" << endl;
        }
    }
}
