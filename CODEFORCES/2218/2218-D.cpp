/**
 * Author: KUNWAR
 * Date:   2026-04-04
 * Time:   20:35:55
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

const int MAX_P = 150000; 
vector<ll> primes;
vector<bool> is_prime;

void precompute_primes(){
    is_prime.assign(MAX_P + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(ll p = 2; p * p <= MAX_P; p++){
        if(is_prime[p]){
            for(ll i = p * p; i <= MAX_P; i += p)
                is_prime[i] = false;
        }
    }
    for(ll p = 2; p <= MAX_P; p++){
        if(is_prime[p]) primes.push_back(p);
    }
}

void solve() {
    l(n);
    
    f(i , 0 , n) 
    {
        cout << primes[i] * primes[i + 1] << ' '; 
    }
    cout << endl;
}

int main() {
    fastio();
    precompute_primes();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}