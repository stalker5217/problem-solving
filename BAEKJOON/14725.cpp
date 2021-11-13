#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class TrieNode {
private:
	map<string, TrieNode*> children;

public:
	void insert(vector<string> & v, const int idx) {
		if(v.size() == idx) return;
		
		auto result = children.find(v[idx]);
		if(result == children.end()) {
			TrieNode* next = new TrieNode();
			children.insert({v[idx], next});
			next->insert(v, idx+1);
		}
		else {
			result->second->insert(v, idx+1);
		}
	}

	void print(int depth) {
		if(children.empty()) return;

		for(auto iter = children.begin() ; iter != children.end() ; iter++) {
			for(int i = 0 ; i < depth ; i++) cout << "--";
			cout << iter->first << "\n";

			iter->second->print(depth+1);
		}
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
	cin >> n;

	TrieNode* root = new TrieNode();
	while(n--) {
		int k;
		cin >> k;

		vector<string> v(k);
		for(int i = 0 ; i < k ; i++) cin >> v[i];

		root->insert(v, 0);
	}

	root->print(0);
    
    return 0;
}