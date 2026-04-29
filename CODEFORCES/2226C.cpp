#include <bits/stdc++.h>
using namespace std;

static bool canMakeMex(const vector<int>& a, int k) {
    multiset<int> pool(a.begin(), a.end());
    vector<int> cnt(k + 1, 0);
    for (int v : a) {
        if (v <= k) cnt[v]++;
    }

    for (int x = k - 1; x >= 0; --x) {
        if (cnt[x] > 0) {
            cnt[x]--;
            auto it = pool.find(x);
            if (it == pool.end()) return false;
            pool.erase(it);
        } else {
            int need = 2 * x + 1;
            auto it = pool.lower_bound(need);
            if (it == pool.end()) return false;
            pool.erase(it);
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int lo = 0, hi = n;
        int mexwf = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canMakeMex(a, mid)) {
                mexwf = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        cout << mexwf << '\n';
    }

    return 0;
}
