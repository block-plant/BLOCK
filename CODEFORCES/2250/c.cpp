/**
 * Author: KUNWAR
 * Date:   2026-07-26
 * Time:   20:35:50
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
    ll n ;
    cin >> n;
    vll l(n);
    vll r(n);
    vll u(n);
    vll ve(n);
    f(i , 0 , n) {
        cin >> l[i] >> r[i] >> u[i] >> ve[i]; 
    }
    fr(i , n , 1) {
        ll cur = 0 ; 
        ll v = 1 ; 
        f(j , 1 , i + 1) {
            ll rit = i - j + 1 ;
            ll f = 0 ; 
            while(cur < n) {
                if((j < l[cur] || j > r[cur]) && (rit < u[cur] || rit > ve[cur])) {
                    f = 1; 
                    cur++ ;
                    break;
                }
                cur++ ;
            }
            if(!f) {
                v = 0 ;
                break;
            }
        }
        if(v) {
            cout << i << endl;
            return;
        }
    }
    cout << 0 << endl;
}

int main() {
    fastio();
    // l(t);
    ll t = 1; 
    cin >> t; 
    while(t--) {
        solve();
    }
    return 0;
}