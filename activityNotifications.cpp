// Problem: Fraudulent Activity Notifications
// Platform: HackerRank
// Language: C++
// Approach: Use counting sort to track last 'd' expenditures and compute median

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int activityNotifications(vector<int> expenditure, int d) {
    vector<int> count(201, 0);
    int notifications = 0;

    for (int i = 0; i < d; i++)
        count[expenditure[i]]++;

    auto getMedian = [&](int d) -> double {
        int sum = 0;
        if (d % 2 == 1) {
            int mid = d / 2 + 1;
            for (int i = 0; i <= 200; i++) {
                sum += count[i];
                if (sum >= mid)
                    return i;
            }
        } else {
            int mid1 = d / 2;
            int mid2 = mid1 + 1;
            int m1 = -1, m2 = -1;
            for (int i = 0; i <= 200; i++) {
                sum += count[i];
                if (sum >= mid1 && m1 == -1) m1 = i;
                if (sum >= mid2) { m2 = i; break; }
            }
            return (m1 + m2) / 2.0;
        }
        return 0;
    };

    for (int i = d; i < expenditure.size(); i++) {
        double median = getMedian(d);
        if (expenditure[i] >= 2 * median)
            notifications++;
        count[expenditure[i - d]]--;
        count[expenditure[i]]++;
    }

    return notifications;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);
    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));
    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        expenditure[i] = stoi(expenditure_temp[i]);
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";
    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
