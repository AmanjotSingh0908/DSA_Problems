class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        nodes = preorder.split(',')
        slots = 1
        
        for node in nodes:
            
            slots -= 1
            if slots < 0:
                return False
            if node != '#':
                slots += 2
        
        return slots == 0
