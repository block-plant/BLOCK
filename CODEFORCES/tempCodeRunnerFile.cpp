/**
 * Author: KUNWAR
 * Date:   2026-03-17
 * Time:   22:33:24
**/

#include <bits/stdc++.h>
#include <iostream>  
#include <vector>   
#include <string>
#include <algorithm>
#include <map>
#include <set>
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

ll a = 4 ;
ll b = 6 ; 
ll c = 6 ; 
ll d = 2 ; 
bool testing = false;

void solve() {
    l(n);
    l(m);

    auto ask = [&](ll x , ll y)->ll {
        auto interactor = [&](ll x , ll y)->ll {
            return min(abs(x-a) + abs(y-b) , abs(x-c) + abs(y-d));
        };

        cout << "? " << x << ' ' << y << endl;
        if(testing) {
            ll simulated_response = interactor(x , y);
            cout << simulated_response << endl;
            return simulated_response;
        }

        ll response;
        cin >> response;
        return response;
    };

    ll d1 = ask(1, 1);
    ll d2 = ask(n, 1);
    ll d3 = ask(1, m);

    bool found_A = false;
    if((d1 + d2 - n + 3) % 2 == 0) 
    { 
        ll y_f = (d1 + d2 - n + 3) / 2;
        ll x_f = d1 + 2 - y_f;

        if(x_f >= 1 && x_f <= n && y_f >= 1 && y_f <= m) 
        {
            ll verify = ask(x_f, y_f);
            if(verify == 0) 
            {
                cout << "! " << x_f << " " << y_f << endl;
                return; 
            }
        }
    }

    ll x_s = (d1 + d3 - m + 3) / 2;
    ll y_s = d1 + 2 - x_s;
    
    cout << "! " << x_s << " " << y_s << endl;
}

int main() {
    fastio();
    l(t);
    // ll t = 1 ;
    while(t--) {
        solve();
    }
    return 0;
}