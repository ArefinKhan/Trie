#include <iostream>
#include <string>
using namespace std;

struct Node {
    char val;
    Node *children[26];
    bool isEnd;
    Node(char x): val(x) {
        isEnd = false;
        for(int i=0; i<26; i++) children[i] = NULL;
    }
};

void insert(Node *root, string str) {
    Node *node = root;
    int i;
    for(i=0; i<str.size(); i++) {
        int index = str[i] - 'a';
        if(node->children[index]) {
            node = node->children[index];
            if(i == str.size() - 1) node->isEnd = true;
        }
        else {
            Node *newNode;
            newNode = new Node(str[i]);
            if(i == str.size() - 1) newNode->isEnd = true;
            node->children[index] = newNode;
            node = node->children[index];
        }
    }
}

bool search(Node *root, string str) {
    bool res = false;
    Node *node = root;
    int N = str.size();
    for(int i=0; i<N; i++) {
        int index = str[i] - 'a';
        if(node->children[index]) {
            if(i == N-1) {
                if(node->children[index]->isEnd) res = true;
            } 
            node = node->children[index];
        }
        else break;
    }
    return res;
}

void printTrie(Node *root) {
    cout<<"Val:"<<root->val<<" isEnd:"<<root->isEnd<<endl;
    for(int i=0; i<26; i++) {
        if(root->children[i]) printTrie(root->children[i]);
    }
}

int main() {
    Node *root;
    root = new Node('$');
    insert(root, "cat");
    insert(root, "saturn");
    insert(root, "sat");
    insert(root, "book");
    insert(root, "apple");
    insert(root, "application");
    // printTrie(root);
    cout<<search(root, "book")<<endl;
    cout<<search(root, "sat")<<endl;
    cout<<search(root, "saturn")<<endl;
    cout<<search(root, "pluto")<<endl;
    return 0;
}
