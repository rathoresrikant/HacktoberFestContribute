timesM :: Matrix -> Matrix -> Matrix
timesM mat1 mat2[ [ dotprod r c | c <- (transpose mat2) ] |  r <- mat1 ]
    where
        dotprod :: [Rational] -> [Rational] -> Rational
        dotprod xs ys = sum (zipWith (\x -> \y -> x*y) xs ys)

nthfib n = foldr (timesM) [[1,0],[0,1]] (take n (repeat [[1,1],[1,0]]))
