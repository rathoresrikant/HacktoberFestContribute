def find_peak_1d(arr):
    n = len(arr)
    
    if n == 1:
        return arr[0]
    if arr[0] >= arr[1]:
        return arr[0]
    if arr[n - 1] >= arr[n - 2]:
        return arr[n - 1]

    for i in range(1, n - 1):
        if arr[i] >= arr[i - 1] and arr[i] >= arr[i + 1]:
            return arr[i]

    return None  # In case no peak is found


def find_peak_2d(arr):
    if not arr or not arr[0]:
        return None
    
    rows = len(arr)
    cols = len(arr[0])
    
    def get_neighbors(r, c):
        neighbors = []
        if r > 0: neighbors.append(arr[r - 1][c])  # Top
        if r < rows - 1: neighbors.append(arr[r + 1][c])  # Bottom
        if c > 0: neighbors.append(arr[r][c - 1])  # Left
        if c < cols - 1: neighbors.append(arr[r][c + 1])  # Right
        return neighbors

    for r in range(rows):
        for c in range(cols):
            if all(arr[r][c] >= n for n in get_neighbors(r, c)):
                return arr[r][c]

    return None 

arr = [1, 3, 20, 4, 1, 0]
peak = find_peak_1d(arr)
print("Peak element in 1D array is:", peak)

arr_2d = [
    [10, 8, 10, 10],
    [14, 13, 12, 11],
    [15, 9, 16, 8],
    [20, 14, 17, 30]
]
peak_2d = find_peak_2d(arr_2d)
print("Peak element in 2D array is:", peak_2d) 