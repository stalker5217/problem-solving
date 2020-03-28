#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool compare(const string & a, const string & b);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Algorithm
    int n;
	cin >> n;

	vector<string> vec;
	for(int i = 0 ; i < n ; i++){
		string temp;
		cin >> temp;
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end(), compare);

	string preWord = "";
    for(int i = 0 ; i < n ; i++){
		if(vec[i] != preWord){
			cout << vec[i] << "\n";
			preWord = vec[i];
		}
	}

    return 0;
}

bool compare(const string & a, const string & b){
	int sizeA = a.size();
	int sizeB = b.size();

	// 길이로 1차 비교
	if(sizeA > sizeB){
		return false;
	}
	else if(sizeA < sizeB){
		return true;
	}

	// 길이가 같은 경우. 2차 비교
	for(int i = 0 ; i < sizeA ; i++){
		int ascA = a[i];
		int ascB = b[i];

		if(ascA > ascB){
			return false;
		}
		else if(ascA < ascB){
			return true;
		}
	}

	// 아예 같은 경우
	return false;
}