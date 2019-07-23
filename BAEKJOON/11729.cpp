#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void hanoi(int, int, int, int);
void printMove();

int moveCnt = 0;
vector<pair<int, int>> moveHistory;

int main()
{
    int n;
    cin >> n;

    hanoi(n, 1, 3, 2);
    cout << moveCnt << "\n";
    printMove();

    return 0;
}

void hanoi(int n, int from, int to, int by)
{
    if (n == 1)
    {
        moveCnt++;
        moveHistory.push_back(make_pair(from, to));
    }
    else
    {
        hanoi(n - 1, from, by, to);
        moveCnt++;
        moveHistory.push_back(make_pair(from, to));
        hanoi(n - 1, by, to, from);
    }
}
 
void printMove()
{
    for (int i = 0; i < moveHistory.size(); i++)
    {
        cout << moveHistory[i].first << " " << moveHistory[i].second << "\n";
    }
}