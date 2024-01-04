class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        if len(prices) == 1:
            return max_profit
        low = 0
        high = 0

        for indi, i in enumerate(prices):
            if indi < 1:
                continue
            if i > prices[high]:
                high = indi
                temp_max = prices[high] - prices[low]
                max_profit = temp_max if temp_max > max_profit else max_profit
                continue
            if i >= prices[low]:
                continue
            if indi == len(prices) - 1:
                break
            low = indi
            high = indi + 1
            temp_max = prices[high] - prices[low]
            max_profit = temp_max if temp_max > max_profit else max_profit
        return max_profit
            
        
