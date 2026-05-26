/**
 * Author: KUNWAR
 * Date:   2026-05-26
 * Time:   16:00:31
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

const int N = 1e7+5 ;
vector<ll> spf(N);

bool isPrime(ll n) { if(n <= 1) return false; if(n <= 3) return true; if(n % 2 == 0 || n % 3 == 0) return false; for(ll i = 5; i * i <= n; i += 6) if(n % i == 0 || n % (i + 2) == 0) return false; return true; }
vb sieve(ll n) { vb isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for(ll i = 2; i * i <= n; i++) if(isPrime[i]) for(ll j = i * i; j <= n; j += i) isPrime[j] = false; return isPrime; }
vll getPrimeFact(ll n) { vll factors; for(ll i = 2; i * i <= n; i++) { if(n % i == 0) { while(n % i == 0) { factors.push_back(i); n /= i; } } } if(n > 1) factors.push_back(n); return factors; }
vll getFact(ll n) { vll factors; for(ll i = 1; i * i <= n; i++) { if(n % i == 0) { factors.push_back(i); if(i * i != n) factors.push_back(n/i); } } sort(all(factors)); return factors; }
void sieve() {
    for(ll i=1; i<N; i++) spf[i] = i;
    for(ll i=2; i*i<N; i++) if(spf[i]==i) for(ll j=i*i; j<N; j+=i) if(spf[j]==j) spf[j]=i;
}


map<ll , ll> mp ; 
void getFact(ll x, ll flag) {
    if(flag == 1) {
        while(x > 1) { 
            mp[spf[x]]++; 
            x /= spf[x]; 
        }
    }
    else {
        while(x > 1) {
            mp[spf[x]]--;
            x /= spf[x];
        }
    }
}

void func(int n , vll a , vll&c , int flag) {
    f(i , 0 , n) {
        ll s = 1;
        while(a[i] > 1) {
            ll p = spf[a[i]];
            if(flag == 1) { 
                if(mp[p] > 0) {
                    s *= p; 
                    mp[p]--; 
                }
            } 
            else {         
                if(mp[p] < 0) {
                    s *= p;
                    mp[p]++; 
                }
            }
            a[i] /= p;
        }
        if(s > 1) c.push_back(s);
    }
}

void solve() {
    l(n);
    l(m);
    auto a = in<ll>(n);
    auto b = in<ll>(m);

    ll resa = 1 ; 

    vll c ; 
    vll d ; 

    ll limit = 1e7 ; 
    f(i , 0 , n) {
        getFact(a[i] , 1);
    }
    f(i , 0 , m) {
        getFact(b[i] , 0);
    }

    func(n , a , c , 1);
    func(m , b , d , 0);

    if(c.empty()) c.push_back(1);
    if(d.empty()) d.push_back(1);

    cout << c.size() << ' ' << d.size() << endl;
    out(c);
    out(d);
}

int main() {
    fastio();
    sieve();
    // l(t);
    ll t = 1 ;
    while(t--) {
        solve();
    }
    return 0;
}