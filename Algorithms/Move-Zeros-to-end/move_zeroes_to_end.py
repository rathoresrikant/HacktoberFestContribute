def move_zeroes_to_end(arr):
    # Initialize a pointer for the position of non-zero elements
    non_zero_index = 0

    # Iterate through the array
    for i in range(len(arr)):
        if arr[i] != 0:
            # Move the non-zero element to the front
            arr[non_zero_index] = arr[i]
            non_zero_index += 1

    # Fill the remaining positions with zeroes
    for i in range(non_zero_index, len(arr)):
        arr[i] = 0

# Example usage
array = [0, 1, 0, 3, 12]
print("Original array:", array)
move_zeroes_to_end(array)
print("Array after moving zeroes:", array)
