#include <bits/stdc++.h>
using namespace std;

long long solve(int n, vector<long long>& a) {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve(n, a) << '\n';
    }
    return 0;
}