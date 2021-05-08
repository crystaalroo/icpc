pair<int, int> f(int i) { return {(i) / 2, (i) % 2}; }

struct UF {
  vector<int> p;

  UF(int N) { p = vector<int>(N, -1); }

  int root(int a) {
    if(p[a] < 0) return a;
    return p[a] = root(p[a]);
  }

  lli size(int a) { return -p[root(a)]; }

  bool connect(int a, int b) {
    a = root(a);
    b = root(b);
    if(a == b) return false;
    if(size(a) < size(b)) swap(a, b);

    p[a] += p[b];
    p[b] = a;

    return true;
  }

  bool same(int a, int b) { return root(a) == root(b); }
};

struct mst {
  struct edge {
    int from, to, used;
    lli cost;

    edge(int x, int y, lli z) : from(x), to(y), cost(z) {}

    bool operator<(const edge& e) const { return cost < e.cost; }
  };

  int V;
  vector<int> p;
  vector<edge> es;

  mst(int _V) : V(_V), p(_V) {
    for(auto& i : p) i = -1;
  }

  void add(int u, int v, lli c) { es.emplace_back(u, v, c); }

  int root(int a) {
    if(p[a] < 0) return a;
    return p[a] = root(p[a]);
  }

  int size(int a) { return -p[root(a)]; }

  bool connect(int a, int b) {
    a = root(a);
    b = root(b);
    if(a == b) return false;
    if(size(a) < size(b)) swap(a, b);

    p[a] += p[b];
    p[b] = a;

    return true;
  }

  bool same(int a, int b) { return root(a) == root(b); }

  vector<edge> build() {
    sort(es.begin(), es.end());

    vector<edge> res;

    fore(i, 0, (lli)es.size()) {
      edge e = es[i];
      if(!same(e.from, e.to)) {
        connect(e.from, e.to);
        res.push_back(e);
      }
    }
    return res;
  }
};
