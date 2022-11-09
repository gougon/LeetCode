#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if (key2iter.find(key) == key2iter.end())
            return -1;

        auto iter = key2iter[key];
        pair<int, int> kv = *iter;
        key2val.erase(iter);
        key2val.push_back(kv);
        key2iter[key] = --key2val.end();
        return kv.second;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            key2iter[key]->second = value;
            return;
        }

        if (key2iter.size() == _capacity) {
            int keyDel = key2val.begin()->first;
            key2val.erase(key2val.begin());
            key2iter.erase(keyDel);
        }

        key2val.push_back({key, value});
        key2iter[key] = --key2val.end();
    }
private:
    int _capacity;
    list<pair<int, int>> key2val;
    unordered_map<int, list<pair<int, int>>::iterator> key2iter;
};

int main(int argc, char *argv[]) {
    LRUCache lRUCache = LRUCache(2);
    cout << lRUCache.get(2) << endl;
    lRUCache.put(2, 6);
    cout << lRUCache.get(1) << endl;
    lRUCache.put(1, 5);
    lRUCache.put(1, 2);
    cout << lRUCache.get(1) << endl;
    cout << lRUCache.get(2) << endl;
    return 0;
}
