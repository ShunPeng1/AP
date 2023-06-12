
removeIndex :: Int -> [a] -> [a]
removeIndex _ [] = []
removeIndex i (x:xs)  
    | i == 0 = (removeIndex (i-1) xs)
    | otherwise = x : (removeIndex (i-1) xs)

