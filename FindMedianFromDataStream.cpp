class MedianFinder {
    priority_queue<int> maxHeap; // max-heap for lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap for upper half

public:
    MedianFinder() { }

    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Rebalance
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) {
            return ((long long)maxHeap.top() + minHeap.top()) / 2.0;
        } else if(maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 * Space complexity: O(n) where n is the number of elements added
 * Time complexity: O(log n) for addNum and O(1) for findMedian
 */