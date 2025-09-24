// Problem: Palindrome Index
// Platform: HackerRank
// Language: C++
// Approach: Two-pointer technique to find the index to remove for palindrome

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

int palindromeIndex(string s) {
    int n = s.size();
    int left = 0, right = n - 1;

    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            int l1 = left + 1, r1 = right;
            bool palindromeLeft = true;
            while (l1 < r1) {
                if (s[l1] != s[r1]) {
                    palindromeLeft = false;
                    break;
                }
                l1++;
                r1--;
            }

            int l2 = left, r2 = right - 1;
            bool palindromeRight = true;
            while (l2 < r2) {
                if (s[l2] != s[r2]) {
                    palindromeRight = false;
                    break;
                }
                l2++;
                r2--;
            }

            if (palindromeLeft) return left;
            if (palindromeRight) return right;
            return -1;
        }
    }
    return -1;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);
    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);
        int result = palindromeIndex(s);
        fout << result << "\n";
    }

    fout.close();
    return 0;
}
