#include<iostream>
using namespace std;

class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
    TrieNode *root;
    
    public :
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
        }
        
        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        
        // Recursive call
        insertWord(child, word.substr(1));
    }
    
    // For user
    void insertWord(string word) {	//it is basically overloading
        insertWord(root, word);
    }
    
  	bool search(TrieNode* root,string word) {
    
      if(word.size()==0)
      {
       	return root->isTerminal;
      }
  
      int i= word[0]-'a';
      if(root->children[i]!=NULL)
        return search(root->children[i],word.substr(1));
      else
        return false;
    }
    
    bool search(string word) {
        
      return search(root,word);
        
    }
};

int main() {
    int choice;
    cin >> choice;
    Trie t;
    
    //cout << "asasas";
    while(choice != -1){
        string word;
        bool ans;
        switch(choice) {
            case 1 : // insert
                // getline(cin, word);
                cin >> word;
                t.insertWord(word);
                break;
            case 2 : // search
                // getline(cin, word);
                cin >> word;
                ans = t.search(word);
                if (ans) {
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
                break;
            default :
                return 0;
        }
        cin >> choice;
    }
    return 0;
}