#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printPreOrder(const int &, const int &, const int &, const int &);

vector<int> inOrder;
vector<int> postOrder;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
	cin >> size;

	inOrder.assign(size, 0);
	postOrder.assign(size, 0);

	for(int i = 0 ; i < size ; i++) cin >> inOrder[i];
	for(int i = 0 ; i < size ; i++) cin >> postOrder[i];

	printPreOrder(0, size, 0, size);
    
    return 0;
}

void printPreOrder(const int & in_start, const int & in_end, const int & post_start, const int & post_end){
	if((in_start >= in_end) || (post_start >= post_end)) return;
	
	const int root = postOrder[post_end - 1];
	cout << root << " ";

	// In Order 결과로 LEFT, RIGHT Tree 나누기
	const int inRootIdx = find(inOrder.begin() + in_start, inOrder.begin() + in_end, root) - inOrder.begin();

	printPreOrder(in_start, inRootIdx, post_start, post_start + (inRootIdx - in_start));
	printPreOrder(inRootIdx + 1, in_end, post_start + (inRootIdx - in_start), post_end - 1);
}