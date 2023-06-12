-- The initial board configuration
type Board = [Int]

initialBoard :: Board
initialBoard = [5, 4, 3, 2, 1]

printBoard :: Int -> Board -> IO()
printBoard _ [] = return()
printBoard row (x,board) = do
    putStrLn ((show row) ++ ": " ++ (replicate x '*'))
    printBoard (row+1) board

checkAllRow :: Board -> Bool
checkAllRow [] = True
checkAllRow (x:xs) = 
    if x > 0 
    then False
    else checkAllRow xs

checkWin :: Board -> String -> IO Bool
checkWin board player = do
    let win = checkAllRow board
    if win == True
    then do 
        putStrLn ("Player " ++ player ++ " won!")
    else return ()
    return win

getRowSize :: Int -> Board -> Int
getRowSize _ [] = -1
getRowSize i (x:xs) = 
    if i == 0 
    then x
    else getRowSize (i-1) xs

updateBoard :: Int -> Int -> Board -> Board
updateBoard _ _ [] = []
updateBoard row star (x:xs) = 
    if row == 0 
    then (x-star) : updateBoard (row-1) star xs
    else x : updateBoard (row-1) star xs


makeStar :: Int -> Board -> IO Board
makeStar rowNumber board = do
    putStrLn ("How many star?")
    starInput <- getLine
    let rowSize = getRowSize rowNumber board
    let starNumber = read starInput :: Int
    if ((0 < starNumber) && (starNumber <= rowSize))  
    then return (updateBoard rowNumber starNumber board)
    else makeStar rowNumber board


makeMove :: Board -> IO Board
makeMove board = do
    rowInput <- getLine
    let rowNumber = read rowInput :: Int
    if rowNumber > 0
        then makeStar (rowNumber+1) board
        else makeMove board

gameLoop :: Board -> IO ()
gameLoop board = do
    putStrLn "Player 1 is playing ..."
    boardAfter1 <- makeMove board
    printBoard 1 boardAfter1
    win2 <- checkWin boardAfter1 "2"
    if win2 == False
    then do
        putStrLn "Player 2 is playing ..."
        boardAfter2 <- makeMove boardAfter1
        printBoard 1 boardAfter2
        win1 <- checkWin boardAfter2 "1"
        if win1 == False
        then gameLoop boardAfter2
        else putStrLn "=============Game Over==========="
    else putStrLn "=============Game Over==========="


main :: IO ()
main = do    
    putStrLn "Welcome To Nim Game ..."
    putStrLn "Initializing ..."
    gameLoop initialBoard

