#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class El{
private:
	int ord;
	int age;
	string name;
public:
	El(int ord, int age, string name)
	: ord(ord), age(age), name(name)
	{}

	int getAge(){
		return age;
	}

	string getName(){
		return name;
	}

	bool operator<(const El & el){
		if(age > el.age){
			return false;
		}
		else if(age < el.age){
			return true;
		}
		else{
			if(ord > el.ord){
				return false;
			}
			else{
				return true;
			}
		}
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
	cin >> n;

	vector<El> elList;
	for(int i = 0 ; i < n ; i++){
		int age;
		string name;
		cin >> age >> name;
		
		El el(i, age, name);

		elList.push_back(el);
	}

	sort(elList.begin(), elList.end());
	
	for(int i = 0 ; i < n ; i++){
		cout << elList[i].getAge() << " " << elList[i].getName() << "\n";	
	}
    
    return 0;
}
