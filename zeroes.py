def move_zeros_to_end(arr):
    # Pointer for the position of the next non-zero element
    non_zero_index = 0

    # Traverse the array
    for num in arr:
        # If the current number is not zero, place it at the non-zero index
        if num != 0:
            arr[non_zero_index] = num
            non_zero_index += 1

    # After all non-zero elements have been moved to the front,
    # fill the remaining positions with zeros
    for i in range(non_zero_index, len(arr)):
        arr[i] = 0

    return arr

# Example usage
if __name__ == "__main__":
    user_input = input("Enter numbers separated by spaces: ")
    arr = [int(num) for num in user_input.split()]

    result = move_zeros_to_end(arr)
    print("Array after moving zeros to the end:", result)
