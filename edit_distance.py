
def edit_distance(str1, str2):
    m = len(str1)
    n = len(str2)
    
    dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
    
    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0:
                dp[i][j] = j
            elif j == 0:
                dp[i][j] = i
            elif str1[i - 1] == str2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1])
                
    return dp[m][n]

str1 = "kitten"
str2 = "sitting"
print("The Edit Distance is:", edit_distance(str1, str2))
