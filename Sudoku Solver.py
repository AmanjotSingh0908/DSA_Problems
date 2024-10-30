class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        
        BOARD_SIZE = len(board)
        def is_valid(row, col, str_val):
            for i in range(9):
                if board[row][i] == str_val: return False
                if board[i][col] == str_val: return False
                if board[3*(row//3)+i//3][3*(col//3)+i%3] == str_val : return False
            return True

        def solve(row=0, col=0):
            if row == BOARD_SIZE: return True
            if col == BOARD_SIZE: return solve(row+1, 0)
            if board[row][col] != ".": return solve(row,col+1)

            for i in range(1, BOARD_SIZE+1):
                if is_valid(row, col, str(i)):
                    board[row][col] = str(i)
                    if solve(row, col+1):
                        return True
                    else:
                        board[row][col] = "."
            return False
        solve()
        
