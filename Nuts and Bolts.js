
class Solution {
    matchPairs(n, nuts, bolts) {
        // code here
        //Approach 1 -> Sorting nuts and bolts array -> T.c. O(nlogn) and S.C: O(logn)
        
        //Approach 2. -> reperesent a map
        //key - value !!
        //key -  { !,#,$,%,&,*,?,@,^ }
        //value - {0, 1,,1,1,0,0,0,1,1} based on nuts[] = {@, %, $, #, ^}, bolts[] = {%, @, #, $ ^}
        //TC - O(N) , SC: static size map O(1)
        const freq = new Array(256).fill(0);
        
        for(let i = 0; i<n; i++){
            freq[nuts[i].charCodeAt(0)]++;
        }
        
        let j = 0;
        for(let i = 0; i < 256; i++){
            if(freq[i] > 0){
                nuts[j] = String.fromCharCode(i);
                bolts[j] = String.fromCharCode(i);
                j++;
            }
        }
        return [nuts, bolts];
    }
}
