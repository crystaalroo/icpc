struct DominatorTree{
	int n;
	vector<vector<int>>G,rG;
	vector<int>semi,id,rid,par,mn,anc;
	DominatorTree(int n): n(n),G(n),rG(n),semi(n),id(n,-1),rid(n),par(n,-1),mn(n),anc(n){
    for(int i=0;i<n;i++)semi[i]=mn[i]=anc[i]=i;
	}
	void addEdge(int a,int b){
		G[a].push_back(b);rG[b].push_back(a);
	}
	int find(int v){
		if(anc[v]==v)return v;
		int a=find(anc[v]);
		if(id[semi[mn[anc[v]]]]<id[semi[mn[v]]])mn[v]=mn[anc[v]];
		return anc[v]=a;
	}

	void link(int c,int p){
		anc[c]=p;
	}

	void dfs(int v,int p,int &k){
		id[v]=k;
		rid[k++]=v;
		par[v]=p;
		for(int c:G[v])if(id[c]==-1)dfs(c,v,k);
	}

	vector<int>calc(int root){
		int sz=0;
		dfs(root,-1,sz);
    vector<int>us(n);
    vector<vector<int>>bucket(n);
		for(int i=sz-1;i>0;i--){
			int w=rid[i];
			for(int v:rG[w])if(id[v]!=-1){
				find(v);
				if(id[semi[mn[v]]]<id[semi[w]])semi[w]=semi[mn[v]];
			}
			bucket[semi[w]].pb(w);
			for(int v:bucket[par[w]]){
				find(v);
				us[v]=mn[v];
			}
			bucket[par[w]].clear();
			link(w,par[w]);
		}
    vector<int>idom(n,-1);
		for(int i=1;i<sz;i++){
			int w=rid[i];
			if(semi[w]==semi[us[w]])idom[w]=semi[w];
			else idom[w]=idom[us[w]];
		}
		return idom;
	}
};
