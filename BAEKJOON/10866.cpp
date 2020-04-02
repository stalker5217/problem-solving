#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

class Node{
private:
	int value;
	Node * next;
public:
	Node(int value, Node * next)
	: value(value), next(next)
	{}

	int getValue(){
		return value;
	}
	void setValue(int value){
		this->value = value;
	}
	Node* getNext(){
		return next;
	}
	void setNext(Node * next){
		this->next = next;
	}
};

class Deque{
private:
	int size;
	Node * head;
	Node * tail;
public:
	Deque()
	{
		size = 0;
		head = NULL;
		tail = NULL;
	}

	int empty(){
		if(size == 0){
			return 1;
		}
		else{
			return 0;
		}
	}
	int mySize(){
		return this->size;
	}

	int front(){
		if(head == NULL){
			return -1;
		}
		else{
			return head->getValue();
		}
	}
	int back(){
		if(tail == NULL){
			return -1;
		}
		else{
			return tail->getValue();
		}
	}

	void push_front(int value){
		if(head == NULL){
			head = new Node(value, NULL);
			tail = head;
			size++;
		}
		else{
			Node * newHead = new Node(value, head);
			newHead->setNext(head);
			head = newHead;
			size++;
		}
	}

	void push_back(int value){
		if(tail == NULL){
			tail = new Node(value, NULL);
			head = tail;
			size++;
		}
		else{
			Node * newTail = new Node(value, NULL);
			tail->setNext(newTail);
			tail = newTail;
			size++;
		}
	}

	int pop_front(){
		if(head == NULL){
			return -1;
		}
		else if(head->getNext() == NULL){
			int ret = head->getValue();
			
			delete head;
			
			head = NULL;
			tail = NULL;

			size--;

			return ret;
		}
		else{
			int ret = head->getValue();
			Node * oldHead = head;
			head = oldHead->getNext();

			delete oldHead;

			size--;

			return ret;
		}
	}

	int pop_back(){
		if(tail == NULL){
			return -1;
		}
		else if(size == 1){
			int ret = tail->getValue();

			delete tail;

			head = NULL;
			tail = NULL;

			size--;

			return ret;
		}
		else{
			int ret = tail->getValue();
			Node * curNode = head;
			while(true){
				if(curNode->getNext() == tail){
					curNode->setNext(NULL);
					delete tail;
					tail = curNode;
					break;
				}
				curNode = curNode->getNext();
			}
			size--;
			return ret;
		}
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	Deque deque;

	for(int i = 0 ; i < n ; i++){
		string command;
		cin >> command;

		if(command.compare("push_front") == 0){
			int value;
			cin >> value;

			deque.push_front(value);
		}
		else if(command.compare("push_back") == 0){
			int value;
			cin >> value;

			deque.push_back(value);
		}
		else if(command.compare("pop_front") == 0){
			cout << deque.pop_front() << "\n";
		}
		else if(command.compare("pop_back") == 0){
			cout << deque.pop_back() << "\n";
		}
		else if(command.compare("size") == 0){
			cout << deque.mySize() << "\n";
		}
		else if(command.compare("empty") == 0){
			cout << deque.empty() << "\n";
		}
		else if(command.compare("front") == 0){
			cout << deque.front() << "\n";
		}
		else if(command.compare("back") == 0){
			cout << deque.back() << "\n";
		}
	}
    return 0;
}
