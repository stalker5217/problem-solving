#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int num;
		cin >> num;

		int command, accel;
		int velocity = 0;
		int distance = 0;

		for (int i = 0; i < num; i++) {
			cin >> command;

			switch (command) {
			case 0:
				break;
			case 1:
				cin >> accel;
				velocity += accel;
				break;
			case 2:
				cin >> accel;
				if (velocity >= accel)
					velocity -= accel;
				else
					velocity = 0;
				break;
			}

			if (velocity >= 0)
				distance += velocity;

		}

		cout << "#" << test_case << " " << distance << endl;
	}
	return 0;
}