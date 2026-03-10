/**
 * Author: KUNWAR
 * Date:   2026-03-10
 * Time:   15:45:51
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

vll result;

ll ask(ll left , ll right)
{
    cout << "? " << left << ' ' << right << endl ;
    ll response ;
    cin >> response ; 
    return response ;
}

void dnc(ll low , ll high , ll k)
{
    ll ans = -1 ;
    while(low <= high)
    {
        if(low == high) 
        {
            ans = low;
            break;
        }
        ll mid = low + (high - low) / 2;

        auto left = ask(low , mid);

        ll zil = (mid - low + 1) - left;

        if(k <= zil)
        {
            high = mid ;
        }
        else 
        {
            k -= zil ;
            low = mid + 1;
        }
    }

    cout << "! " << ans << endl;
}
void solve() {
    l(n);
    l(t); // it is 1
    l(k);

    ll low = 1 ; 
    ll high = n ;

    dnc(low , high , k) ; 
}

int main() {
    // fastio();
    // l(t);
    ll t = 1 ;
    while(t--) {
        solve();
    }
    return 0;
}