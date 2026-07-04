#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const int mxb = 1000;
vector<int> min_ops(mxb + 1, 1e9);

void build_engine() {
    min_ops[1] = 0;
    for(int i = 1 ; i <= mxb ; i++) {
        for(int x = 1 ; x <= i ; x++) {
            int nxt = i + (i / x);
            if(nxt <= mxb) {
                min_ops[nxt] = min(min_ops[nxt], min_ops[i] + 1);
            }
        }
    }
}

int main() {
    build_engine();
	int t;
	cin >> t; 
	auto solve = [&]() {
	    int n, k ;
	    cin >> n >> k ;
	    vector<ll> b(n) , c(n);
	    for(auto&x : b) cin >> x;
	    for(auto&x : c) cin >> x;
	    k = min((ll)k, 15LL * n);
	    vector<ll> dp(k + 1 , 0);
	    for(int i = 0 ; i < n ; i++) {
	        ll cost = min_ops[b[i]];
	        ll r = c[i];
	        for(int j = k ; j >= cost ; j--) {
	            dp[j] = max(dp[j] , dp[j - cost] + r);
	        }
	    }
	    cout << dp[k] << endl;
	};
	while(t--) {
	    solve();
	}
}
