vector<int> p, s;

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

void initialize(int n){
    p.resize(n + 1);
    s.resize(n + 1);
    for (int i = 0; i <= n; i++) p[i] = i;
    for (int i = 0; i <= n; i++) s[i] = 1;
}
