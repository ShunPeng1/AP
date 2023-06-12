import Text.Read (readMaybe)
import Data.Maybe (isJust, fromJust)

main :: IO ()
main = do
  putStrLn "Initializing..."
  num1 <- getPositiveNumber "Input the number 1: "
  num2 <- getPositiveNumber "Input the number 2: "
  putStrLn $ "The GCD of " ++ show num1 ++ " and " ++ show num2 ++ " is " ++ show (gcd num1 num2)

getPositiveNumber :: String -> IO Int
getPositiveNumber prompt = do
  putStrLn prompt
  input <- getLine
  case readMaybe input of
    Nothing -> do
      putStrLn "Invalid input. Please enter a positive integer."
      getPositiveNumber prompt
    Just n | n <= 0 -> do
      putStrLn "The number is negative or zero. Please enter a positive integer."
      getPositiveNumber prompt
           | otherwise -> return n
