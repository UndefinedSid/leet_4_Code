class LRUCache {
public:
    list<int> dlList;
    map<int, pair<list<int>::iterator, int>> cacheMap;
    int n;

    void makeRecentUsed(int key){
        dlList.erase(cacheMap[key].first);
        dlList.push_front(key);
        cacheMap[key].first=dlList.begin();
    }

    LRUCache(int capacity) { 
        this->n = capacity; 
    }

    int get(int key) {
        if (!cacheMap.count(key)) {
            return -1;
        } else {
            makeRecentUsed(key);
            return cacheMap[key].second;
        }
    }

    void put(int key, int value) {
        if(cacheMap.count(key)){
            cacheMap[key].second=value;
            makeRecentUsed(key);
        }else{
            dlList.push_front(key);
            cacheMap[key]={dlList.begin(),value};
            n--;
        }

        if(n  < 0){
            cacheMap.erase(dlList.back());
            dlList.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */