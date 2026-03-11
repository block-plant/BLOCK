/**
 * Author: KUNWAR
 * Date:   2026-03-11
 * Time:   17:48:00
**/

#include <bits/stdc++.h>
#include <iostream>  
#include <vector>   
#include <string>
#include <algorithm>
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


void solve() {
    l(n);
    vll hidden = {7,2,5,1,6,3,4} ;
    bool testing = false; 

    auto ask = [&](ll left, ll right) -> ll {
        auto interactor = [&](ll l, ll r) -> ll {
            vector<pair<ll, ll>> sub;
            f(i, l, r + 1) 
            {
                sub.push_back({hidden[i - 1], i}); 
            }

            sort(sub.rbegin(), sub.rend());
            return sub[1].second;
        };

        cout << "? " << left << ' ' << right << endl;
        
        if(testing) 
        {
            ll simulated_response = interactor(left, right);
            cout << simulated_response << endl;
            return simulated_response;
        }

        ll response;
        cin >> response;
        return response;
    };

    ll pos = ask(1, n);

    bool is_left = false;
    if(pos > 1 && ask(1, pos) == pos) 
    {
        is_left = true;
    }

    ll low, high;
    if(is_left) 
    {
        low = 1;
        high = pos - 1;
    } 
    else 
    {
        low = pos + 1;
        high = n;
    }

    ll answer = -1;
    while(low <= high)
    {
        ll mid = (low + high) / 2 ;

        if(is_left)
        {
            if(ask(mid , pos) == pos)
            {
                answer = mid ;
                low = mid + 1;
            }
            else
            {
                high = mid - 1 ;
            }
        }
        else
        {
            if(ask(pos , mid) == pos)
            {
                answer = mid ;
                high = mid - 1 ;
            }
            else
            {
                low = mid + 1;
            }
        }
    }

    cout << "! " << answer << endl;
}

int main() {
    // fastio();
    solve();
    return 0;
}