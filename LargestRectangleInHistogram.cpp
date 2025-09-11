/*
Heights should be in increasing order, to be able
to extend it to the right.
If we find a height which is smaller than the top of the stack,
we need to calculate the area with the height of the top of the stack
as the smallest (or minimum) height.
We pop the top and calculate the area with the popped height
as the smallest height.
The width is the distance between the current index and the index
of the new top of the stack after popping.

We are going to use montonic stack in here and maintain stack
with index + height pair. Index will not be the element's index 
it will be the index from where the rectangle can be extended to the right.
Pop elements from stack and calculate area update max Area if area > maxArea.

If there are elements left in stack after iterating through the heights,
we will pop all elements one by one and calculate area with each popped element

TC: O(N)
SC: O(N)
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st; // {index, height}
        int maxArea = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            int start = i; // index from where the rectangle can be extended to the right
            
            // If current height is less than the height of the top of the stack,
            // we need to pop from stack and calculate area
            while (!st.empty() && st.top().second > heights[i]) {
                int height = st.top().second;
                int index = st.top().first;
                st.pop();
                
                // Calculate area with popped height as the smallest height
                int area = height * (i - index);
                maxArea = max(maxArea, area);
                
                // Update start to the index of the popped element
                start = index;
            }
            
            // Push current height with updated start index
            st.push({start, heights[i]});
        }
        
        // Pop remaining elements from stack and calculate area
        while (!st.empty()) {
            int height = st.top().second;
            int index = st.top().first;
            st.pop();
            
            int area = height * (heights.size() - index);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};