/**
 * Author: Krishan
 * Date:   2026-04-07
 * Time:   3:50:56
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

bool solve() {
    l(n);
    if(n == 1)
    {
        l(val);
        return false;
    }
    vvll a(n , vll(n, 0));

    f(i , 0 , n)
    {
        f(j , 0 , n)
        {
            cin >> a[i][j];
        }
    }

    vll freq(n*n+1 , 0) ;
    f(i , 0 , n)
    {
        f(j , 0 , n)
        {
            freq[a[i][j]]++ ;
            if(freq[a[i][j]] > n * (n-1)) 
            {
                return false ;
            }
        }
    } 
    return true;
}

int main() {
    fastio();
    l(t);
    while(t--) {
        if(solve()) cout << "YES" << endl;
        else cout << "NO" << endl ;
    }
    return 0;
}