from collections import Counter

class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:

        #counting everything automaticcally 
        counts = Counter(nums)

        #get the top k pairs and extract just the numbers using the loop

        results = []

        for nums, freq in counts.most_common(k):
            results.append(nums)

        return results