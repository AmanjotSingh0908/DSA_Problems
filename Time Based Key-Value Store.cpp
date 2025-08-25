class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()) return "";

        auto& values = store[key];
        string res = "";

        int l = 0, r = values.size() - 1;
        while(l <= r) {
            int m = (l+r)/2;
            if(values[m].second <= timestamp) {
                res = values[m].first;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
