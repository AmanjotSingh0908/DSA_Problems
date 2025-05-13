class Solution {
public:

        /*
                    f(4) - in how many unique ways u can reach 4 chairs
                    /   \
                  f(3)  f(2) 
                  /  \      \  \
                 f(2) f(1) f(1) f(2)
                 /                 \
                f(1)               f(1)

            if 3 can be reached in unique 'x' ways then 4 'x' ways can also be utilised to reach 4 || so what ever the existing states use them to reach (existing + 1 state)

            if 2 can be reached in unique 'y' ways then 4 'y' ways can also be utilised to reach 4
            so to reach 4, (x + y) paths/ways can be utilised to reach 4

            Solve using Recursion + Memoization
        */
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1); // memo[i] will store number of ways to reach step i
        return climb(n, memo);
    }

private:
    int climb(int n, vector<int>& memo) {
        if (n <= 1) return 1; // base cases
        if (memo[n] != -1) return memo[n]; // return memoized result

        // store the result in memo before returning
        memo[n] = climb(n - 1, memo) + climb(n - 2, memo);
        return memo[n];
    }
};

/*Another Approach*/
class Solution {
public:

        /*
                    f(4) - in how many unique ways u can reach 4 chairs
                    /   \
                  f(3)  f(2) 
                  /  \      \  \
                 f(2) f(1) f(1) f(2)
                 /                 \
                f(1)               f(1)

            if 3 can be reached in unique 'x' ways then 4 'x' ways can also be utilised to reach 4 || so what ever the existing states use them to reach (existing + 1 state)

            if 2 can be reached in unique 'y' ways then 4 'y' ways can also be utilised to reach 4
            so to reach 4, (x + y) paths/ways can be utilised to reach 4

            Solve using Recursion + Memoization
        */
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1); // memo[i] will store number of ways to reach step i
        return climb(n, memo);
    }

private:
    int climb(int n, vector<int>& memo) {
        if (n <= 1) return 1; // base cases
        //if in case 'n' goes negative
        if(n < 0){
            return 0;
        }

        if (memo[n] != -1) return memo[n]; // return memoized result


        int x = climb(n-1,memo);
        int y = climb(n-2, memo);

        return memo[n] = x + y;
    }
};

    
