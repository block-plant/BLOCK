/**
 * Author: KUNWAR
 * Date:   2026-03-07
 * Time:   20:55:35
**/

#include <bits/stdc++.h>
using namespace std;

// --- Type Definitions ---
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using ld = long double;

// --- Macros ---
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,a,b) for(ll i=a;i>=b;i--)
#define fkv(k, v, m) for(auto &[k, v] : m)
#define all(x) (x).begin(), (x).end()
#define get_sum(v, total) for(auto &x : v) total += x
#define cn continue
#define op(x) cout << x << endl

// --- Input Macros ---
#define read(...) __VA_ARGS__; read_input(__VA_ARGS__)
void read_input() {}
template<typename T, typename... Args>
void read_input(T& first, Args&... rest) { cin >> first; read_input(rest...); }
#define var(type, ...) type __VA_ARGS__; read_input(__VA_ARGS__)
#define i(x) int x; cin >> x
#define l(x) long long x; cin >> x
#define s(x) string x; cin >> x
#define c(x) char x; cin >> x

template <typename T> vector<T> in(int n) { vector<T> v(n); for (T &x : v) cin >> x; return v; }
template <typename T> void out(const vector<T> &v) { for (const T &x : v) cout << x << ' '; cout << '\n'; }
template<typename T> vector<vector<T>> create2D(size_t rows, size_t cols, T default_value = T{}) { return vector<vector<T>>(rows, vector<T>(cols, default_value)); }
template <typename T> vector<vector<T>> in2D(int r, int c) { auto v = create2D<T>(r, c); for (auto &row : v) for (T &cell : row) cin >> cell; return v; }
template<typename T> void out2D(const vector<vector<T>>& vec) { for (size_t i = 0; i < vec.size(); ++i) { for (size_t j = 0; j < vec[i].size(); ++j) { cout << vec[i][j] << (j < vec[i].size() - 1 ? " " : ""); } cout << "\n"; } }

ll find_mex(vll& arr) 
{
    unordered_set<ll> num_set(arr.begin(), arr.end());
    for(ll i = 0; i <= arr.size(); i++) 
    {
        if(num_set.find(i) == num_set.end()) return i;
    }
    return -1; 
}

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    l(n);
    l(m);

    int i = 0 ; 
    ll temp = n ; 

    vpll keeper(n) ; 
    ll ans = 0 ;
    while(temp--)
    {
        l(size);
        auto arr = in<ll>(size);
        ll mex_mx = find_mex(arr); 
        ll put = mex_mx ; 
        arr.push_back(mex_mx);
        mex_mx = find_mex(arr);
        keeper[i] = {put , mex_mx};
        ans = max(ans , keeper[i].second);
        i++ ;  
    }
    
    ll printing = 0 ;
    if(m <= ans) 
    {
        printing = 1LL*(m + 1)*ans; 
    } 
    else 
    {
        printing = 1LL*(ans+1)*ans;
        ll count = m - ans;
        ll fst = ans + 1;
        ll lst = m;
        printing += (count * (fst + lst)) / 2;
    }
    
    cout << printing << endl;
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}