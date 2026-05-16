/**
 * Author: KUNWAR
 * Date:   2026-05-16
 * Time:   20:26:59
**/

#include <bits/stdc++.h>
#include <climits>
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
    l(a);
    l(n);
    auto d = in<ll>(n);
    
    string s = to_string(a);
    ll len = s.size();
    ll ans = LLONG_MAX ;

    ll other = 0 ; 
    f(i , 0 , len - 1) {
        other = other * 10 + d[1] ;
    }
    if(len > 1) ans = min(ans , a - other);

    ll lng = d[d[0] == 0];
    f(i , 0 , len) {
        lng = lng * 10 + d[0];
    }
    ans = min(ans , lng - a);

    auto dfs = [&](auto& self , ll val , ll cur , ll idx)->void {
        if(idx == len) {
            ans = min(ans , abs(a - val));
            return;
        }
        
        for(ll x : d) {
            if(cur == 1) {
                self(self , val * 10 + d[0] , 1 , idx+1);
                break;
            }
            if(cur == -1) {
                self(self , val * 10 + d[1] , -1 , idx+1);
                break;
            }

            ll st = (x > s[idx] - '0') ? 1 : ((x < s[idx] -'0') ? -1 : 0);
            self(self , val * 10 + x , st , idx+1);
        }
    };

    
    dfs(dfs , 0 , 0 , 0);
    cout << ans << endl;
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}