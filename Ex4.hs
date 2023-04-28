-- Implement the game of nim in Haskell, where the 
-- rules of the game are as follows:
-- + The board comprises five rows of stars:
-- 1: * * * * *
-- 2: * * * *
-- 3: * * *
-- 4: * *
-- 5: *
-- + Two players take it turn about to remove one or more stars from the end of a single row
-- + The winner is the player who removes the last star or stars from the board
-- HINT: Represent the board as a list of five integers that give the number of stars 
-- remaining on each row. For example, the initial board is [5,4,3,2,1]. 

import Data.List (intercalate)

-- A Nim game board is represented as a list of integers giving the number of stars remaining in each row
type Board = [Int]

-- The initial board configuration
initialBoard :: Board
initialBoard = [5, 4, 3, 2, 1]

-- Print the current board state
printBoard :: Board -> IO ()
printBoard = putStrLn . intercalate "\n" . zipWith (\row stars -> show row ++ ": " ++ concat (replicate stars "* ")) [1..]


-- Prompt the player for their move and return the updated board
makeMove :: Int -> Board -> IO Board
makeMove player board = do
  putStrLn $ "Player " ++ show player ++ " is playing ..."
  putStrLn "Row?"
  row <- readLn
  putStrLn "How many stars?"
  stars <- readLn
  if validMove board row stars
    then return $ updateBoard board row stars
    else do
      putStrLn "Invalid move, please try again."
      makeMove player board

-- Check if a move is valid
validMove :: Board -> Int -> Int -> Bool
validMove board row stars = row >= 1 && row <= length board && stars >= 1 && stars <= board !! (row - 1)

-- Update the board after a move
updateBoard :: Board -> Int -> Int -> Board
updateBoard board row stars = take (row - 1) board ++ [board !! (row - 1) - stars] ++ drop row board

-- Play the game
playGame :: Int -> Board -> IO ()
playGame player board = do
  printBoard board
  if isGameOver board
    then do
      putStrLn $ "Player " ++ show (otherPlayer player) ++ " wins!!!"
    else do
      updatedBoard <- makeMove player board
      playGame (otherPlayer player) updatedBoard

-- Check if the game is over
isGameOver :: Board -> Bool
isGameOver = all (== 0)

-- Determine the other player
otherPlayer :: Int -> Int
otherPlayer player = if player == 1 then 2 else 1

-- Start a new game
main :: IO ()
main = do
  putStrLn "Initializing ..."
  playGame 1 initialBoard