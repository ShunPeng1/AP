xoa :: Int -> [Int] -> [Int]
xoa _ [] = []
xoa i ns = firstXoa ++ drop  (length firstXoa + i - 1) ns
    where 
        firstXoa = (xoaRegion i ns)

xoaRegion :: Int -> [Int] -> [Int]
xoaRegion 0 _  = []
xoaRegion i [] = []
xoaRegion i ns = before ++ [x | (x,y) <- zip ns [1..length ns], y < (length before + i *2 ) && y >= (length before + i )]
    where 
        before = (xoaRegion (i-1) ns)
        
        


