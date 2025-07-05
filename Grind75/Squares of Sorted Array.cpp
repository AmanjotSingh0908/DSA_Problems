class Solution {
public:
    vector<int> squares;

    void findSquare(int num){
        squares.push_back(num * num);
    };

    vector<int> sortedSquares(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i++){
            findSquare(nums[i]);
        }
        sort(squares.begin(), squares.end());
        //to sort in descending order use sort(squares.begin(), squares.end(), greater<int>());
        return squares;
    }
};
