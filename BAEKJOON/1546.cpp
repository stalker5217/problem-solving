#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int n;
	scanf("%d", &n);

	vector<double> score;
	double max = -1;
	for (int i = 0; i < n; i++) {
		double temp;
		scanf("%lf", &temp);
		
		if (max < temp)
			max = temp;

		score.push_back(temp);
	}

	double sum = 0;
	for (int i = 0; i < n; i++) {
		score[i] = score[i] / max * 100;
		sum += score[i];
	}

	double avg = sum / score.size();
	printf("%.2lf", avg);


	return 0;
}