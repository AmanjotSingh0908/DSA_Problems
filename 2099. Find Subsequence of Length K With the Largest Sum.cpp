class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
		// Declare variables
        int n = nums.size(), i = 0, t = k;
		// Answer Array
        vector<int> ans;
		
		// Put first k elements
        while(t>0){
            ans.push_back(nums[i]);
            i++;
            t--;
        }
		
		//Loop Through Remaining Array
        for(int j=i;j<n;j++)
        {
			// Calcualate minimum from ans array 
            int mini = min_element(ans.begin(), ans.end()) - ans.begin();
			// Compare it with the current element
            if(ans[mini] < nums[j]){
                ans.erase(ans.begin()+mini);
                ans.push_back(nums[j]);
            }
            
        }
        return ans;
    }
};
