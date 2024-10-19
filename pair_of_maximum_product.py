def max_product_pair(arr):
    # Edge case: If the array has less than two elements, return None
    if len(arr) < 2:
        return None
    
    # Initialize the two largest and two smallest numbers
    max1 = max2 = float('-inf')  # Two largest positive numbers
    min1 = min2 = float('inf')   # Two smallest negative numbers (most negative)

    for num in arr:
        # Update max1 and max2 for largest numbers
        if num > max1:
            max2 = max1
            max1 = num
        elif num > max2:
            max2 = num
        
        # Update min1 and min2 for smallest numbers (most negative)
        if num < min1:
            min2 = min1
            min1 = num
        elif num < min2:
            min2 = num

    # Calculate the products of the two largest and two smallest
    product1 = max1 * max2
    product2 = min1 * min2

    # Return the pair with the maximum product
    if product1 > product2:
        return (max1, max2), product1
    else:
        return (min1, min2), product2

# Example usage
arr = [1, 10, -5, 1, -100]
pair, product = max_product_pair(arr)
print(f"Pair with maximum product: {pair}")
print(f"Maximum product: {product}")
