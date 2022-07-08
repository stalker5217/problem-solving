#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
	int capacity;
	unordered_map<int, int> cache;
	unordered_map<int, list<int>::iterator> address;
	list<int> recents;
   
public:
    LRUCache(int capacity) 
	: capacity(capacity) {}
    
    int get(int key) {
		if (cache.find(key) == cache.end()) {
			return -1;
		}

		recents.splice(recents.begin(), recents, address[key]);
		address[key] = recents.begin();

		return cache[key];
    }
    
    void put(int key, int value) {
		cache[key] = value;
		if (address.find(key) == address.end()) {
			recents.push_front(key);
		} else {
			recents.splice(recents.begin(), recents, address[key]);
		}

		address[key] = recents.begin();

		if (cache.size() > capacity) {
			int lru = recents.back();
			address.erase(lru);
			cache.erase(lru);
			recents.pop_back();
		}
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */