template <typename T = int, typename L = int>  LazyST{
  #define mid (l + r)/2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  vector<T>st;  T bad;
  vector<L>lazy; L nulo;

  T op(T a, T b){return a+b; } // operacion de merge
  T cmp(T a, T b){return a+b; } //operacion en query


  LazyST(int n, T ini, L nulo, T bad):st(2*n,ini), lazy(2*n,nulo) nulo(nulo), bad(bad){}

  void push(int u, int l, int r){
    if(l<r and lazy[u]!=nulo){
      st[left(u)] += lazy[u];
      st[right(u)] += lazy[u];

      lazy[left(u)] += lazy[u];
      lazy[right(u)] += lazy[u];

      lazy[u]= nulo;
    }
  }

  void update(int u, int l, int r, int ll, int rr, T x){
    push(u, l, r);
    if(r < ll or l > rr or l>r) return;
    if(ll <= l and r <= rr){
      //
      return;
    }
    update(left(u), l, mid, ll, rr, x);
    update(right(u), mid + 1, r, ll, rr, x);
    st[u] = op(st[left(u)],st[right(u)]);
  }

  T query(int u, int l, int r, int ll, int rr){
    push(u, l, r);
    if(r < ll or l > rr or l>r) return bad;
    if(ll <= l and r <= rr)return st[u];
    return cmp(query(left(u),l,mid,ll,rr),query(right(u),mid+1,r,ll,rr));
  }
};
