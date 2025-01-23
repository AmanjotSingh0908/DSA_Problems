class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int x : nums) {
            add(x);
        }
    }

    int add(int val) {
        minQ.push(val);
        if (minQ.size() > k) {
            minQ.pop();
        }
        return minQ.top();
    }

private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minQ;
};
