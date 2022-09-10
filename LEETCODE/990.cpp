#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        sort(equations.begin(), equations.end(), [](string a, string b) {
			return a[1] > b[1];
		});
        
        UnionFind uf(26);
        for(string equation : equations) {
            int left = equation[0] - 'a';
            int right = equation[3] - 'a';
            
            if (equation[1] == '=') {
                uf.merge(left, right);
            } else if (equation[1] == '!' && uf.find(left) == uf.find(right)) {
                return false;
            }
        }
        
        return true;
    }

private:
    class UnionFind {
	private:
        vector<int> parent;

	public:
        UnionFind(int n)
        : parent(n)
        {
            for(int i = 0 ; i < n ; i++){
                parent[i] = i;
            }
        }

        int find(int u) const {
            if(u == parent[u]) return u;
            return find(parent[u]);
        }

        void merge(int u, int v){
            u = find(u);
            v = find(v);

            if(u == v) return;
            parent[u] = v;
        }
    };
};