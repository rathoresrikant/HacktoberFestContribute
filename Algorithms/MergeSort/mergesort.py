def merge_sort(arr):
    """Sorts an array using the merge sort algorithm."""
    if len(arr) <= 1:
        return arr  # Base case: arrays with 0 or 1 element are already sorted

    # Step 1: Divide the array into two halves
    mid = len(arr) // 2
    left_half = merge_sort(arr[:mid])  # Sort the left half
    right_half = merge_sort(arr[mid:])  # Sort the right half

    # Step 2: Merge the sorted halves
    return merge(left_half, right_half)

def merge(left, right):
    """Merges two sorted arrays into a single sorted array."""
    sorted_array = []
    left_index, right_index = 0, 0

    # Step 3: Compare elements from both halves and merge them in sorted order
    while left_index < len(left) and right_index < len(right):
        if left[left_index] < right[right_index]:
            sorted_array.append(left[left_index])
            left_index += 1
        else:
            sorted_array.append(right[right_index])
            right_index += 1

    # Step 4: Append any remaining elements from both halves
    sorted_array.extend(left[left_index:])  # Add remaining elements from left
    sorted_array.extend(right[right_index:])  # Add remaining elements from right

    return sorted_array

# Example usage
if __name__ == "__main__":
    sample_array = [38, 27, 43, 3, 9, 82, 10]
    sorted_array = merge_sort(sample_array)
    print("Sorted array:", sorted_array)
