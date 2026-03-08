/**
 * Author: KUNWAR
 * Date:   2026-03-08
 * Time:   21:54:05
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
#define i(x) char x; cin >> x

template <typename T> vector<T> in(int n) { vector<T> v(n); for (T &x : v) cin >> x; return v; }
template <typename T> void out(const vector<T> &v) { for (const T &x : v) cout << x << ' '; cout << '\n'; }
template<typename T> vector<vector<T>> create2D(size_t rows, size_t cols, T default_value = T{}) { return vector<vector<T>>(rows, vector<T>(cols, default_value)); }
template <typename T> vector<vector<T>> in2D(int r, int i) { auto v = create2D<T>(r, i); for (auto &row : v) for (T &cell : row) cin >> cell; return v; }
template<typename T> void out2D(const vector<vector<T>>& vec) { for (size_t i = 0; i < vec.size(); ++i) { for (size_t j = 0; j < vec[i].size(); ++j) { cout << vec[i][j] << (j < vec[i].size() - 1 ? " " : ""); } cout << "\n"; } }

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void solve() {
    l(n); 
    l(h);
    auto a = in<ll>(n);

    const ll INF = 2e18;
    vll pref(n, INF), suff(n, INF);

    f(i , 0 , n) 
    { 
        if(a[i] == h) cn; 
        ll cur = 0, mx = a[i];
        
        fr(j , i , 0) 
        {
            mx = max(mx, a[j]);
            cur += mx;
        }
       
        pref[i] = min(pref[i], cur);
       
        ll cur_total = cur;
        ll mx_right = a[i];
        f(j, i+1 , n) 
        {
            mx_right = max(mx_right, a[j]);
            cur_total += mx_right;
            pref[j] = min(pref[j], cur_total);
        }
    }

    fr(i, n - 1, 0) 
    {
        if(a[i] == h) cn;
        ll cur = 0, mx = a[i];
        
        f(j , i , n) 
        {
            mx = max(mx, a[j]);
            cur += mx;
        }
        suff[i] = min(suff[i], cur);

        ll cur_total = cur;
        ll mx_left = a[i];
        fr(j , i-1 , 0) 
        {
            mx_left = max(mx_left, a[j]);
            cur_total += mx_left;
            suff[j] = min(suff[j], cur_total);
        }
    }

    ll ans = pref[n-1];
    f(i , 0 , n-1) 
    {
        if(pref[i] < 1e18 && suff[i+1] < 1e18)
        {
            ans = min(ans, pref[i] + suff[i+1]);
        }
    }

    if(ans >= 1e18) cout << 0 << endl;
    else cout << n * h - ans<< endl;
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}