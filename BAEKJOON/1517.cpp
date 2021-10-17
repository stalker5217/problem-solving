#include <iostream>
#include <vector>

using namespace std;

long long answer = 0;

void mergeArea(vector<int> & arr, int left, int mid, int right) {
	int frontIdx = left;   // 앞 배열 인덱스
	int rearIdx = mid + 1; // 뒷 배열 인덱스
	int resultIdx = 0;  // 결과 배열 인덱스
	
	vector<int> temp(right - left + 1, 0);
	
	// merge할 배열 중 하나가 끝날 때 까지 채우기
	while(frontIdx <= mid && rearIdx <= right)
	{
		if(arr[frontIdx] <= arr[rearIdx])
			temp[resultIdx++] = arr[frontIdx++];
		else {
			temp[resultIdx++] = arr[rearIdx++];
			answer += (mid - frontIdx + 1) * 1LL;
		}
	}
	
	// 먼저 다 채운 배열이 뒷 배열이면 앞 배열 나머지 요소 채우기
	while(frontIdx <= mid) temp[resultIdx++] = arr[frontIdx++];
	
	// 먼저 다 채운 배열이 앞 배열이면 뒷 배열 나머지 요소 채우기
	while(rearIdx <= right) temp[resultIdx++] = arr[rearIdx++];
	
	for(int i = left; i <= right; i++) arr[i] = temp[i - left];
}

void mergeSort(vector<int> & arr, int left, int right) {
	if(left < right) {
		int mid = (left + right) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		mergeArea(arr, left, mid , right);
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0 ; i < n ; i++) cin >> arr[i];

	mergeSort(arr, 0, n - 1);

	cout << answer;

    return 0;
}