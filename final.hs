import System.IO

getListItems :: [Int] -> String
getListItems [] = "Your list is empty"
getListItems (x:[]) = "Your list starts with " ++ show x
getListItems (x:y:[]) = "Your list starts with " ++ show x ++ " and " ++ show y
getListItems (x:ns) = "The first item is " ++ show x ++ " and the rest is " ++ show ns

main = do
    putStrLn "WHAT'S YOUR NAME"
    name <- getLine
    putStrLn ("HELLLO " ++ name)

times4 :: Int -> Int
times4 x = x * 4

add1 :: Int -> (Int -> Int)
add1 x y = x + y

add2 :: Int -> Int -> Int
add2 x y = x + y

add13 = add1 3
add24 = add2 4


doubleEvenNumber y = 
    if (y `mod` 2 /= 0)    
        then y
    else y * 2

myLast1 :: [Int] -> Int
myLast1 xs = head(reverse xs)


myLast2 :: [Int] -> Int
myLast2 (x:[]) = x
myLast2 (x:xs) = myLast2 xs


myInit1 :: [Int] -> [Int]
myInit1 xs = reverse(tail(reverse xs))

myInit2 :: [Int] -> [Int]
myInit2 (x:[]) = []
myInit2 (x:xs) = (x : (myInit2 xs))

odds n = map (\x -> x*2 + 1) [0..n-1]

myTail1 :: [a] -> [a]
myTail1 xs = 
    if null xs then []
    else tail xs


myTail2 :: [a] -> [a]
myTail2 xs 
    | null xs = []
    | otherwise = tail xs

myTail3 :: [a] -> [a]
myTail3 [] = []
myTail3 (x:xs) = xs 

-- CHAP 5

pyths :: Int -> [(Int, Int, Int)]
pyths n = [(x,y,z) | x <- [1..n], y <- [1..n], z <- [1..n], x*x + y*y == z*z]

factor :: Int -> [Int]
factor n = [x | x <- [1..n], n `mod` x == 0]

perfects :: Int -> [Int]
perfects n = [x | x <- [1..n], sum(init(factor x)) == x]

scalarProduct :: [Int] -> [Int] -> Int
scalarProduct xs ys = sum [ x * y | (x,y) <- (zip xs ys)]

-- CHAP 6
merge :: Ord a => [a] -> [a] -> [a]
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys) = 
    if x < y 
        then x : (merge xs (y:ys))
        else y : (merge (x:xs) ys)

msort :: Ord a => [a] -> [a]
msort [] = []
msort (x:[]) = [x]
msort xs = merge sorted1Halve sorted2halve
    where 
        sorted1Halve = msort (take (div (length xs) 2) xs)
        sorted2halve = msort (drop (div (length xs) 2) xs)


