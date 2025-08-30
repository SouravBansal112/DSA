#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    char data;
    int childcount;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        isTerminal = false;
        childcount=0;
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

        char ch = word[idx];

        TrieNode* child;
        if(root->children.find(ch) != root->children.end()) {
            child = root->children[ch];
        } else {
            child = new TrieNode(ch);
            root->children[ch] = child;
            root->childcount++;
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

        char ch = word[idx];

        if(root->children.find(ch) == root->children.end()) {
            return false;
        }

        return searchUtil(root->children[ch], word, idx + 1);
    }

    bool search(string word) {
        return searchUtil(root, word, 0);
    }
};

/*You are given an array ‘ARR’ consisting of ‘N’ strings. Your task is to find the longest common prefix among all these strings. If there is no common prefix, you have to return an empty string.

A prefix of a string can be defined as a substring obtained after removing some or all characters from the end of the string.*/

//brute force nm^2
string longestCommonPrefi(vector<string>& arr) {
    if (arr.empty()) return "";

    string prefix = arr[0];  // Take the first string as initial prefix

    for (int i = 1; i < arr.size(); i++) {
        // Reduce prefix until the current string starts with it
        while (arr[i].find(prefix) != 0) {  // prefix not found at the start
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty()) return "";  // no common prefix
        }
    }

    return prefix;
}
//sorting approach n*mlog(n*m)
string LongestCommonPrefix(vector<string>& arr) {
    if(arr.empty()) return "";

    sort(arr.begin(), arr.end()); // Step 1: Sort strings
    string first = arr[0], last = arr[arr.size() - 1];
    
    int i = 0;
    while(i < first.size() && i < last.size() && first[i] == last[i]) {
        i++;
    }
    
    return first.substr(0, i);
}
//trie approach
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans="";
    string str=arr[0];
    Trie* words=new Trie();
    for(int i=0 ; i<arr.size() ; i++){
        words->insertword(arr[i]);
    }
    TrieNode* temp= words->root;
    int i=0;
    while(temp->childcount==1 && !temp->isTerminal){
        ans.push_back(str[i]);
        temp=temp->children[str[i]];
        i++;
    }
    return ans;
}
