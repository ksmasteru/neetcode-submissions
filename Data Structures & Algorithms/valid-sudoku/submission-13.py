class Solution:
    def unvalidRow(self, Row:List[str]) -> bool:
        count = {}
        for i in range(len(Row)):
            if (Row[i] == "."):
                continue
            count[Row[i]] = 1 + count.get(Row[i], 0);
            if (count[Row[i]] > 1):
                return True
        return False
    
    def isValidSubSudoku(self, board: List[List[str]]) -> bool:
        for br in range(3):
            for bc in range(3):
                box = []
                for i in range(3 * br, 3 * br + 3):
                    for j in range(3 * bc, 3 * bc + 3):
                        box.append(board[i][j])
                if self.unvalidRow(box):
                    return False
        return True

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(len(board)):
            row = []
            column = []
            for j in range(len(board[0])):
                row.append(board[i][j])
                column.append(board[j][i])
            if (self.unvalidRow(row) or self.unvalidRow(column)):
                return False
        return self.isValidSubSudoku(board)               