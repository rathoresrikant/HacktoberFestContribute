def find_peak_1d(arr):
    n = len(arr)
    if n == 0:
        return None
    if n == 1 or arr[0] >= arr[1]:
        return arr[0]
    if arr[n - 1] >= arr[n - 2]:
        return arr[n - 1]

    for i in range(1, n - 1):
        if arr[i] >= arr[i - 1] and arr[i] >= arr[i + 1]:
            return arr[i]

    return None

def find_peak_2d(arr):
    def find_peak_recursive(start_row, end_row, cols):
        mid_row = (start_row + end_row) // 2
        max_index = 0
        
        for j in range(cols):
            if arr[mid_row][j] > arr[mid_row][max_index]:
                max_index = j

        if (mid_row > 0 and arr[mid_row][max_index] < arr[mid_row - 1][max_index]):
            return find_peak_recursive(start_row, mid_row - 1, cols)
        elif (mid_row < len(arr) - 1 and arr[mid_row][max_index] < arr[mid_row + 1][max_index]):
            return find_peak_recursive(mid_row + 1, end_row, cols)
        else:
            return arr[mid_row][max_index]

    if not arr or not arr[0]:
        return None
    return find_peak_recursive(0, len(arr) - 1, len(arr[0]))

if __name__ == "__main__":
    choice = input("Enter '1' for 1D peak finding or '2' for 2D peak finding: ")
    
    if choice == '1':
        arr_1d = list(map(int, input("Enter the elements of the 1D array separated by space: ").split()))
        peak = find_peak_1d(arr_1d)
        print("1D Peak:", peak)
    
    elif choice == '2':
        rows = int(input("Enter number of rows for 2D array: "))
        arr_2d = []
        for i in range(rows):
            row = list(map(int, input(f"Enter the elements of row {i + 1} separated by space: ").split()))
            arr_2d.append(row)
        peak = find_peak_2d(arr_2d)
        print("2D Peak:", peak)
    
    else:
        print("Invalid choice.")
