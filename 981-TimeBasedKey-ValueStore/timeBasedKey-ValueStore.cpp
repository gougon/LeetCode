#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        _hashMap[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        unordered_map<string, map<int, string>>::iterator m = _hashMap.find(key);
        if (m == _hashMap.end()) return "";
        map<int, string>::iterator h = m->second.upper_bound(timestamp);
        if (h == m->second.begin()) return "";
        return prev(h)->second;
    }
private:
    unordered_map<string, map<int, string>> _hashMap;
};

int main() {
    TimeMap timeMap = TimeMap();
    timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
    cout << timeMap.get("foo", 1) << endl;         // return "bar"
    cout << timeMap.get("foo", 3) << endl;         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
    timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
    cout << timeMap.get("foo", 4) << endl;         // return "bar2"
    cout << timeMap.get("foo", 5) << endl;         // return "bar2"
    return 0;
}
