maxPairProduct :: [(Int,Int)] -> (Int,Int)
maxPairProduct = fst . maximum . map (\(x,y)->((x,y),x*y))

main = print $ maxPairProduct [(1,3),(2,2)]
