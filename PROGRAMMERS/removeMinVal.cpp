#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int minVal = 987654321;
    vector<int>::iterator minIter;
    
    for(auto iter = arr.begin() ; iter != arr.end() ; iter++){
		if(*iter < minVal){
            minVal = *iter;
            minIter = iter;
        }
    }
    arr.erase(minIter);
    answer.assign(arr.begin(), arr.end());

	if(answer.size() == 0) answer.push_back(-1);

    return answer;
}

int main(){
	vector<int> arr = {4,3,2,1};
	vector<int> ans = solution(arr);

	for(int i = 0 ; i < ans.size() ; i++){
		cout << ans[i] << " ";
	}
}