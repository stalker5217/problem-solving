#include <iostream>
#include <string>

using namespace std;

struct __Node {
	__Node* next;
	__Node* previous;
	
	char value;

	__Node(char v) 
	: value(v), previous(nullptr), next(nullptr) 
	{}
};
typedef __Node Node;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s; 
	cin >> s;
	
	Node* dummyHead = new Node('~');
	Node* cur = dummyHead;
	for(int i = 0 ; i < s.size() ; i++) {
		Node* nextNode = new Node(s[i]);
		nextNode->previous = cur;
		cur->next = nextNode;
		
		cur = nextNode;
	}

	Node* dummyRear = new Node('~');
	dummyRear->previous = cur;
	cur->next = dummyRear;

	int commandCnt; 
	cin >> commandCnt;
	
	while(commandCnt--) {
		string command; 
		cin >> command;

		if(command[0] == 'L' && cur != dummyHead) cur = cur->previous;
		else if(command[0] == 'D' && cur->next != dummyRear) cur = cur->next; 
		else if(command[0] == 'B') {
			if(cur != dummyHead) {
				cur->previous->next = cur->next;
				cur->next->previous = cur->previous;
				cur = cur->previous;
			}
		}
		else if(command[0] == 'P') {
			string character; cin >> character;
			Node* newNode = new Node(character[0]);
			
			newNode->previous = cur;
			newNode->next = cur->next;

			cur->next->previous = newNode;
			cur->next= newNode;
			
			cur = newNode;
		}
	}

	cur = dummyHead->next;
	while(cur != dummyRear) {
		cout << cur->value;
		cur = cur->next;
	}

	return 0;
}