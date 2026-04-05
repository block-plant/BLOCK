/**
 * Author: KUNWAR
 * Date:   2026-04-05
 * Time:   23:25:00
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

ll solve(vll&r , vll&g , vll&b , ll&ans) 
{
    ll nr = r.size();
    ll ng = g.size();
    ll nb = b.size();
    
    f(i , 0 , ng)
    {
        ll g_val = g[i];
        
        auto it = upper_bound(all(r) , g_val);
        if(it == r.begin()) continue ;
        ll r_val = *(--it) ;

        auto its = lower_bound(all(b) , g_val);
        if(its == b.end()) continue ; 
        ll b_val = *(its) ; 

        ll diff1 = abs(r_val - g_val) ;
        ll diff2 = abs(b_val - r_val) ;
        ll diff3 = abs(g_val - b_val) ;
        
        ll val = 1LL*diff1*diff1 + 1LL*diff2*diff2 + 1LL*diff3*diff3 ; 

        ans = min(ans , val);
    }   
    return ans ;
}

int main() {
    fastio();
    l(t);
    while(t--) {
        l(nr);
        l(ng);
        l(nb);
        
        auto r = in<ll>(nr);
        auto g = in<ll>(ng);
        auto b = in<ll>(nb);
        
        ll ans = LLONG_MAX ;
        
        sort(all(r));
        sort(all(g));
        sort(all(b));

        ans = solve(r , g , b , ans);
        ans = solve(g , b , r , ans);
        ans = solve(b , r , g , ans);
        ans = solve(r , b , g , ans);
        ans = solve(g , r , b , ans);
        ans = solve(b , g , r , ans);

        op(ans);
    }
    return 0;
}