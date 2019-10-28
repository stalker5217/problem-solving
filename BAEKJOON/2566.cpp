#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef struct __myValue{
	int row;
	int col;
	int val;
} myValue;

bool compare(const myValue &a, const myValue &b){
	if(a.val < b.val)
		return true;
	else
		return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<myValue> arr;
    for(int i = 1 ; i <= 9 ; i++){
		for(int j = 1 ; j <= 9 ; j++){
			int val;
			cin >> val;
			myValue temp;
			temp.row = i;
			temp.col = j;
			temp.val = val;
			arr.push_back(temp);
		}
	}

	myValue maxValue = *max_element(arr.begin(), arr.end(), compare);

	cout << maxValue.val << "\n";
	cout << maxValue.row << " " << maxValue.col;
    
    return 0;
}
