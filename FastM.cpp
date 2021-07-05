const int mod = 1e9+7;

li Sum(li a, li b){
	a = (a%mod + mod)%mod;
	b = (b%mod + mod)%mod;
    return (a+b)%mod;
}

li Mul(li a, li b){
	a = (a%mod + mod)%mod;
	b = (b%mod + mod)%mod;
    return (a*b)%mod;
}

li Pow(long long  a, long long b){
	int res = 1;
	while(b){ 
		if(b%2) res = Mul(res,a);
		a = Mul(a,a);  b>>=1;
	} return res;
}

li Inv(li a){
    return Pow(a,mod-2);
}

