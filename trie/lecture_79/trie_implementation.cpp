#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    char data;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        isTerminal = false;
    }
};

class Trie {
    public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertutil(TrieNode* root, string &word, int idx) {
        // Base case
        if(idx == word.length()) {
            root->isTerminal = true;
            return;
        }

        char ch = toupper(word[idx]);

        TrieNode* child;
        if(root->children.find(ch) != root->children.end()) {
            child = root->children[ch];
        } else {
            child = new TrieNode(ch);
            root->children[ch] = child;
        }

        insertutil(child, word, idx + 1);
    }

    void insertword(string word) {
        insertutil(root, word, 0);
    }

    bool searchUtil(TrieNode* root, string &word, int idx) {
        // Base case
        if(idx == word.length()) {
            return root->isTerminal;
        }

        char ch = toupper(word[idx]);

        if(root->children.find(ch) == root->children.end()) {
            return false;
        }

        return searchUtil(root->children[ch], word, idx + 1);
    }

    bool search(string word) {
        return searchUtil(root, word, 0);
    }
};

int main() {
    Trie t;
    t.insertword("Apple");
    t.insertword("App");

    cout << t.search("App") << endl;    // 1
    cout << t.search("Apple") << endl;  // 1
    cout << t.search("Appl") << endl;   // 0

    return 0;
}












