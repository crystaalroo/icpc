#include <bits/stdc++.h>
#define f first
#define s second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
using namespace std;

long long gcd(long long a, long long b){ return b? gcd(b, a%b) : a; }
long long lcm(long long a, long long b){ return (!a or !b)? 0 : a * b / gcd(a,b); } 
long long  poww(long long  a, long long b){
	long long res = 1;
	while(b){ 
		if(b%2) res = res * a ; 
		a = a * a;  b>>=1;
	} return res;
}

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int rnd(int n){return uniform_int_distribution<int>(0, n-1)(rng);}

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
template<class t,class u>bool mmax(t&a,u b){if(a<b)a=b;return a<b;}
template<class t,class u>bool mmin(t&a,u b){if(b<a)a=b;return b<a;}
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using li = long long;
using vi = vc<int>;
using ii = pair<int,int>;
// ---- しゃけ ツナマヨ ('-')7

int main(){_

	auto solve=[&](){

	};
	//int t; cin>>t; while(t--)
	solve();
}
