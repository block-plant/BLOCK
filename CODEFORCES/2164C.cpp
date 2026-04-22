/**
 * Author: KUNWAR
 * Date:   2026-04-22
 * Time:   23:45:30
**/
#include <bits/stdc++.h>
using namespace std;

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

#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,a,b) for(ll i=a;i>=b;i--)
#define fkv(k, v, m) for(auto &[k, v] : m)
#define all(x) (x).begin(), (x).end()
#define get_sum(v, total) for(auto &x : v) total += x
#define cn continue
#define op(x) cout << x << endl

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
    l(m);
    
    vll a = in<ll>(n);
    vll b = in<ll>(m);
    vll c = in<ll>(m);
    
    multiset<ll> swords(all(a));
    
    vpll up;
    vpll down;
    
    f(i , 0 , m) 
    {
        if(c[i] > 0) 
        {
            up.push_back({b[i], c[i]});
        }
        else 
        {
            down.push_back({b[i], c[i]});
        }
    }
    
    sort(all(up));
    sort(all(down));
    
    ll ans = 0;
    
    for(auto& p : up) 
    {
        auto it = swords.lower_bound(p.first);
        if(it == swords.end()) 
        {
            break;
        }
        ll val = *it;
        swords.erase(it);
        swords.insert(max(val, p.second));
        ans++;
    }
    
    for(auto& p : down) 
    {
        auto it = swords.lower_bound(p.first);
        if(it != swords.end()) 
        {
            swords.erase(it);
            ans++;
        }
    }
    
    op(ans);
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}