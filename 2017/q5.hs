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
