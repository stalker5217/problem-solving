#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef struct __Student {
	double score;
	int s_id;
	int rank;
} Student;

typedef struct __stuSort {
	bool operator()(const Student& s1, const Student& s2) {
		return s1.score > s2.score;
	}
} stuSort;

typedef struct __findStu {
	int s_id;
	bool operator()(const Student& s) {
		return s_id == s.s_id;
	}
} findStu;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		int target;
		vector<Student> stu;

		cin >> n;
		cin >> target;

		for (int i = 1; i <= n; i++) {
			Student temp;
			int s;

			temp.s_id = i;
			temp.score = 0;
			// 중간
			cin >> s;
			temp.score += (double)s * 0.35;

			// 기말
			cin >> s;
			temp.score += (double)s * 0.45;

			// 과제
			cin >> s;
			temp.score += (double)s * 0.20;

			stu.push_back(temp);
		}

		sort(stu.begin(), stu.end(), stuSort());

		for (int i = 0; i < n; i++)
			stu[i].rank = i;

		findStu findstu;
		findstu.s_id = target;
		vector<Student>::iterator iter = find_if(stu.begin(), stu.end(), findstu);

		cout << "#" << test_case << " ";

		switch ((iter->rank) / (n / 10)) {
		case 0:
			cout << "A+" << endl;
			break;
		case 1:
			cout << "A0" << endl;
			break;
		case 2:
			cout << "A-" << endl;
			break;
		case 3:
			cout << "B+" << endl;
			break;
		case 4:
			cout << "B0" << endl;
			break;
		case 5:
			cout << "B-" << endl;
			break;
		case 6:
			cout << "C+" << endl;
			break;
		case 7:
			cout << "C0" << endl;
			break;
		case 8:
			cout << "C-" << endl;
			break;
		case 9:
			cout << "D0" << endl;
			break;
		}
	}
	return 0;
}