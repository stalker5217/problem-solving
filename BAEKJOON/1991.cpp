#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

typedef struct __TreeNode{
	char value;
	struct __TreeNode * left = nullptr;
	struct __TreeNode * right = nullptr;
} TreeNode;

TreeNode* makeNode(const char value);
void preOrder(TreeNode * node);
void inOrder(TreeNode * node);
void postOrder(TreeNode * node);
void releaseMemory(TreeNode * node);

unordered_map<char, string> nodeInfo;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
	cin >> size;

	// ignore '\n'
	cin.ignore(1, 13);
	for(int i = 0 ; i < size ; i++){
		string temp;
		getline(cin, temp);
		nodeInfo[temp[0]] = temp;
	}

	TreeNode * root = makeNode('A');

	preOrder(root); cout << "\n";
	inOrder(root); cout << "\n";
	postOrder(root);
	releaseMemory(root);

    return 0;
}

TreeNode* makeNode(const char value){
	TreeNode * curNode = new TreeNode();
	curNode->value = value;

	string info = nodeInfo[value];
	char left = info[2];
	char right = info[4];

	if(left != '.') curNode->left = makeNode(left);
	if(right != '.') curNode->right = makeNode(right);

	return curNode;
}

void preOrder(TreeNode * node){
	cout << node->value;
	if(node->left != nullptr) preOrder(node->left);
	if(node->right != nullptr) preOrder(node->right);
}

void inOrder(TreeNode * node){
	if(node->left != nullptr) inOrder(node->left);
	cout << node->value;
	if(node->right != nullptr) inOrder(node->right);
}

void postOrder(TreeNode * node){
	if(node->left != nullptr) postOrder(node->left);
	if(node->right != nullptr) postOrder(node->right);
	cout << node->value;
}

void releaseMemory(TreeNode * node){
	TreeNode * left = node->left;
	TreeNode * right = node->right;

	delete node;

	if(left != nullptr) releaseMemory(left);
	if(right != nullptr) releaseMemory(right);
}