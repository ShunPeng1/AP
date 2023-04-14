myHead :: [a] -> a
myHead (x:_) = x

myTail :: [a] -> [a]
myTail (_:xs) = xs

add :: Int -> Int -> Int -> Int 
add x y z = x + y + z

-- 3 5 2
-- y z = 3 + y + z
-- z = 3 + 5 + z

odds n = map f [0..n-1]
    where
        f x = x*2 + 1

