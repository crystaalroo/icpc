long long gcd(long long a, long long b){ return b? gcd(b, a%b) : a; }
long long lcm(long long a, long long b){ return (!a or !b)? 0 : a * b / gcd(a,b); } 
long long  poww(long long  a, long long b){
	long long res = 1;
	while(b){ 
		if(b%2) res = res * a ; 
		a = a * a;  b>>=1;
	} return res;
}
