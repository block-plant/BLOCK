/**
 * Author: KUNWAR
 * Date:   2026-05-26
 * Time:   08:06:28
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

ll getPhi(ll n) {
    ll result = n;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if(n > 1) result -= result / n;
    return result;
}

ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while(exp > 0) {
        if(exp % 2 == 1) res = res * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return res;
}

void solve() {
    l(n);
    l(m);
    auto w = in<ll>(n);
    l(q);

    vll temp ; 
    ll p = m;
    while(p > 1) {
        temp.push_back(p);
        p = getPhi(p);
    }
    temp.push_back(1);

    while(q--) {
        l(l);
        l(r);
        l-- ; 
        r-- ; 
        vll phi ; 
        ll i = l ;
        ll idx = 0;
        while(i <= r && temp[idx] > 1) {
            phi.push_back(temp[idx]);
            idx++;
            i++ ;
        } 
        phi.push_back(1);

        ll exp = 1; 
        ll j = phi.size()-2 ; 

        fr(k , i-1 , l) {
            ll cur = phi[j];

            if(w[k] == 1) {
                exp = 1;
                j-- ;
                continue;
            }
            if(w[k] == 0) {
                exp = ((exp == 0) ? 1 : 0); 
                j-- ;
                continue;
            }
            
            if(exp >= cur || w[k] >= cur) {
                exp = power(w[k] , exp , cur);
                if(k > l) {
                    exp += cur ;
                }
            }
            else {
                ll ch = 1;
                for(int p = 0; p < exp && ch < cur; p++) ch *= w[k];
                
                if(ch >= cur) {
                    exp = power(w[k], exp, cur);
                    if(k > l) {
                        exp += cur ;    
                    } 
                } 
                else {
                    exp = ch;
                }
            }
            j-- ;
        }
        op(exp % m);
    }
}

int main() {
    fastio();
    // l(t);
    ll t = 1 ; 
    while(t--) {
        solve();
    }
}