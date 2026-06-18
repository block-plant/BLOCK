#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
int main() {
	int t ;
	cin >> t;
	while(t--) {
	    int n ;
	    cin >> n ;
	    string s ;
	    cin >> s ;
	    ll tot = (ll)n * (n + 1) / 2;
    
        ll dis = 0;
        vector<ll> cnt(3, 0);
        cnt[0] = 1; 
        int pref = 0;
        ll odd = 0;
        ll len = 1;
        for(int i = 0 ; i < n ; i++) {
            int val = (s[i] == '1') ? 1 : -1;
            pref = (pref + val) % 3;
            if(pref < 0) pref += 3; 
            dis += cnt[pref]; 
            cnt[pref]++;
            if(i > 0) {
                if(s[i] != s[i - 1]) {
                    len++;
                } 
                else {
                    len = 1;
                }
                odd += (len - 1) / 2; 
            }
        }
        
        ll ans = tot - dis - odd;
        cout << ans << endl;
	}
}
