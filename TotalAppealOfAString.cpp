class Solution {
public:
    long long appealSum(string s) {
        long long n = s.length();
        long long ans = 0;
        for(char ch = 'a'; ch <= 'z'; ch++){
            int last = -1;
            long long contirbution = n*(n+1)/2;
            for(int i = 0; i <n ; i++){
                if(s[i] == ch){
                    long long len = i - last - 1;
                    if(len > 0){
                        contirbution -= len*(len+1)/2;
                    }
                    last = i;
                }
            }
            long long len = n - last - 1;
            if(len > 0) {
                contirbution -= (len + 1)*len/2;
            }
            ans += contirbution;
        }
        return ans;
    }
};