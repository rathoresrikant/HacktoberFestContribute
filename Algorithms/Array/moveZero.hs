moveZero :: [Int] -> [Int]
moveZero arr = filter (/= 0) arr ++ filter (== 0) arr

main = print $ moveZero [1,3,0,6,0,3,0,0]
