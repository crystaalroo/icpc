lli res =0;
vc<ii> f,g;
void dc(int l, int r, int L, int R){
	if(l>r)return;
	int mid = (l+r)/2;
	int pos = R;
	lli tmp = -inf<lli>;
	auto cost = [&](int i){
		return 1ll * (g[i].s+f[mid].s) * (g[i].f-f[mid].f);
	};
	fore(i,L,R+1){
		if(tmp < cost(i)){
			tmp = cost(i); // modificar esto.
			pos = i;
		}
	}
	res=max(res,tmp);
	dc(l,mid-1,L,pos);
	dc(mid+1,r,pos,R);
}
