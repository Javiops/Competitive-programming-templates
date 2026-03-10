//https://www.spoj.com/problems/ORDERSET/
//Treaps with pointers is really slow, 1.90 s with O(N log N) implementation

#include <bits/stdc++.h>
using namespace std;

mt19937 rng(1337);

struct tnode {
    int val, pri, size;
    tnode *c[2];
    tnode (int v) {        
        val = v, pri = rng(), size = 1;
        c[0] = c[1] = NULL;
    }
};

int size(tnode *treap) { return treap ? treap->size : 0; }

void update(tnode *t) {
    if (t) {
        t->size = 1 + size(t->c[0]) + size(t->c[1]);
    }
}

pair<tnode*,tnode*> split(tnode* t, int v) { 
   // return left and right treaps containing lower and higher values, respectively
   // nodes with value >= v will go to the right
   if (!t) return {t,t};
   if (t->val >= v) { // our current node will be in the right treap
       auto p = split(t->c[0], v);
       t->c[0] = p.second; 
       
       update(t);
       
       return {p.first, t};
   } else { // our current node will be in the left treap
       auto p = split(t->c[1], v);
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

bool search(tnode *t, int v){
    if (!t) return 0;
    if (t->val == v) return 1;
    if (t->val < v) return search(t->c[1], v);
    return search(t->c[0], v);
}

tnode* ins(tnode *t, int v) {
    auto a = split(t, v);  
    auto b = split(a.second, v + 1);
    
    if (!b.first) {
        b.first = new tnode(v);
    }
    
    return merge(merge(a.first, b.first), b.second);
}

tnode* del(tnode *t, int v) {
    auto a = split(t, v); 
    auto b = split(a.second, v + 1);

    return merge(a.first, b.second);
}

int kth(tnode *t, int k){
    if (!t || size(t) < k) return -1;
    if (k == 0) return t->val;
    
    if (k <= size(t->c[0])) {
        return kth(t->c[0], k);
    } else if (k == size(t->c[0]) + 1) {
        return t->val;
    } else {
        return kth(t->c[1], k - size(t->c[0]) - 1);
    }
}

int count(tnode *t, int v){
    if (!t) return 0;
    
    if (t->val < v){
        return size(t->c[0]) + 1 + count(t->c[1], v);
    }else{
        return count(t->c[0], v);
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    tnode *t = NULL;
    while(n--){
        char c;
        int v;
        cin >> c >> v;
        if (c == 'I'){
            t = ins(t, v);
        }else if (c == 'D'){
            t = del(t, v);
        }else if(c == 'K'){
            int ans = kth(t, v);
            if (ans == -1) cout << "invalid" << endl;
            else cout << ans << endl;
        }else{
            cout << count(t, v) << endl;
        }
    }
}
