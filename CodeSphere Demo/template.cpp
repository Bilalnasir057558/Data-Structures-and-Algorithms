#include <bits/stdc++.h>
using namespace std;

int solve(int n, long long c, vector<long long>& a) {
    long long count = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > c) count++;
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long c;
        cin >> n >> c;
        vector<long long> a(n);
        for (auto& x : a) cin >> x;
        cout << solve(n, c, a) << '\n';
    }
    return 0;
}