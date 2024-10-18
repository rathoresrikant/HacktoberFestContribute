#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <list>

struct LRUCacheItem {
    LRUCacheItem(int timestamp, int key) : key(key), timestamp(timestamp) {}

    int timestamp;
    int key;
};

// Custom comparator for priority queue (lower timestamp has higher priority)
struct LRUCacheComp {
    bool operator()(const LRUCacheItem& item1, const LRUCacheItem& item2) {
        return item1.timestamp > item2.timestamp; // Reverse order for LRU
    }
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto itCache = cache.find(key);

        if (itCache != cache.end()) {
            updateRecentUsed(key); // Update timestamp on get
            return itCache->second;
        }

        return -1;
    }

    void put(int key, int value) {
        cache[key] = value;
        updateRecentUsed(key);
        invalidateCache();
    }

private:
    void updateRecentUsed(int key) {
        // Check if key exists in recent_used
        auto itRecentUsedLocation = recentUsedLocation.find(key);
        if (itRecentUsedLocation != recentUsedLocation.end()) {
            // Erase the old entry from the priority queue
            recent_used.erase(itRecentUsedLocation->second);
        }

        // Create a new entry with the current timestamp
        recent_used.push(LRUCacheItem(time++, key));  // Use a global time counter
        recentUsedLocation[key] = recent_used.end();
        --recentUsedLocation[key]; // Move iterator back one step to point to the newly added element
    }

    void invalidateCache() {
        if (cache.size() > capacity) {
            int keyToRemove = recent_used.top().key; // Get the least recently used key
            cache.erase(keyToRemove);
            recent_used.pop();
            recentUsedLocation.erase(keyToRemove);
        }
    }

    std::unordered_map<int, int> cache;
    std::priority_queue<LRUCacheItem, std::vector<LRUCacheItem>, LRUCacheComp> recent_used;
    std::unordered_map<int, std::priority_queue<LRUCacheItem, std::vector<LRUCacheItem>, LRUCacheComp>::iterator> recentUsedLocation;
    int capacity;
    static int time; // Global timestamp counter for LRU order
};

int LRUCache::time = 0; // Initialize static variable

int main() {
    LRUCache cache(2 /* capacity */);

    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << "> Get(1) = " << cache.get(1) << std::endl;   // returns 1
    cache.put(3, 3);                                         // evicts key 2
    std::cout << "> Get(2) = " << cache.get(2) << std::endl;   // returns -1 (not found)
    cache.put(4, 4);                                         // evicts key 1
    std::cout << "> Get(1) = " << cache.get(1) << std::endl;   // returns -1 (not found)
    std::cout << "> Get(3) = " << cache.get(3) << std::endl;   // returns 3
    std::cout << "> Get(4) = " << cache.get(4) << std::endl;   // returns 4
}
