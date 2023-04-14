
removeIndex :: Int -> ([a] -> [a])
removeIndex index (x:xs) 
    | index == 0 = xs
    | otherwise = x : removeIndex (index - 1) xs 
removeIndex _ [] = []


