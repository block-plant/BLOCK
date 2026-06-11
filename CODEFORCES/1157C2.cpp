/**
 * Author: KUNWAR
 * Date:   2026-06-11
 * Time:   22:36:13
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
    auto a = in<ll>(n);
 
    ll i = 0 ; 
    ll j = n - 1 ;
    string ans = "";
    ll last = -1 ;
    
    while(i <= j) {
        bool left = (a[i] > last) ;
        bool right = (a[j] > last) ;
        if(!left && !right) break ;
        if(left & !right) {
            ans += 'L' ;
            last = a[i];
            i++ ; 
        }
        else if(!left && right) {
            ans += 'R' ;
            last = a[j] ;
            j-- ; 
        }
        else {
            if(a[i] < a[j]) {
                ans += 'L';
                last = a[i]; 
                i++; 
            }
            else if(a[i] > a[j]) {
                ans += 'R';
                last = a[j]; 
                j--; 
            }
            else {
                ll l = i ; 
                ll r = j ;
                ll cntl = 1 ;
                ll cntr = 1 ; 
                for(ll c = l ; c < r ; c++) {
                    if(a[c] < a[c + 1]) cntl++ ; 
                    else break;
                }
                for(ll c = r ; c > l ; c--) {
                    if(a[c] < a[c - 1]) cntr++ ;
                    else break;
                }
                if(cntl > cntr) {
                    for(ll k = 0 ; k < cntl ; k++) ans += 'L';
                }
                else {
                    for(ll k = 0 ; k < cntr ; k++) ans += 'R';
                }
                break;
            }
        }
    }
    
    cout << ans.length() << endl;
    cout << ans << endl;
}
 
int main() {
    fastio();
    // l(t);
    ll t = 1 ;
    while(t--) {
        solve();
    }
    return 0;
}