struct StronglyConnectedComponents {
	int n, group_num, now_ord;
	vector<vector<int>> g;
	vector<int> low, ord, idx;
	StronglyConnectedComponents(int _n) :n(_n), low(n), ord(n, -1), idx(n), g(n), group_num(0), now_ord(0) {}
	void add_edge(int from, int to) {
		g[from].emplace_back(to);
	}
	void dfs(int cur, vector<int> &visited) {
		ord[cur] = low[cur] = now_ord++;
		visited.emplace_back(cur);
		for (auto nxt : g[cur]) {
			if (ord[nxt] == -1) {
				dfs(nxt, visited);
				low[cur]=min(low[cur], low[nxt]);
			}
			else {
				low[cur]=min(low[cur], ord[nxt]);
			}
		}
		if (ord[cur] == low[cur]) {
			while (true) {
				int v = visited.back();
				visited.pop_back();
				ord[v] = n; //別のdfs木からこないように
				idx[v] = group_num;
				if (cur == v) break;
			}
			group_num++;
		}
	}

	//sccのidxに入ってる頂点番号 idxはトポロジカル順
	vector<vector<int>> build() {
		vector<int> visited;
		for (int i = 0; i < n; i++) if (ord[i] == -1) dfs(i, visited);
		for (int i = 0; i < n; i++) idx[i] = group_num - 1 - idx[i];
		vector<vector<int>> groups(group_num);
		for (int i = 0; i < n; i++) {
			groups[idx[i]].emplace_back(i);
		}
		return groups;
	}
};
