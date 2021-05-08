template <typename T> vector<int> z_algorithm(vector<T> &s) {
    int n = sz(s);
    vector<int> res(n);
    for(int i = 1, j = 0; i < n; i++) {
        if(i + res[i - j] < j + res[j]) res[i] = res[i - j];
        else {
            int k = max(0, j + res[j] - i);
            while(i + k < n and s[k] == s[i + k]) ++k;
            res[i] = k, j = i;
        }
    }
    res[0] = n;
    return res;
}
