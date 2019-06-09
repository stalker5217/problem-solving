#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int origin;
	scanf("%d", &origin);

	int num = origin;
	int cycle = 0;
	while (true) {
		int first;
		int second;
		int third;

		if (num < 10) {
			first = 0;
			second = num;
			third = first + num;
		}
		else {
			first = num / 10;
			second = num % 10;
			third = (first + second) % 10;
		}
		num = second * 10 + third;
		
		cycle++;
		if (num == origin)
			break;
	}

	printf("%d", cycle);
	
	return 0;
}