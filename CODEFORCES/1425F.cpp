/**
 * Author: KUNWAR
 * Date:   2026-03-09
 * Time:   20:01:08
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

ll ask(ll L , ll R) {
    cout << "? " << L << ' '  << R << endl; 
    ll response;
    cin >> response;
    return response;
}

void solve() {
    l(n);
    vll prev(n+1) ; 
    vll ans(n+1) ; 
    ll q12 = ask(1, 2); 
    ll q23 = ask(2, 3); 
    ll q13 = ask(1, 3); 
    
    ans[3] = q13 - q12;          
    ans[1] = q13 - q23;          
    ans[2] = q12 - ans[1];       
    
    prev[1] = ans[1];
    prev[2] = q12;
    prev[3] = q13;

    f(i , 4 , n+1)
    {
        ll num = ask(1 , i);
        ans[i] = num - prev[i-1];
        prev[i]= num;
    }

    cout << "! " ;
    f(i , 1 , n+1)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}