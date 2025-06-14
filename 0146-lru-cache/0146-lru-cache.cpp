class LRUCache {
public:
    int n;
    unordered_map<int,int>mp;
    vector<int>keys;
    LRUCache(int capacity) {
       n = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            // Remove old occurrence of key before pushing back
            for (auto it = keys.begin(); it != keys.end(); ++it) {
                if (*it == key) {
                    keys.erase(it);
                    break;
                }
            }
            keys.push_back(key);
            return mp[key];
        }
        return -1;
    }

    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key] = value;
            for (auto it = keys.begin(); it != keys.end(); ++it) {
                if (*it == key) {
                    keys.erase(it);
                    break;
                }
            }
            keys.push_back(key);
            return;
        }
        else if(mp.size() == n){
            int replace = keys.front();
            keys.erase(keys.begin());
            mp.erase(replace);
        }
        mp[key] = value;
        keys.push_back(key);
    
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */