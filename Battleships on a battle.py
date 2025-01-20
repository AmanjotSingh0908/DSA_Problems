class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        if not board:
            return 0
        
        m, n = len(board), len(board[0])
        count = 0
        
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'X':
                    if i == 0 or board[i-1][j] == '.':  # No 'X' above
                        if j == 0 or board[i][j-1] == '.':  # No 'X' to the left
                            count += 1
        return count


#This is similar to Number of islands (there we need to do DFS)
