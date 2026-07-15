/**
 * Author: KUNWAR
 * Date:   2026-07-15
 * Time:   23:27:06
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

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

template <typename T> vector<T> in(int n) { vector<T> v(n); for (T &x : v) cin >> x; return v; }
template <typename T> void out(const vector<T> &v) { for (const T &x : v) cout << x << ' '; cout << '\n'; }
template<typename T> vector<vector<T>> create2D(size_t rows, size_t cols, T default_value = T{}) { return vector<vector<T>>(rows, vector<T>(cols, default_value)); }
template <typename T> vector<vector<T>> in2D(int r, int c) { auto v = create2D<T>(r, c); for (auto &row : v) for (T &cell : row) cin >> cell; return v; }
template<typename T> void out2D(const vector<vector<T>>& vec) { for (size_t i = 0; i < vec.size(); ++i) { for (size_t j = 0; j < vec[i].size(); ++j) { cout << vec[i][j] << (j < vec[i].size() - 1 ? " " : ""); } cout << "\n"; } }

void solve() {
    l(n);
    vll p(n+1);
    ll inv = 0;
    f(i , 1 , n+1) {
        cin >> p[i];
        f(j , 1 , i) {
            if(p[j] > p[i]) inv++;
        }
    }
    
    if(n % 2 == 0 && inv % 2 != 0){
        cout << -1 << endl;
        return;
    }
    
    vll a(p.begin()+ 1 , p.end()); 
    vll ops;

    auto apply = [&](ll i) { 
        vll b;
        b.reserve(n);
        b.push_back(a[i]);
        f(k , 0 , i) b.push_back(a[k]);
        f(k , i+2 , n) b.push_back(a[k]);
        b.push_back(a[i+1]);
        a.swap(b);
        ops.push_back(i+1); 
    };
    ll lft = (n + 1) / 2;
    ll rt = (n % 2 == 0) ? lft + 1 : lft;
    if(n % 2 != 0) {
        lft--;
        rt++;
    }

    while(lft >= 1 && rt <= n) {
        ll l = -1, r = -1;
        f(k , 0, n) {
            if(a[k] == lft) l = k;
            if(a[k] == rt) r = k;
        }
        while(abs(l - r) > 1) {
            ll idx = min(l, r) + 1;
            apply(idx);
            f(k , 0 , n) {
                if(a[k] == lft) l = k;
                if(a[k] == rt) r = k;
            }
        }
        if(l > r) {
            apply(r); 
            f(k , 0 , n) {
                if(a[k] == lft) l = k;
                if(a[k] == rt) r = k;
            }
            while(abs(l - r) > 1) {
                ll idx = min(l, r) + 1;
                apply(idx);
                f(k, 0 , n) {
                    if(a[k] == lft) l = k;
                    if(a[k] == rt) r = k;
                }
            }
        }
        apply(l);
        lft--;
        rt++;
    }
    cout << ops.size() << endl;
    if(!ops.empty()) out(ops);
    else cout << endl;
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}