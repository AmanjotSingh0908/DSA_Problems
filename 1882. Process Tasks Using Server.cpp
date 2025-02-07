class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size(), time = 0;
        using p = pair<int, int>;
        priority_queue<p, vector<p>, greater<p>> free, occ;
        for(int i = 0 ; i < n ; i++)
            free.push({servers[i], i});
        vector<int> ans(m);
        for(int t = 0 ; t < m ; t++){
            time = max(time, t);
            while(occ.size() && occ.top().first <= time){
                free.push({servers[occ.top().second], occ.top().second});
                occ.pop();
            }
            if(!free.size()){
                time = occ.top().first;
                while(occ.size() && occ.top().first <= time){
                    free.push({servers[occ.top().second], occ.top().second});
                    occ.pop();
                }
            }
            occ.push({time + tasks[t], free.top().second});
            ans[t] = free.top().second;
            free.pop();
        }
        return ans;
    }
};
