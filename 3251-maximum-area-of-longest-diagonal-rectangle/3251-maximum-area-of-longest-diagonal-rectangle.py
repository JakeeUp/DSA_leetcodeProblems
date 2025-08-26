class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:

        best = 0
        ans = 0
        for L, W in dimensions:
            d = L * L + W * W
            if d > best:
                best = d
                ans = L * W
            elif d == best:
                ans = max(ans, L * W) 
        return ans
        