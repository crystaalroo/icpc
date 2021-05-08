struct C{
	set<ii>s;
	int query(int u){
		auto p = s.lower_bound(ii{u,-1});
		if(p==s.begin())return 0;
		return prev(p)->s;
	}
	void add(int u, int d){
		int x = query(u);
		if(x<d){
			auto p = s.lower_bound(ii{u,-1});
			while(p!=s.end() and p->s<=d)p = s.erase(p);
			s.insert(ii{u,d});
		}
	}
};
