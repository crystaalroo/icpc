
struct rolling_hash{
 // !!! ハッシュはullで受け取ること !!!
 // 文字列の中に0があると，その値が影響しなくなって壊れるので注意！
 // generate_base は結構遅いので，何回も呼び出す必要がある場合は何度も呼ばない方が良い
 typedef unsigned int ui;
 typedef unsigned long long ull;

 const ull MASK30 = (1ull<<30) - 1;
 const ull MASK31 = (1ull<<31) - 1;
 const ull MOD = (1ull<<61) - 1;
 const ull POSITIVISER = MOD * ((1ull<<3) - 1);
 ui base;
 int n;
 vector<ull> pw, hs;

 rolling_hash(){}

 rolling_hash(const string &s, int bs){
   // set base
   base = (ui)bs;

   n = s.size();
   hs.assign(n+1, 0);
   pw.assign(n+1, 0);
   hs[0] = 0;
   pw[0] = 1;
   for(int i=0;i<n;i++){
     pw[i+1] = calc_mod(mul(pw[i], base));
     hs[i+1] = calc_mod(mul(hs[i], base) + s[i]);
   }
 }

 ull hash(int l, int r){
   return calc_mod(hs[r] + POSITIVISER - mul(hs[l], pw[r-l]));
 }

 ull mul(ull l, ull r){
   ull lu = l>>31;
   ull ld = l & MASK31;
   ull ru = r>>31;
   ull rd = r & MASK31;
   ull middle_bit = ld * ru + lu * rd;
   return ((lu*ru)<<1) +ld*rd + ((middle_bit & MASK30) << 31) + (middle_bit>>30);
 }

 ull mul(ull l, ui r){
   ull lu = l>>31;
   ull rd = r & MASK31;
   ull middle_bit = lu * rd;
   return (l & MASK31) * rd + ((middle_bit & MASK30)<<31) + (middle_bit>>30);
 }

 ull calc_mod(ull val){
   val = (val & MOD) + (val>>61);
   if(val > MOD) val -= MOD;
   return val;
 }
};

int generate_base(){
 random_device seed_gen;
 mt19937_64 rnd(seed_gen());
 uniform_int_distribution<int> dist(129, INT_MAX);
 int base = dist(rnd);
 return base;
}
