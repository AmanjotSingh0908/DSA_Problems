class Solution {
    #define ll long long
    #define pii pair<int,int>
public:
    long long findScore(vector<int>& nums) {
        //min heap + sort
        int n = nums.size();
        priority_queue<pii,vector<pii>,greater<pii>> minheap;
        for(int i=0; i<n; ++i){
            minheap.push(make_pair(nums[i], i));
        }

        unordered_set<int> marked_index;
        ll sum = 0;
        while(!minheap.empty()){
            pii curr = minheap.top();
            minheap.pop();

            int val = curr.first;
            int index = curr.second;
            if(marked_index.count(index)){
                continue;
            }

            sum += val;
            marked_index.insert(index);
            marked_index.insert(index-1);
            marked_index.insert(index+1);
        }
        return sum;
    }
};
