#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    vector<Node*> links;
    Node() {
        this->links.assign(2, nullptr);
    }
    bool has(int bit) {
        return links[bit] != nullptr;
    }
    void put(int bit) {
        links[bit] = new Node();
    }
    Node* move(int bit) {
        return links[bit];
    }
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        this->root = new Node();
    }
    void insert(int num) {
        Node *curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = ((num >> i)&1) != 0;
            if (!curr->has(bit)) {
                curr->put(bit);
            }
            curr = curr->move(bit);
        }
    }
    int findMax(int num) {
        Node *curr = root;
        int mx = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = ((num >> i)&1) != 0;
            if (curr->has(1 - bit)) {
                mx |= (1 << i);
                curr = curr->move(1 - bit);
            } else {
                curr = curr->move(bit);
            }
        }
        return mx;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    Trie trie;
    for (int i = 0; i < n; i++) {
        trie.insert(arr1[i]);
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans = max(ans, trie.findMax(arr2[i]));
    }
    return ans;
}