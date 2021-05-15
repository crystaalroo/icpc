const int mod = 1e9+7;

int Sum(li a, li b){
    return (a+b)%mod;
}

int Mul(li a, li b){
	a%=mod, b%=mod;
    return (a*b)%mod;
}

int Pow(long long  a, long long b){
	int res = 1;
	while(b){ 
		if(b%2) res = Mul(res,a);
		a = Mul(a,a);  b>>=1;
	} return res;
}

int Inv(li a){
    return Pow(a,mod-2);
}

