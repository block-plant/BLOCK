/**
 * Author: KUNWAR
 * Date:   2026-06-02
 * Time:   22:52:06
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

const ll N = 2e6 + 7; 
vll spf(N);
bool isPrime(ll n) { if(n <= 1) return false; if(n <= 3) return true; if(n % 2 == 0 || n % 3 == 0) return false; for(ll i = 5; i * i <= n; i += 6) if(n % i == 0 || n % (i + 2) == 0) return false; return true; }
vb sieve(ll n) { vb isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for(ll i = 2; i * i <= n; i++) if(isPrime[i]) for(ll j = i * i; j <= n; j += i) isPrime[j] = false; return isPrime; }
vll getPrimeFact(ll n) { vll factors; for(ll i = 2; i * i <= n; i++) { if(n % i == 0) { while(n % i == 0) { factors.push_back(i); n /= i; } } } if(n > 1) factors.push_back(n); return factors; }
vll getFact(ll n) { vll factors; for(ll i = 1; i * i <= n; i++) { if(n % i == 0) { factors.push_back(i); if(i * i != n) factors.push_back(n/i); } } sort(all(factors)); return factors; }
void sieve() {
    for(int i = 1; i < N; i++) spf[i] = i;
    for(int i = 2; i * i < N; i++) {
        if(spf[i] == i) {
            for(int j = i * i; j < N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

ll binpow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base);
        base = (base * base);
        exp /= 2;
    }
    return res;
}

void solve() {
    l(n);
    auto a = in<ll>(n);

    vector<vector<ll>> z(N); 

    f(i , 0 , n) {
        ll x = a[i];
        while(x > 1) {
            ll p = spf[x];
            ll count = 0;
            while(x % p == 0) {
                count++;
                x /= p;
            }
            z[p].push_back(count);
        }
    }

    ll ans = 1 ;

    f(p , 2 , N) {
        if(z[p].empty()) continue; 
        ll temp = 0;
        ll non = z[p].size();

        if(non <= n - 2) {
            temp = 0;
        } 
        else if(non == n - 1) {
            temp = *min_element(z[p].begin(), z[p].end());
        } 
        else if(non == n) {
            sort(z[p].begin(), z[p].end());
            temp = z[p][1]; 
        }

        if(temp > 0) {
            ans = (ans * binpow(p, temp));
        }
    }

    cout << ans << endl;
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