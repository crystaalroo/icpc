int K = 10;
auto oper =[](int a, int b){return ;};
int st[K][1<<K];
void st_init(vi a){
  int n = sz(a);
	st[0]=a;
	fore(k,1,K)fore(i,0,n-(1<<k)+1)st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
int st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}
