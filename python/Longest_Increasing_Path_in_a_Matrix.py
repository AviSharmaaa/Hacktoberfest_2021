# Problem Description:- Longest_Increasing_Path_in_a_Matrix
#Link:- https://leetcode.com/problems/longest-increasing-path-in-a-matrix/


class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        R, C, longest = len(matrix), len(matrix[0]), 0
        
        dp = [[0]*C for _ in range(R)]
        dirr = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        
        def dfs(r, c):
            if dp[r][c] > 0:
                return dp[r][c]
            
            maxx = 0
            for dr, dc in dirr:
                x, y = dr+r, dc+c
                if (0 <= x < R and 0 <= y < C and matrix[x][y] > matrix[r][c]):
                    tmp = dfs(x, y)
                    maxx = max(maxx, tmp)
            
            dp[r][c] = maxx + 1
            return dp[r][c]
            
        for r in range(R):
            for c in range(C):
                maxSoFar = dfs(r, c)
                longest = max(longest, maxSoFar)
        
        return longest
