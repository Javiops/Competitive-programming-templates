

struct BST {
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

    int newNode(int key) {
        if (!free_nodes.empty()) {
            int idx = free_nodes.back();
            free_nodes.pop_back();
            tree[idx] = Node(key);
            return idx;
        }
        tree.emplace_back(key);
        return (int)tree.size() - 1;
    }
    
    void insert(int key) {
        if (root == -1) { root = newNode(key); return; }
        int curr = root;
        while (true) {
            if (key < tree[curr].key) {
                if (tree[curr].l == -1) { 
                    int nxt = newNode(key);
                    tree[curr].l = nxt; 
                    break; 
                }
                curr = tree[curr].l;
            } else if (key > tree[curr].key) {
                if (tree[curr].r == -1) { 
                    int nxt = newNode(key); 
                    tree[curr].r = nxt; 
                    break; 
                }
                curr = tree[curr].r;
            } else break;
        }
    }
    
    void remove(int key) {
        root = erase(root, key);
    }

    int getMin(int curr) {
        while (tree[curr].l != -1) curr = tree[curr].l;
        return curr;
    }

    int erase(int curr, int key) {
        if (curr == -1) return -1;

        if (key < tree[curr].key) {
            tree[curr].l = erase(tree[curr].l, key);
        } else if (key > tree[curr].key) {
            tree[curr].r = erase(tree[curr].r, key);
        } else {
            if (tree[curr].l == -1 || tree[curr].r == -1) {
                int temp = (tree[curr].l != -1) ? tree[curr].l : tree[curr].r;
                free_nodes.push_back(curr); 
                return temp;
            } else {
                int temp = getMin(tree[curr].r);
                tree[curr].key = tree[temp].key;
                tree[curr].r = erase(tree[curr].r, tree[temp].key);
            }
        }
        return curr;
    }
    
    bool search(int key) {
        int curr = root;
        while (curr != -1) {
            if (key == tree[curr].key) return true;
            curr = (key < tree[curr].key) ? tree[curr].l : tree[curr].r;
        }
        return false;
    }
};
