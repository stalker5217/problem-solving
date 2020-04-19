// 같은 숫자는 싫어

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

	int pre = -1;
    for(int i = 0 ; i < arr.size() ; i++){
		if(pre != arr[i]){
			answer.push_back(arr[i]);
		}
		pre = arr[i];
	}

    return answer;
}

int main(){
	vector<int> arr = {1,1,3,3,0,1,1};
	vector<int> ans = solution(arr);

	for(int i = 0 ; i < ans.size() ; i++){
		cout << ans[i] << " ";
	}
}