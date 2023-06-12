doubleAll :: [Int] -> [Int]
doubleAll [] = []
doubleAll (x:xs) = (x * 2) : (doubleAll xs) 

positives :: [Int] -> [Int]
positives xs = [x | x <- xs, x > 0]

