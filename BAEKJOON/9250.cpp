#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int ALPHABETS = 26;

// 알파벳을 인덱스로 대응
int toNumber(char ch){
	return ch - 'a';
}

struct TrieNode {
	TrieNode* children[ALPHABETS];
	TrieNode* fail;
	int terminal;
	vector<int> output;

	TrieNode()
	: terminal(-1)
	{
		memset(children, 0, sizeof(children));
	}

	~TrieNode() {
		for(int i = 0 ; i < ALPHABETS ; i++){
			if(children[i]) delete children[i];
		}
	}

	void insert(const char * key, const int& num){
		// 문자열의 끝인 경우 terminal check 후 종료
		if(*key == 0){
			terminal = num;
			return;
		}

		int next = toNumber(*key);
		if(children[next] == NULL){
			children[next] = new TrieNode();
		}
		children[next]->insert(key + 1, num);
	}

	TrieNode* find(const char * key){
		if(*key == 0) return this;

		int next = toNumber(*key);
		if(children[next] == nullptr) return nullptr;
		return children[next]->find(key+1);
	}
};


class AhoCorasick{
private:
	TrieNode* root;

	void computeFailureFunc(TrieNode* root){
		queue<TrieNode*> q;

		root->fail = root;
		q.push(root);

		while(!q.empty()){
			TrieNode* here = q.front();
			q.pop();

			for(int edge = 0 ; edge < ALPHABETS ; ++edge) {
				TrieNode* child = here->children[edge];
				if(!child) continue;
				
				// 1레벨 노드들은 모두 루트로 연결
				if(here == root) child->fail = root;
				else{
					TrieNode* t = here->fail;
					while(t != root && t->children[edge] == nullptr){
						t = t->fail;
					}

					if(t->children[edge]){
						t = t->children[edge];
					}

					child->fail = t;
				}		

				child->output = child->fail->output;
				if(child->terminal != -1){
					child->output.push_back(child->terminal);
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

	/**
	 *  Trie에 포함된 패턴을 s에서 찾는다.
	 *  s 내에서 패턴이 출현할 때마다 (마지막 글자, 패턴 번호)의 쌍을 저장한다.
	 */
	vector<pair<int, int> > getResult(const string& s){
		vector<pair<int, int> > ret;
		TrieNode* state = root;

		for(int i = 0 ; i < s.size() ; i++){
			int chr = toNumber(s[i]);

			while(state != root && state->children[chr] == nullptr){
				state = state->fail;
			}

			if(state->children[chr]){
				state = state->children[chr];
			}

			for(int j = 0 ; j < state->output.size() ; j++){
				ret.push_back({i, state->output[j]});
			}
		}

		return ret;
	}
};


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int needleCnt;
	cin >> needleCnt;
	TrieNode root;
	for(int i = 0 ; i < needleCnt ; i++){
		char s[101];
		cin >> s;
		root.insert(s, i);
	}
	
	AhoCorasick ahoCorasick(&root);
	int stringCnt;
	cin >> stringCnt;
	for(int i = 0 ; i < stringCnt ; i++){
		char s[10001];
		cin >> s;
		
		if(ahoCorasick.getResult(s).size() > 0) cout << "YES\n";
		else cout << "NO\n";
	}
}