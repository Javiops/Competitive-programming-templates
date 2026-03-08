struct BST{
    struct Node {
        int key, l, r;
    
        Node(int val){
            key = val;
            l = -1;
            r = -1;
        }
    };
    
    vector<Node> tree;
    vector<int> free_nodes;
    int root = -1;
    
    int search(int x){
        int id = root;
        while(id != -1 && tree[id].key != x){
            if (tree[id].key < x){
                id = tree[id].r;
            }else{
                id = tree[id].l;
            }
        }
        return id;
    }
    
    int succesor(int x){
        int id = root;
        int succ = -1;
        
        while(id != -1){
            if (tree[id].key > x){
                succ = id;       
                id = tree[id].l; 
            } else {
                id = tree[id].r; 
            }
        }
        return succ;
    }
    
    int predecessor(int x){
        int id = root;
        int pred = -1;
        
        while(id != -1){
            if (tree[id].key < x){
                pred = id;       
                id = tree[id].r; 
            } else {
                id = tree[id].l; 
            }
        }
        return pred;
    }
    
    void insert(int x){
        Node nuevo(x);
        
        if (root == -1){
            root = 0;
            if (tree.empty()) tree.push_back({nuevo});
            else tree[root] = nuevo;
            
            return;
        }
        
        int id = root, p = -1;
        while(id != -1){
            p = id;
            if (tree[id].key < x){
                id = tree[id].r;
            }else{
                id = tree[id].l;
            }
        }
        
        if (free_nodes.empty()) {
            id = tree.size();
            tree.push_back({nuevo});
        }else {
            id = free_nodes.back();
            free_nodes.pop_back();
            
            tree[id] = nuevo;
        }
        
        if (x < tree[p].key) tree[p].l = id;
        else tree[p].r = id;
    }
    
    void erase(int x){
        int z = root;
        int p = -1;
        
        while(z != -1 && tree[z].key != x){
            p = z;
            if(x < tree[z].key){
                z = tree[z].l;
            }else{
                z = tree[z].r;
            }
        }
        
        if(z == -1) return;
        
        if(tree[z].l == -1){
            if(p == -1) root = tree[z].r;
            else if(tree[p].l == z) tree[p].l = tree[z].r;
            else tree[p].r = tree[z].r;
            
            free_nodes.push_back(z);
        }else if(tree[z].r == -1){
            if(p == -1) root = tree[z].l;
            else if(tree[p].l == z) tree[p].l = tree[z].l;
            else tree[p].r = tree[z].l;
            
            free_nodes.push_back(z);
        }else{
            int y = tree[z].r;
            int y_p = z;
            
            while(tree[y].l != -1){
                y_p = y;
                y = tree[y].l;
            }
            
            if(y_p != z){
                if(tree[y_p].l == y) tree[y_p].l = tree[y].r;
                else tree[y_p].r = tree[y].r;
                
                tree[y].r = tree[z].r;
            }
            
            if(p == -1) root = y;
            else if(tree[p].l == z) tree[p].l = y;
            else tree[p].r = y;
            
            tree[y].l = tree[z].l;
            free_nodes.push_back(z);
        }
    }
};
