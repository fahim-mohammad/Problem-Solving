// Problem: Anagram
// Platform: HackerRank
// Language: C++
// Approach: Count character frequencies and compute minimum changes for first half

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(),
        not1(ptr_fun<int,int>(isspace))));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(),
        not1(ptr_fun<int,int>(isspace))).base(), s.end());
    return s;
}

int anagram(string s) {
    int n = s.size();
    if (n % 2 != 0) return -1;

    string a = s.substr(0, n/2);
    string b = s.substr(n/2, n/2);

    vector<int> freq(26, 0);
    for (char c : a) freq[c - 'a']++;
    for (char c : b) freq[c - 'a']--;

    int changes = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] > 0) changes += freq[i];

    return changes;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);
    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();
    return 0;
}
