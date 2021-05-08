struct Dsu {
  vector<int> parents;
  vector<int> sizes;
  vector<array<int, 2>> history;
  vector<int> checkpoints;

  Dsu(int n) {
    parents.resize(n);
    iota(all(parents), 0);
    sizes.assign(n, 1);
  }

  int find(int x) {
    if (x == parents[x]) { return x; }
    return find(parents[x]);
  }

  void unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) { return; }
    if (sizes[x] > sizes[y]) { swap(x, y); }

    parents[x] = y;
    sizes[y] += sizes[x];
    history.push_back({x, y});
  }

  void persist() {
    checkpoints.push_back(history.size());
  }

  void rollback() {
    int c = checkpoints.back(); checkpoints.pop_back();
    while ((int)history.size() > c) {
      auto [x, y] = history.back(); history.pop_back();
      parents[x] = x;
      sizes[y] -= sizes[x];
    }
  }
};
