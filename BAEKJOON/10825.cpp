#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct __Student {
	string name;
	int korean;
	int english;
	int math;
} Student;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin >> n;
	vector<Student> arr;

	for(int i = 0 ; i < n ; i++) {
		Student student;
		cin >> student.name;
		cin >> student.korean >> student.english >> student.math;

		arr.push_back(student);
	}

	sort(arr.begin(), arr.end(), [](Student a, Student b) {
		if(a.korean > b.korean) return true;
		else if(a.korean < b.korean) return false;
		else if(a.english < b.english) return true;
		else if(a.english > b.english) return false;
		else if(a.math > b.math) return true;
		else if(a.math < b.math) return false;
		else return a.name < b.name;
	});

	for(Student student : arr) {
		cout << student.name << "\n";
	}

	return 0;
}