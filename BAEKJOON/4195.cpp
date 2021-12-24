#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <functional>

using namespace std;

int main() {
	int testCase; cin >> testCase;
	while(testCase--) {
		unordered_map<string, int> pMap;
		int pNum = 0;

		vector<pair<int, int> > relations;
		int f; cin >> f;
		while(f--) {
			string a, b;
			cin >> a >> b;

			int aNum;
			if(pMap.find(a) == pMap.end()) {
				aNum = pNum;
				pMap[a] = pNum++;
			}
			else aNum = pMap[a];

			int bNum;
			if(pMap.find(b) == pMap.end()) {
				bNum = pNum;
				pMap[b] = pNum++;
			}
			else bNum = pMap[b];

			relations.push_back({aNum, bNum});
		}

		vector<int> parent(pNum);
		vector<int> networkCnt(pNum);
		for(int i = 0 ; i < pNum ; i++) {
			parent[i] = i;
			networkCnt[i] = 1;
		}

		function<int (int)> find = [&](int num) {
			if(parent[num] == num) return num;
			else return parent[num] = find(parent[num]); 		
		};

		auto merge = [&](int a, int b) {
			a = find(a);
			b = find(b);

			if(a == b) return;
			
			parent[b] = a;
			networkCnt[a] += networkCnt[b];
			networkCnt[b] = networkCnt[a];
		};

		for(auto relation : relations) {
			merge(relation.first, relation.second);
			cout << networkCnt[parent[relation.first]] << "\n";
		}
	}

	return 0;
}