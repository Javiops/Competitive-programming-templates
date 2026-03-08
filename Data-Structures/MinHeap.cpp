struct MinHeap {
    
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void SiftDown(int i){
        int l = leftChild(i);
        int r = rightChild(i);
        int mn = i;
        int n = heap.size();
        
        if (l < n && heap[l] < heap[mn]){
            mn = l;
        }
        
        if (r < n && heap[r] < heap[mn]){
            mn = r;
        }
        
        if (mn != i){
            swap(heap[i], heap[mn]);
            SiftDown(mn);
        }
    }
    
    void SiftUp(int i){
        int p = parent(i);
        
        while(i > 0 && heap[p] > heap[i]){
            swap(heap[p], heap[i]);
            i = p;
            p = parent(i);
        }
    }
    
    int peek(){
        if (heap.empty()) return -1;
        return heap[0];
    }
    
    void pop(){
        if (heap.empty()) return;

        int n = heap.size();
        int v = heap.back();
        heap.pop_back();
        
        if (n > 1) {
            heap[0] = v; 
            SiftDown(0);
        }
    }
    
    void insert(int x){
        heap.push_back(x);
        
        int n = heap.size();
        SiftUp(n - 1);
    }
    
};
