#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <list>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
	cin >> n >> k;
	list<int> linkedList;
	for(int i = 1 ; i <= n ; i++) linkedList.push_back(i);

	list<int> yosef;
	int preIdx = 0;
	int curIdx = 0;
	for(int i = 0 ; i < n ; i++){
		curIdx = (preIdx + k - 1) % linkedList.size();
		auto delTarget = next(linkedList.begin(), curIdx);
		yosef.push_back(*delTarget);
		linkedList.erase(delTarget);
		preIdx = curIdx;
	}

	cout << "<";
	int cnt = 0;
	for(auto iter = yosef.begin() ; iter != yosef.end() ; iter++){
		cout << *iter;
		if(yosef.size() > cnt++ + 1) cout << ", ";
	}
	cout << ">";
    
    return 0;
}