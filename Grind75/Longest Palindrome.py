class Solution:
    def longestPalindrome(self, s: str) -> int:
        seen = set()
        res = 0

        for c in s:
            if c in seen:
                seen.remove(c)
                res += 2

            else:
                seen.add(c)

     #if set is not empty , i.e., there's a character with odd frequency or you can code it similart to the 'return' statement
        # if seen:       
        #     res += 1

        return res  +1 if seen else res
