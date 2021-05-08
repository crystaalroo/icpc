struct Dsu {
  vector<int> parents;
  vector<int> sizes;
  vector<array<int, 2>> history;
	int tot;

  Dsu(int n=1) {
    parents.resize(n);
    iota(all(parents), 0);
    sizes.assign(n, 1);
		tot = n;
  }

  int find(int x) {
    if (x == parents[x]) { return x; }
    return find(parents[x]);
  }

  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) { return 0; }
    if (sizes[x] > sizes[y]) { swap(x, y); }
    parents[x] = y;
    sizes[y] += sizes[x];
    history.push_back({x, y});
		tot--;
		return 1;
  }

  void rollback() {
    if(history.empty())return;
    auto [x, y] = history.back(); history.pop_back();
    parents[x] = x;
		tot++;
    sizes[y] -= sizes[x];
  }
};

struct Query{
	int a,b,c;
	Query(int a, int b):a(a),b(b),c(0){}
};

struct QTree{
	#define mid (l + r) / 2
	#define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
	vc<vc<Query>> st;
	Dsu dsu;
	QTree(int n, int v):st(2*n+5){
			dsu = Dsu(v);
	}

	void add(int u, int l, int r, int ll, int rr, Query v){
		if(r < ll or l > rr or l>r) return;
		if(ll ==l and r == rr){
			st[u].pb(v);
			return;
		}
		add(left(u), l, mid, ll, min(rr,mid), v);
		add(right(u), mid+1, r, max(ll,mid+1), rr, v);
	}

	void dfs(int u, int l, int r, vc<int>&ans){
		for(auto &i:st[u])i.c=dsu.unite(i.a, i.b);
		if(l==r)ans[l]=dsu.tot;
		else{
			dfs(left(u),l,mid,ans);
			dfs(right(u),mid+1,r,ans);
		}
		for(auto &i:st[u])if(i.c)dsu.rollback();
	}

};
