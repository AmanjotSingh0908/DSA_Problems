class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> all_unique;

        unordered_set<int> last_and;
        for(int i = 0; i < n; i++){
            unordered_set<int> new_and_cnt;
            new_and_cnt.insert(arr[i]);

            for(auto v : last_and){
                new_and_cnt.insert(v | arr[i]);
            }
            for(auto v : new_and_cnt){
                all_unique.insert(v);
            }
            last_and = new_and_cnt;
        }
        return all_unique.size();
    }
};
