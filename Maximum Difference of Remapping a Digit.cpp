class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        string maxi = "";
        string mini = "";
        int n = str.size();
        char ele = ' ';

        for(int i = 0; i < n; i++){
            if(str[i] != '9'){
                ele = str[i];
                break;
            }
        }

        for(int i = 0; i < n; i++){
            if(ele == str[i]) maxi += '9';
            else maxi += str[i];
        }

        for(int i = 0; i < n; i++){
            if(str[0] == str[i]) mini += '0';
            else mini += str[i];
        }
        return stoi(maxi) - stoi(mini);

    }
};

/*
To get the maximum number:
Find the first digit not equal to '9'.
Replace all occurrences of that digit with '9'.
To get the minimum number:
Replace all occurrences of the first digit with '0' (to minimize).
*/
