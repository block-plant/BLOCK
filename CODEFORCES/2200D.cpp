/**
 * Author: KUNWAR
 * Date:   2026-04-17
 * Time:   22:59:19
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
    var(ll , n , x , y);

    auto p = in<ll>(n);

    vll b;
    f(i , x , y) b.push_back(p[i]);

    vll s;
    f(i , 0 , x) s.push_back(p[i]);
    f(i , y , n) s.push_back(p[i]);

    ll o = 0;
    ll mn = b[0];
    f(i , 1 , (ll)b.size())
    {
        if(b[i] < mn)
        {
            mn = b[i];
            o = i ;
        }
    }

    vll a;
    f(i , o , (ll)b.size()) a.push_back(b[i]);
    f(i , 0 , o) a.push_back(b[i]);

    ll pos = s.size();
    f(i , 0 , (ll)s.size())
    {
        if(a[0] < s[i]) 
        {
            pos = i ;
            break ;
        }
    }

    f(i , 0 , pos) cout << s[i] << " ";
    
    f(i , 0 , (ll)a.size()) cout << a[i] << ( (i == (ll)a.size() - 1 && pos == (ll)s.size()) ? "" : " ");
    
    f(i , pos , (ll)s.size()) cout << s[i] << (i == (ll)s.size() - 1 ? "" : " ");
    cout << endl;
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}