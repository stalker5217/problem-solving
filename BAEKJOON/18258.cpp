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

class Queue{
private:
	int size;
	Node * head;
	Node * tail;
public:
	Queue()
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

	void push(int value){
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

	int pop(){
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
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	Queue queue;

	for(int i = 0 ; i < n ; i++){
		string command;
		cin >> command;

		if(command.compare("push") == 0){
			int value;
			cin >> value;

			queue.push(value);
		}
		else if(command.compare("pop") == 0){
			cout << queue.pop() << "\n";
		}
		else if(command.compare("size") == 0){
			cout << queue.mySize() << "\n";
		}
		else if(command.compare("empty") == 0){
			cout << queue.empty() << "\n";
		}
		else if(command.compare("front") == 0){
			cout << queue.front() << "\n";
		}
		else if(command.compare("back") == 0){
			cout << queue.back() << "\n";
		}
	}
    return 0;
}
