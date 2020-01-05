#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

struct Node {
    char value;
    map<char, Node*> children;
    bool isEnd;
    Node(char v): value(v) {
        isEnd = false;
    }
};

class Trie {
    Node *root;

    void print(Node *run) {
        map<char, Node*>::iterator it;
        for(it = run->children.begin(); it!=run->children.end(); it++) {
            char val = it->first;
            cout<<val<<endl;
            if(run->children[val]->isEnd) cout<<"$"<<endl;
            Node *child = it->second;
            print(child);
        }
    }
    public:
    Trie() {
        // create the root here
        root = new Node(' ');
    }

    void insert(string word) {
        Node *run = root;
        for(int i=0; i<word.size(); i++) {
            char alpha = word[i];
            if(run->children.find(alpha) == run->children.end()) {
                run->children[alpha] = new Node(alpha);
            }
            run = run->children[alpha];
        }
        run->isEnd = true;
    }

    void print() {
        print(root);
    }

    bool search(string word) {
        Node *run = root;
        for(int i=0; i<word.size(); i++) {
            char alpha = word[i];
            if(run->children.find(alpha) == run->children.end()) {
                return false;
            }
            run = run->children[alpha];
        }
        return run->isEnd;
    }
};

int main() {
    Trie dictionary;
    dictionary.insert("cat");
    dictionary.insert("cow");
    dictionary.insert("caterpillar");
    dictionary.insert("apple");
    dictionary.insert("apply");
    // dictionary.print();
    cout<<dictionary.search("cow")<<endl;
    return 0;
}
