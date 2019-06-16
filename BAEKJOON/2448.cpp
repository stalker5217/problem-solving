#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

void makeStar(char **, int, int, int);

int main(int argc, char** argv)
{
	char **star;
	int height;
	scanf("%d", &height);
	int width = height * 2 - 1;

	star = new char*[height];
	for (int i = 0; i < height; i++) {
		star[i] = new char[width];
		memset(star[i], ' ', sizeof(char) * width);
	}

	makeStar(star, height, width/2, 0);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%c", star[i][j]);
		}
		printf("\n");
	}


	for (int i = 0; i < height; i++) {
		delete[] star[i];
	}
	delete star;

	return 0;
}

void makeStar(char** star, int height, int x, int y) {
	
	if (height == 3) {
		star[y][x] = '*';
		star[y + 1][x - 1] = '*';
		star[y + 1][x + 1] = '*';
		star[y + 2][x - 2] = '*';
		star[y + 2][x - 1] = '*';
		star[y + 2][x] = '*';
		star[y + 2][x + 1] = '*';
		star[y + 2][x + 2] = '*';

		return;
	}


	else {
		makeStar(star, height/2, x, y);
		makeStar(star, height/2, x - height/2, y + height/2);
		makeStar(star, height/2, x + height/2, y + height/2);
	}
}