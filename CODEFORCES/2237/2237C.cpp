#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
int main() {
	int t ;
	cin >> t ;
	while(t--) {
	    int n ;
	    cin >> n ;
	    vector<ll> a(n , 0);
	    ll mx = 0 ; 
	    ll sum = 0 ;
	    for(int i = 0 ; i < n ; i++) {
	        cin >> a[i];
	        sum += a[i];
	        mx = max(mx , a[i]);
	    }
	    auto check = [&](ll mid)->bool {
            ll temp = mid;
            for(int i = n - 1; i >= 0; i--) {
                if(a[i] > temp) {
                    return false;
                }
                temp = max(min((ll)a[i], temp) , temp - (ll)a[i]);
            }
            return true;
	    };
	    ll low = mx ; 
	    ll high = sum ;
	    ll ans = sum ;
	    while(low <= high) {
	        ll mid = (low + high) / 2;
	        if(check(mid)) {
	            high = mid - 1;
	            ans = mid;
	        }
	        else {
	            low = mid +1 ;
	        }
	    }
	    cout << ans << endl;
 	}
}