
doubleAll :: [Int] -> [Int]
doubleAll [] = []
doubleAll (x:ns) = (x * 2) : doubleAll ns

positives :: [Int] -> [Int]
positives ns = filter(>=0)  ns

