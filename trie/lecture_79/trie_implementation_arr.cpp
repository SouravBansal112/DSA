#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isTerminal;

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    inline int charToIndex(char c) {
        return c - 'a';
    }

    void insertWord(const string &word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = charToIndex(c);
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isTerminal = true;
    }

    bool searchWord(const string &word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = charToIndex(c);
            if (!curr->children[idx]) return false;
            curr = curr->children[idx];
        }
        return curr->isTerminal;
    }

    bool startsWith(const string &prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int idx = charToIndex(c);
            if (!curr->children[idx]) return false;
            curr = curr->children[idx];
        }
        return true;
    }
};