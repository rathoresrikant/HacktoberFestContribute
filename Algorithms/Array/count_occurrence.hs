count :: Eq a => a -> [a] -> Int
count x = foldl (\i y -> if y==x then i+1 else i) 0

main = print $ count 3 [1,3,5,3,1]
