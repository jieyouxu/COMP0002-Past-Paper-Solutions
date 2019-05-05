{-
    COMP0002 2017 Q5

    Given `foldr`, `map`, `filter`
-}
{-
    Q5(a)

    higher order function:
        A function which takes another function as parameter.
    operator section:
        Partial application of a function, e.g.:
            Left section: (3 <=) <=> \x -> 3 <= x
            Right section: (/ 2) <=> \x -> x / 2
    type class:
        A protocol which defines what operations its instance can perform.
    Quick Check:
        A property-testing library
-}
-- Q5(b)
isPrimeHelper :: Int -> Int -> Bool
isPrimeHelper n 2 = n `mod` 2 /= 0
isPrimeHelper n d
  | n `mod` d == 0 = False
  | otherwise = isPrimeHelper n (d - 1)

isPrime :: Int -> Bool
isPrime 1 = True
isPrime 2 = True
isPrime n = isPrimeHelper n (n - 1)

-- Q5(c)
iter' :: Int -> (a -> a) -> a -> a
iter' 0 f x = x
iter' n f x = iter' (n - 1) f (f x)

square :: Int -> Int
square n = n ^ 2

quarProd :: [Int] -> Int
quarProd [] = 0
quarProd xs = foldr1 (*) [iter' 2 square x | x <- xs]
