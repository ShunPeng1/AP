hangman :: IO ()
hangman = do putStrLn "Think of a word: "

word  sgetLine
putStrLn "Try to guess it:"
play word

We adopt a top down approach to implementing
hangman in Haskell, starting as follows: 15
The action sgetLine reads a line of text from the
keyboard, echoing each character as a dash:
sgetLine :: IO String
sgetLine = do x  getCh

if x == '\n' then
do putChar x
return []
else
do putChar '-'
xs  sgetLine
return (x:xs)

16

import System.IO
getCh :: IO Char
getCh = do hSetEcho stdin False

x  getChar
hSetEcho stdin True
return x

The action getCh reads a single character from the
keyboard, without echoing it to the screen: 17
The function play is the main loop, which requests
and processes guesses until the game ends.
play :: String  IO ()
play word =
do putStr "? "
guess  getLine
if guess == word then
putStrLn "You got it!"
else
do putStrLn (match word guess)
play word

4

18
The function match indicates which characters in
one string occur in a second string:

For example:
> match "haskell" "pascal"
"-as--ll"
match :: String  String  String
match xs ys =
[if elem x ys then x else '-' | x  xs]

19

Exercise
Implement the game of nim in Haskell, where the
rules of the game are as follows:
z The board comprises five rows of stars:
1: * * * * *
2: * * * *
3: * * *
4: * *
5: *

20
z Two players take it turn about to remove one
or more stars from the end of a single row.
z The winner is the player who removes the last
star or stars from the board.
Hint:
Represent the board as a list of five integers that
give the number of stars remaining on each row.
For example, the initial