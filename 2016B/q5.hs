{-
    COMP0002 Q5

    Given `map`, `foldr`, `filter`
-}

import Data.Char

{-
    Q5(a)

    pre-condition:
        Constraints on parameters and global states before function is executed.
    
    side-effect:
        Modifying some external state outside of the function.
    
    operator-section:
        Partial application of an operator, e.g.
            Left section: (3 *)
            Right section: (* 3)
    
    higher-order function:
        A function which takes another function as an parameter
-}

-- Q5(b)
raised :: IO ()
raised = do
    putStrLn "Enter a line of text:"
    line <- getLine
    putStrLn $ capitalized line
        where
            capitalized xs = map toUpper xs

-- Q5(c)
zipWith'' :: (a -> a -> a) -> [a] -> [a] -> [a]
zipWith'' f [] [] = []
zipWith'' f [x] [] = []
zipWith'' f [] [y] = []
zipWith'' f (x:xs) (y:ys) = (f x y) : zipWith'' f xs ys

-- Q5(d)
zipWith''' :: (a -> a -> a) -> [a] -> [a] -> [a]
zipWith''' f xs ys = map (uncurry $ f) pairs
    where 
        pairs = zip xs ys

-- Q5(e)(i)
-- Note `t` where is not constained to be strictly `Int`, instead, only 
-- operations defined on it are constrained.
data Vector t = Vector [t] deriving (Show)

ok :: Vector Int -> Vector Int -> Bool
ok (Vector xs) (Vector ys)
    | null xs || null ys = False
    | length xs == length ys = True
    | otherwise = False

sum' :: [Int] -> Int
sum' xs = foldr (+) 0 xs

dotProduct :: Vector Int -> Vector Int -> Int
dotProduct (Vector xs) (Vector ys)
    | ok (Vector xs) (Vector ys) = sum' (zipWith'' (*) xs ys)
    | otherwise = error "invalid vectors"
