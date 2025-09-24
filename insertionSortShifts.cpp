// Problem: Insertion Sort - Counting Shifts
// Platform: HackerRank
// Language: C++
// Approach: Use merge sort to count inversions instead of simulating insertion sort

#include <bits/stdc++.h>
using namespace std;

long long mergeCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    if (left >= right) return 0;
    int mid = (left + right) / 2;
    long long inv = mergeCount(arr, temp, left, mid);
    inv += mergeCount(arr, temp, mid + 1, right);

    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv += (mid - i + 1);
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (i = left; i <= right; i++) arr[i] = temp[i];
    return inv;
}

long long insertionSortShifts(vector<int>& arr) {
    vector<int> temp(arr.size());
    return mergeCount(arr, temp, 0, arr.size() - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        long long result = insertionSortShifts(arr);
        cout << result << "\n";
    }
    return 0;
}
