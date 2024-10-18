def move_zeros_to_end(arr):
    non_zero_index = 0  # Pointer for the position of non-zero elements

    # Traverse the array
    for i in range(len(arr)):
        # If the current element is non-zero
        if arr[i] != 0:
            # Move it to the non-zero index position
            arr[non_zero_index] = arr[i]
            non_zero_index += 1  # Increment the non-zero index

    # Fill the remaining positions with zeros
    for i in range(non_zero_index, len(arr)):
        arr[i] = 0

    return arr  # Return the modified array

# Example usage:
arr = [0, 1, 0, 3, 12]
print(move_zeros_to_end(arr))  # Output: [1, 3, 12, 0, 0]
