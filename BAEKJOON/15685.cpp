#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <deque>

using namespace std;

int map[101][101];

int main()
{
	//freopen("input.txt", "r", stdin);

	int result = 0;
	int dragon = 0;
	cin >> dragon;

	for (int d = 0; d < dragon; ++d)
	{
		int x, y;
		int direction;
		int generation;

		cin >> x >> y >> direction >> generation;
		deque<int> dirStack;
		dirStack.push_back(direction);

		for (int g = 0; g < generation; ++g)
		{
			deque<int> tempStack;
			tempStack.assign(dirStack.begin(), dirStack.end());

			while (true)
			{
				if (tempStack.empty())
				{
					break;
				}
				int topVal = tempStack[tempStack.size() - 1];
				tempStack.pop_back();

				// 시계 반대 방향 회전
				// 0->1 , 1->2 , 2->3 , 3->0
				topVal++;
				if (topVal == 4)
				{
					topVal = 0;
				}

				dirStack.push_back(topVal);
			}
		}
		// 커브 그리기
		map[y][x] = 1;
		for (int s = 0; s < dirStack.size(); s++)
		{
			if (dirStack[s] == 0)
			{
				x += 1;
			}
			else if (dirStack[s] == 1)
			{
				y -= 1;
			}
			else if (dirStack[s] == 2)
			{
				x -= 1;
			}
			else if (dirStack[s] == 3)
			{
				y += 1;
			}
			map[y][x] = 1;
		}
	}
	// 사각형 갯수 확인
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)
			{
				++result;
			}
		}
	}

	cout << result << "\n";
	return 0;
}