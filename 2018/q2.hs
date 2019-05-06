{-
    COMP0002 2018 Q2
    
    Given `foldr`, `map`, `filter`.
-}

{-
    Q2(a)
        1.  > 4 + 6.0
            = 10.0
        2.  > 27 == "27"
            Error: type mismatch between Int and [Char]
        3.  > (\v d -> v d) (\d -> d) 2
            = 2
        4.  > not ( True && (not True) )
            = not ( True && False )
            = not False
            = True
        5.  > - read "3"
            = -3
-}

-- Q2(b)
take' :: Int -> [a] -> [a]
take' 0 xs = []
take' n []
    | n > 0 = error "cannot take items from empty list"
    | n == 0 = []
    | otherwise = error "invalid number"
take' n (src @ (x : xs))
    | n < 0 = error "invalid number"
    | n > length src = error "cannot take more than length of list"
    | otherwise = x : (take' (n - 1) xs)

-- Q2(c)
divisor :: Int -> [Int]
divisor n
    | n <= 0 = error "number needs to be positive"
    | n == 1 = [1]
    | otherwise = [ x | x <- [1..n], n `mod` x == 0 ]

isPrime :: Int -> Bool
isPrime n
    | n <= 1 = False
    | otherwise = length (divisor n) == 2
