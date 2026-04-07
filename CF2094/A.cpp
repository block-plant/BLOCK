#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ; 
    cin >> t ;
    while(t--)
    {
        string s ;
        cin >> s ; 

        char one = s[0] ; 

        string p ; 
        cin >> p ; 

        char two = p[0] ; 

        string q ; 
        cin >> q ; 

        char three = q[0];
        
        string ans = "" ;
        ans += one;
        ans += two;
        ans += three;
        cout << ans << endl;
    }

    return 0;
}
