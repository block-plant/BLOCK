/**
 * Author: KUNWAR
 * Date:   2026-03-25
 * Time:   23:34:33
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

void solve() 
{
    l(k); 
    l(a1); l(b1); 
    l(a2); l(b2);

    ll a = a1 + a2;
    ll b = b1 + b2;

    ll wa = (a1 > b1) + (a2 > b2);
    ll wb = (b1 > a1) + (b2 > a2);

    ll fb = b + k; 
    ll fa = a + 0; 
    ll fwb = wb + 1; 

    if(fb > fa || (fb == fa && fwb > wa)) 
    {
        op("YES");
    } 
    else 
    {
        op("NO");
    }
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}


import java.util.Scanner

/**
 * Author: KUNWAR
 * Date:   2026-03-25
 * Time:   23:34:33
**/

fun solve(sc: Scanner) 
{
    val k = sc.nextLong()
    val a1 = sc.nextLong()
    val b1 = sc.nextLong()
    val a2 = sc.nextLong()
    val b2 = sc.nextLong()

    val a = a1 + a2
    val wa = (if (a1 > b1) 1 else 0) + (if (a2 > b2) 1 else 0)

    val b = b1 + b2
    val wb = (if (b1 > a1) 1 else 0) + (if (b2 > a2) 1 else 0)

    val fa = a 
    val fb = b + k
    val fwb = wb + 1 

    if (fb > fa || (fb == fa && fwb > wa)) {
        println("YES")
    } else {
        println("NO")
    }
}

fun main() {
    val sc = Scanner(System.`in`)
    if (sc.hasNextLong()) {
        val t = sc.nextLong()
        repeat(t.toInt()) {
            solve(sc)
        }
    }
}