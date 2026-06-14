/**
 * Author: KUNWAR
 * Date:   2026-06-14
 * Time:   22:53:56
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

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const ll M1 = 1e9 + 7;
const ll M2 = 1e9 + 9;
const ll MAXN = 1e6 + 5;

ll B1, B2;
ll INV_B1, INV_B2;
ll pb1[MAXN], pb2[MAXN];
bool is_initialized = false;

ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while(exp > 0) {
        if(exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n, ll M) {
    return power(n, M - 2, M);
}

void init_hashing() {
    if(is_initialized) return;
    
    B1 = uniform_int_distribution<ll>(256, M1 - 1)(rng);
    B2 = uniform_int_distribution<ll>(256, M2 - 1)(rng);
    
    INV_B1 = modInverse(B1, M1);
    INV_B2 = modInverse(B2, M2);
    
    pb1[0] = 1; pb2[0] = 1;
    f(i , 1 , MAXN) {
        pb1[i] = (1LL * pb1[i - 1] * B1) % M1;
        pb2[i] = (1LL * pb2[i - 1] * B2) % M2;
    }
    is_initialized = true;
}

void build_hash(const string& s, vector<ll>& pref1, vector<ll>& pref2) {
    int n = s.length();
    pref1.assign(n + 1, 0);
    pref2.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref1[i + 1] = (1LL * pref1[i] * B1 + s[i]) % M1;
        pref2[i + 1] = (1LL * pref2[i] * B2 + s[i]) % M2;
    }
}

pair<ll, ll> get_hash(int L, int R, const vector<ll>& pref1, const vector<ll>& pref2) {
    if (L > R) return {0, 0};
    int len = R - L + 1;
    
    ll h1 = (pref1[R + 1] - 1LL * pref1[L] * pb1[len]) % M1;
    if (h1 < 0) h1 += M1;
    
    ll h2 = (pref2[R + 1] - 1LL * pref2[L] * pb2[len]) % M2;
    if (h2 < 0) h2 += M2;
    
    return {h1, h2};
}

struct DynamicHash {
    ll h1, h2, len;

    DynamicHash() : h1(0), h2(0), len(0) {}

    bool operator==(const DynamicHash& o) const {
        return len == o.len && h1 == o.h1 && h2 == o.h2;
    }

    void push_back(char c) {
        h1 = (1LL * h1 * B1 + c) % M1;
        h2 = (1LL * h2 * B2 + c) % M2;
        len++;
    }

    void push_front(char c) {
        h1 = (h1 + 1LL * c * pb1[len]) % M1;
        h2 = (h2 + 1LL * c * pb2[len]) % M2;
        len++;
    }

    void pop_front(char c) {
        if(len == 0) return;
        len--;
        h1 = (h1 - 1LL * c * pb1[len]) % M1;
        if(h1 < 0) h1 += M1;
        
        h2 = (h2 - 1LL * c * pb2[len]) % M2;
        if(h2 < 0) h2 += M2;
    }

    void pop_back(char c) {
        if(len == 0) return;
        h1 = (h1 - c) % M1;
        if(h1 < 0) h1 += M1;
        h1 = (1LL * h1 * INV_B1) % M1; 
        
        h2 = (h2 - c) % M2;
        if(h2 < 0) h2 += M2;
        h2 = (1LL * h2 * INV_B2) % M2; 
        len--;
    }
};

void solve() {
    string s; 
    cin >> s;
    string alpha ;
    cin >> alpha ;
    l(k);
    ll n = s.length();
    
    vector<pair<ll, ll>> u;
    f(l , 0 , n) {
        ll cnt =0 ; 
        DynamicHash w ; 
        f(r , l , n) {
            if(alpha[s[r] - 'a'] == '0') cnt++ ; 
            if(cnt > k) break;
            w.push_back(s[r]);
            u.push_back({w.h1 , w.h2});
        }
    }
    sort(all(u));
    auto g = unique(all(u)) - u.begin() ;
    cout << g << endl;
}

int main() {
    fastio();
    init_hashing();
    // l(t);
    ll t = 1; 
    while(t--) {
        solve();
    }
    return 0;
}