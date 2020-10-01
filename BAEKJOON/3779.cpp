#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPartialMatch(const string &);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test_case = 1;
	while (true)
	{
		int size;
		cin >> size;

		if (size == 0)
			break;

		string N;
		cin >> N;

		vector<int> pi = getPartialMatch(N);

		cout << "Test case #" << test_case++ << "\n";
		for (int i = 0; i < N.size(); i++)
		{
			if (i + 1 - pi[i] == 0) continue;

			if (pi[i] == 0 || pi[i] % (i + 1 - pi[i]));
			else
				cout << (i + 1) << " " << (i + 1) / (i + 1 - pi[i]) << "\n";
		}
		cout << "\n";
	}

	return 0;
}

vector<int> getPartialMatch(const string &N)
{
	vector<int> pi(N.size(), 0);

	int matched = 0;
	for (int i = 1; i < N.size(); i++)
	{
		while (matched > 0 && N[i] != N[matched])
			matched = pi[matched - 1];
		if (N[i] == N[matched])
			pi[i] = ++matched;
	}

	return pi;
}
