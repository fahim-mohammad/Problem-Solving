// Problem: String Similarity
// Platform: HackerRank
// Language: C++
// Approach: Z-algorithm to compute total similarity of string prefixes

#include <bits/stdc++.h>
using namespace std;

long stringSimilarity(const string &s) {
    int n = s.size();
    vector<int> z(n, 0);
    z[0] = n;
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    long total = 0;
    for (int val : z) total += val;
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (t--) {
        string s;
        getline(cin, s);
        cout << stringSimilarity(s) << "\n";
    }

    return 0;
}
