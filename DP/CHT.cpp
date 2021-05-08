struct Line {
    mutable lli k, m, p;
    bool operator<(const Line &o) const { return k < o.k; }
    bool operator<(double x) const { return p < x; }
};

struct LineContainer: multiset<Line,less<>>{
	lli div(lli a, lli b){return a/b -((a^b)<0 and a%b);}

	bool isect(iterator x, iterator y){
		if(y==end()){x->p=INF;return false;}
		if(x->k==y->k)x->p=x->m>y->m?INF:-INF;
		else x->p = div(y->m-x->m,x->k-y->k);
		return x->p>=y->p;
	}

	void add(lli k, lli m){
		auto z = insert({k,m,0}),y=z++,x=y;
		while(isect(y,z))z=erase(z);
		if(x!=begin() and isect(--x,y))isect(x,y=erase(y));
		while((y=x)!=begin() and (--x)->p>=y->p)isect(x,erase(y));
	}

	lli query(lli x){
		assert(!empty());
		auto l =*lower_bound(x);
		return l.k*x+l.m;
	 }
};
