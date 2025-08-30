#include<bits/stdc++.h>
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

        char ch =(word[idx]);

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

        char ch =(word[idx]);

        if(root->children.find(ch) == root->children.end()) {
            return false;
        }

        return searchUtil(root->children[ch], word, idx + 1);
    }

    bool search(string word) {
        return searchUtil(root, word, 0);
    }

};

void suggestions(TrieNode* root, string &str, vector<string> &sugg) {
    if (root->isTerminal) {
        sugg.push_back(str);
    }
    for (auto &child : root->children) {
        str.push_back(child.first);
        suggestions(child.second, str, sugg);
        str.pop_back();  // Backtrack
    }
}

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    vector<vector<string>> ans;
    Trie* words=new Trie();
    for(int i=0 ; i<contactList.size() ; i++){
        words->insertword(contactList[i]);
    }
    TrieNode* temp = words->root;
    string prefix = "";
    
    for (char ch : queryStr) {
        vector<string> sugg;
        prefix.push_back(ch);  // Ensure matching case

        if (temp->children.count(ch)) {
            temp = temp->children[ch];
            suggestions(temp, prefix, sugg);

            // Sort results to simulate phone directory behavior
            sort(sugg.begin(), sugg.end());
        } 
        else{
            break;
        }
        ans.push_back(sugg);
    }
    return ans;
}