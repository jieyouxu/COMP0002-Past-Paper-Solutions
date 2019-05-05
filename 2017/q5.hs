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
-- Q5(d)
{-
    Given:
    power2 n
        | n == 0 = 1
        | otherwise = 2 * power2(n - 1)

    Given:
        precondition:   n >= 0
        postcondition:  power2 n = 2^n
        and always terminates

    By induction on `n`, given `n` in natural numbers, `n` >= 0
    Base case: P(0)
        power2 0 = 1 = 2^0, which trivially holds
    Induction hypothesis: P(k)
        power2 k = 2^k
    Step Case: P(k + 1)
        power2 (k + 1) = 2 * power2 k
                 = 2 * 2^(k)            (By I.H.)
                 = 2^(k+1)                      (Exponent law)
                 As required

    Since:
    P(0)             P(k) -> P(k + 1)
    ---------------------------------
             ∀ n ∈ ℕ: P(n)

-}
