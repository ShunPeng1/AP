add :: (Int, Int) -> Int
add (x,y) = x+y

zeroto :: Int -> [Int]
zeroto n = [0..n]


mult :: Int -> (Int -> (Int -> Int))
mult x y z = x*y*z

fac :: Integral->Integral
fac n = product [1..n]

factorial n = product [1..n]



