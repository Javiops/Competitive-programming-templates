//https://cses.fi/problemset/task/2072/

#include <bits/stdc++.h>
using namespace std;

mt19937 rng(1337);

struct tnode {
    int pri, size;
    char s;
    tnode *c[2];
    tnode (char t) {        
        pri = rng(), size = 1;
        s = t;
        c[0] = c[1] = NULL;
    }
};

int size(tnode *treap) { return treap ? treap->size : 0; }

void update(tnode *t) {
    if (t) {
        t->size = 1 + size(t->c[0]) + size(t->c[1]);
    }
}

pair<tnode*,tnode*> split(tnode* t, int k) { 
   // return left and right treaps containing lower and higher values, respectively
   // nodes with value >= v will go to the right
   if (!t) return {t,t};
   if (size(t->c[0]) >= k) { // our current node will be in the left treap
       auto p = split(t->c[0], k);
       t->c[0] = p.second; 
       
       update(t);
       
       return {p.first, t};
   } else { // our current node will be in the right treap
       auto p = split(t->c[1], k - size(t->c[0]) - 1);
       t->c[1] = p.first;
       
       update(t);
       
       return {t, p.second};
   }
}

tnode* merge(tnode* l, tnode* r) {
   if (!l) return r;
   if (!r) return l;
   if (l->pri > r->pri) { // maintain heap property, l will be topmost node of treap
       l->c[1] = merge(l->c[1],r);
       update(l);
       return l;
   } else {
       r->c[0] = merge(l,r->c[0]);
       update(r);
       return r;
   }
}

void print(tnode *t){
    if (!t) return;
    print(t->c[0]);
    cout << t->s;
    print(t->c[1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q; cin >> n >> q;
    string s; cin >> s;
    tnode *t = NULL;
    
    for (int i = 0; i < n; i++){
        t = merge(t, new tnode(s[i]));
    }
    while(q--){
        int l, r; cin >> l >> r;
        l--; r--;
        
        auto a = split(t, l);
        auto b = split(a.second, r - l + 1);
        
        t = merge(merge(a.first, b.second), b.first);
    }
    print(t);
    cout << endl;
}
