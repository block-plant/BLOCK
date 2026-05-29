/**
 * Author: KUNWAR
 * Date:   2026-05-29
 * Time:   20:44:23
**/

#include <bits/stdc++.h>
#include <ostream>
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

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { if (a == 0 || b == 0) return 0; return (a / gcd(a, b)) * b; }
ll binpow(ll base, ll exp, ll mod) { ll res = 1; base %= mod; while(exp > 0) { if(exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

const ll N = 1e5 + 7;
vll spf(N,0);
bool isPrime(ll n) { if(n <= 1) return false; if(n <= 3) return true; if(n % 2 == 0 || n % 3 == 0) return false; for(ll i = 5; i * i <= n; i += 6) if(n % i == 0 || n % (i + 2) == 0) return false; return true; }
vb sieve(ll n) { vb isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for(ll i = 2; i * i <= n; i++) if(isPrime[i]) for(ll j = i * i; j <= n; j += i) isPrime[j] = false; return isPrime; }
vll getPrimeFact(ll n) { vll factors; for(ll i = 2; i * i <= n; i++) { if(n % i == 0) { while(n % i == 0) { factors.push_back(i); n /= i; } } } if(n > 1) factors.push_back(n); return factors; }
vll getFact(ll n) { vll factors; for(ll i = 1; i * i <= n; i++) { if(n % i == 0) { factors.push_back(i); if(i * i != n) factors.push_back(n/i); } } sort(all(factors)); return factors; }


void solve() {
    l(n);
    l(m);
    vll parent(n + 1 , 0);
    multiset<ll> mp ;
    while(m--) {
        char c; 
        cin >> c;
        ll idx ; 
        cin >> idx ; 
        vll fact = getPrimeFact(idx);
        if(c == '+') {
            if(mp.empty()) {
                cout << "Success" << endl;
                mp.insert(idx);
                for(auto x : fact) {
                    parent[x] = idx ;
                }
            }
            else {
                if(mp.find(idx) != mp.end()) {
                    cout << "Already on" << endl;
                }
                else {
                    bool psbl = true ; 
                    for(auto x : fact) {
                        if(parent[x] != 0) {
                            cout << "Conflict with " << parent[x] << endl;
                            psbl = false ;
                            break;
                        }
                    }
                    if(psbl) {
                        cout << "Success" << endl;
                        for(auto x : fact) {
                            parent[x] = idx ;
                        }
                        mp.insert(idx);
                    }
                }
            }
        }
        else {
            if(mp.empty()) {
                cout << "Already off" << endl;
            }
            else {
                if(mp.find(idx) != mp.end()) {
                    cout << "Success" << endl;
                    mp.erase(idx);
                    for(auto x : fact) {
                        parent[x] = 0 ;
                    }
                }
                else {
                    cout << "Already off" << endl;
                }
            }
        }
    }
}

int main() {
    fastio();
    // l(t);
    ll t = 1;
    while(t--) {
        solve();
    }
    return 0;
}