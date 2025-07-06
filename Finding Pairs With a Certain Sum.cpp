class FindSumPairs {
    vector<int> nums1, nums2;
    unordered_map<int, int> freq;
public:
    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        nums1 = n1;
        nums2 = n2;
        for(int num : nums2)
            freq[num]++;
    }
    
    void add(int index, int val) {
        int oldVal = nums2[index];
        freq[oldVal]--;
        nums2[index] += val;
        freq[nums2[index]]++;
    }
    
    int count(int tot) {
        int result = 0;
        for(int num : nums1) {
            int needed = tot - num;
            result += freq[needed];
        }
        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
