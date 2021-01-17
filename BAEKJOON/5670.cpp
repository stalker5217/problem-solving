#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

const int ALPHABET = 26;

const int MAXCNT = 100000;
const int MAXLEN = 81;
char inputStr[MAXCNT][MAXLEN];

int toNumber(char c){
	return c - 'a';
}

struct TrieNode{
	bool isRoot;
	bool isTerminal;
	int childCnt;
	TrieNode* children[ALPHABET];
	
	TrieNode()
	: isTerminal(false), isRoot(false), childCnt(0)
	{
		for(int i = 0 ; i < ALPHABET ; i++){
			children[i] = nullptr;
		}
	}

	~TrieNode(){
		for(int i = 0 ; i < ALPHABET ; i++){
			if(children[i]) delete children[i];
		}
	}

	void insert(const char* key){
		if(*key == 0){
			isTerminal = true;
			return;
		}

		int next = toNumber(*key);
		if(children[next] == nullptr){
			children[next] = new TrieNode();
			childCnt++;
		}
		children[next]->insert(key + 1);
	}

	int find(const char* key, int inputCnt){
		if(*key == 0) return inputCnt;

		if(isRoot) inputCnt++;
		else if(isTerminal) inputCnt++;
		else if(childCnt >= 2) inputCnt++;

		int next = toNumber(*key);
		if(children[next] == nullptr){
			 return -999;
		}
		return children[next]->find(key + 1, inputCnt);
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
	while(cin >> n){
		TrieNode* root = new TrieNode();
		root->isRoot = true;	
		for(int i = 0 ; i < n ; i++){
			cin >> inputStr[i];
			root->insert(inputStr[i]);
		}

		int sum = 0;
		for(int i = 0 ; i < n ; i++){
			sum += root->find(inputStr[i], 0);
		}
		
		cout << fixed;
    	cout.precision(2);
		cout << (double) sum / n << "\n";
	
		delete root;
	}
	
    return 0;
}