#include <bits/stdc++.h>
using namespace std;

string solve(int n, vector<string>& names) {
    vector<string> sukkur_orig = {"Maaz", "Ahmer", "Ammar", "Affan", "Saad", "Enayat",
};  
    if(n < 3) return "NO";
    int count = 0;
    for(auto& s : names) {
        for(auto& a : sukkur_orig) {
            if(s == a) count++;
        }
    }

    if(count == 6 && n == 6) return "OG Sukkur Gang";
    else if(count >= 3) return "YES";
    else return "NO";

    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> names(n);
        for (auto& s : names) cin >> s;
        cout << solve(n, names) << '\n';
    }
    return 0;
}