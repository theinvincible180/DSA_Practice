class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        check = [0 for i in range(0, 9)]

        for i in range(0, 9):
            check[:] = [0] * len(check)
            for j in range(0, 9):
                if board[i][j] != ".":
                    idx = int(board[i][j])
                    check[idx-1] += 1

                    if check[idx-1] > 1:
                        return False
        
        check[:] = [0] * len(check)
        
        for i in range(0, 9):
            check[:] = [0] * len(check)
            for j in range(0, 9):
                if board[j][i] != ".":
                    idx = int(board[j][i])
                    check[idx-1] += 1

                    if check[idx-1] > 1:
                        return False

        check[:] = [0] * len(check)

        for i in range(0, 9):
            check[:] = [0] * len(check)
            for j in range(0, 3):
                for k in range(0, 3):
                    row = (i//3) * 3 + j
                    col = (i%3) * 3 + k

                    if board[row][col] != ".":
                        idx = int(board[row][col])
                        check[idx-1] += 1

                        if check[idx-1] > 1:
                            return False


        return True
        