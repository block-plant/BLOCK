/**
 * Author: KUNWAR
 * Date:   2026-03-06
 * Time:   17:18:57
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


vll getPrimeFact(ll n) { vll factors; for(ll i = 2; i * i <= n; i++) { if(n % i == 0) { while(n % i == 0) { factors.push_back(i); n /= i; } } } if(n > 1) factors.push_back(n); return factors; }
vll getFact(ll n) { vll factors; for(ll i = 1; i * i <= n; i++) { if(n % i == 0) { factors.push_back(i); if(i * i != n) factors.push_back(n/i); } } sort(all(factors)); return factors; }



void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    long long w, h, d;
    long long n;
    
    cin >> w >> h >> d >> n ;

    vector<long long> divisors;
    for(long long i = 1; i * i <= n; ++i) 
    {
        if(n % i == 0) 
        {
            divisors.push_back(i);
            if(i * i != n) 
            {
                divisors.push_back(n / i);
            }
        }
    }

    for(long long pw : divisors) 
    {
        if(w % pw == 0) 
        {
            long long rem_n = n / pw;
            for(long long ph : divisors) 
            {
                if(rem_n % ph == 0 && h % ph == 0) 
                {
                    long long pd = rem_n / ph; 
                    
                    if(d % pd == 0) 
                    {
                        cout << (pw - 1) << " " << (ph - 1) << " " << (pd - 1) << "\n";
                        return;
                    }
                }
            }
        }
    }
    
    cout << -1 << "\n";
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