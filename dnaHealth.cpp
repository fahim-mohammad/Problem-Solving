// Problem: Determining DNA Health
// Platform: HackerRank
// Language: C++
// Approach: Use Trie + Aho-Corasick algorithm to compute gene health

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    vector<pair<int,long long>> leaf;
    TrieNode* fail = nullptr;
};

void insert(TrieNode* root, const string& gene, int index, long long health) {
    TrieNode* node = root;
    for (char c : gene) {
        if (!node->children.count(c))
            node->children[c] = new TrieNode();
        node = node->children[c];
    }
    node->leaf.push_back({index, health});
}

void buildFailLinks(TrieNode* root) {
    queue<TrieNode*> q;
    root->fail = root;
    for (auto& p : root->children) {
        p.second->fail = root;
        q.push(p.second);
    }

    while (!q.empty()) {
        TrieNode* curr = q.front(); q.pop();
        for (auto& p : curr->children) {
            char c = p.first;
            TrieNode* child = p.second;
            TrieNode* f = curr->fail;
            while (f != root && !f->children.count(c)) f = f->fail;
            if (f->children.count(c)) child->fail = f->children[c];
            else child->fail = root;
            q.push(child);
        }
    }
}

long long query(TrieNode* root, const string& dna, int first, int last) {
    TrieNode* node = root;
    long long total = 0;
    for (char c : dna) {
        while (node != root && !node->children.count(c)) node = node->fail;
        if (node->children.count(c)) node = node->children[c];

        TrieNode* temp = node;
        while (temp != root) {
            for (auto& p : temp->leaf)
                if (p.first >= first && p.first <= last)
                    total += p.second;
            temp = temp->fail;
        }
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> genes(n);
    vector<long long> health(n);
    for (int i = 0; i < n; i++) cin >> genes[i];
    for (int i = 0; i < n; i++) cin >> health[i];

    TrieNode* root = new TrieNode();
    for (int i = 0; i < n; i++) insert(root, genes[i], i, health[i]);
    buildFailLinks(root);

    int s;
    cin >> s;
    long long minH = LLONG_MAX, maxH = LLONG_MIN;
    for (int i = 0; i < s; i++) {
        int first, last;
        string dna;
        cin >> first >> last >> dna;
        long long total = query(root, dna, first, last);
        minH = min(minH, total);
        maxH = max(maxH, total);
    }

    cout << minH << " " << maxH << "\n";
    return 0;
}
