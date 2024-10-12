class Solution(object):
    def shoppingOffers(self, price, special, needs, lookup=None):
        """
        :type price: List[int]
        :type special: List[List[int]]
        :type needs: List[int]
        :rtype: int
        """
        lookup = {} if lookup is None else lookup
        if str(needs) in lookup:
            return lookup[str(needs)]
        min_price = sum([needs[i] * price[i] for i in range(len(needs))])
        for offer in special:
            if all([offer[i] <= needs[i] for i in range(len(needs))]):
                new_needs = [needs[i] - offer[i] for i in range(len(needs))]
                min_price = min(min_price, offer[-1]+ self.shoppingOffers(price,special,new_needs,lookup))
        lookup[str(needs)] = min_price
        return min_price
        
#Memoization
