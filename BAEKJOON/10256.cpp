#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int CHAR_CNT = 4;

int toNumber(char c){
	switch(c){
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
	}

	return -1;
}

struct TrieNode {
	bool isTerminal;
	TrieNode* children[CHAR_CNT];
	TrieNode* failLink;
	int output;

	TrieNode()
	: isTerminal(false), failLink(nullptr), output(0)
	{
		for(int i = 0 ; i < CHAR_CNT ; i++){
			children[i] = nullptr;
		}
	}

	~TrieNode(){
		for(int i = 0 ; i < CHAR_CNT ; i++){
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
		}
		children[next]->insert(key+1);
	}

	TrieNode* find(const char* key){
		if(*key == 0){
			return this;
		}

		int next = toNumber(*key);
		if(children[next] == nullptr){
			return nullptr;
		}
		else children[next]->find(key+1);
	}
};

class AhoCorasick{

private:
	TrieNode* root;

	void computeFailureFunc(TrieNode* root){
		queue<TrieNode*> q;

		root->failLink = root;
		q.push(root);

		while(!q.empty()){
			TrieNode* here = q.front();
			q.pop();

			for(int edge = 0 ; edge < CHAR_CNT ; ++edge) {
				TrieNode* child = here->children[edge];
				if(!child) continue;
				
				// 1레벨 노드들은 모두 루트로 연결
				if(here == root) child->failLink = root;
				else{
					TrieNode* t = here->failLink;
					while(t != root && t->children[edge] == nullptr){
						t = t->failLink;
					}

					if(t->children[edge]){
						t = t->children[edge];
					}

					child->failLink = t;
				}		

				child->output = child->failLink->output;
				if(child->isTerminal){
					child->output += 1;
				}
				q.push(child);
			}
		}
	}

public:
	AhoCorasick(TrieNode* root)
	: root(root)
	{
		computeFailureFunc(root);
	}

	int getResult(const string& s){
		int ret = 0;
		TrieNode* state = root;

		for(int i = 0 ; i < s.size() ; i++){
			int chr = toNumber(s[i]);

			while(state != root && state->children[chr] == nullptr){
				state = state->failLink;
			}

			if(state->children[chr]){
				state = state->children[chr];
			}

			ret += state->output;
		}

		return ret;
	}
};

char s[1000001];
char marker[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int test_case;
	cin >> test_case;
	while(test_case--){
		int n, m;
		cin >> n >> m;
		cin >> s >> marker;

		TrieNode* root = new TrieNode();
		for(int i = 0 ; i < m ; i++){
			for(int j = i+1 ; j <= m ; j++){
				reverse(marker + i, marker + j);
				root->insert(marker);
				reverse(marker + i, marker + j);
			}
		}

		AhoCorasick ahoCorasick(root);
		cout << ahoCorasick.getResult(s) << "\n";

		delete root;
	}

    return 0;
}