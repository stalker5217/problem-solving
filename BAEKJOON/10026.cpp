#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>

using namespace std;

int n;
char picture[100][100];
bool visit[100][100];

int sectionCnt = 0;
int noColor_sectionCnt = 0;

void initVisit();
void countSection(int r, int c);

pair<int, int> dir[4] = {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> picture[i][j];
        }
    }
    
    memset(visit, false, sizeof(visit));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(visit[i][j] == false){
                countSection(i, j);
                sectionCnt++;
            }
        }
    }


    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(picture[i][j] == 'G') picture[i][j] = 'R';
        }
    }

    memset(visit, false, sizeof(visit));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(visit[i][j] == false){
                countSection(i, j);
                noColor_sectionCnt++;
            }
        }
    }

    cout << sectionCnt << " " << noColor_sectionCnt;
    
    return 0;
}

void countSection(int r, int c){
    visit[r][c] = true;

    for(int i = 0 ; i < 4 ; i++){
        if(r + dir[i].first >= 0
        && r + dir[i].first < n
        && c + dir[i].second >= 0
        && c + dir[i].second < n
        && !visit[r + dir[i].first][c + dir[i].second]
        && picture[r + dir[i].first][c + dir[i].second] == picture[r][c]){
            countSection(r + dir[i].first, c + dir[i].second);
        }
    }
}