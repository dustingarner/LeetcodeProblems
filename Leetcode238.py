class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        product = 1
        product_sans_zero = 1
        zero_count = 0
        for i in nums:
            product *= i
            if i == 0:
                zero_count += 1
            if i != 0 or zero_count > 1:
                product_sans_zero *= i
        products = []
        for i in nums:
            if i != 0:
                products += [int(product / i)]
            else:
                products += [product_sans_zero]
        return products
