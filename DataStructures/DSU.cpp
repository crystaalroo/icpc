template <typename T = int> struct UnionFind {
    vector<int> pr;
    vector<int> sz;
    vector<T> data;

    UnionFind(int n, T def) {
        pr.assign(n, -1);
        sz.assign(n, 1);
        data.assign(n,def);
    }
    
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(size(x) < size(y)) swap(x, y);
        sz[x] += sz[y];
        pr[y] = x;
        data[x]+=data[y]; //edit
        return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int find(int x) {
        if(pr[x] < 0) return x;
        return (pr[x] = find(pr[x]));
    }

    int size(int x) { return sz[find(x)]; }
};
