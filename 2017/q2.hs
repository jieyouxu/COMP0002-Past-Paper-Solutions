{-
    COMP0002 2017 Q2

    Given `foldr`, `map`, `filter` without definition.
-}
{-
    Q2(a)
    1.  > 5 * 10 - 49
        = 50 - 49
        = 1
    2.  > "speedy" = "speed"
        Error: assignment (=) operator used for comparison
    3.  > succ 9 * 10
        = succ 90
        = 91
    4.  > div 37 21
        = 1
    5.  > 12 + "13"
        Error: type mismatch
            Expected Int for second argument of (+), but got [Char] instead
-}
-- Q2(b)
fac :: Int -> Int
fac 0 = 1
fac n = n * fac (n - 1)

sumFac :: Int -> Int
sumFac 0 = 1
sumFac n = fac n + sumFac (n - 1)

-- Q2(c)
cubes :: [Int]
cubes = [x | x <- [1 .. 10], 200 <= x ^ 3 && x ^ 3 <= 1000]

cubes2 :: [Int]
cubes2 = filter (>= 200) $ takeWhile (<= 1000) cubed
  where
    cubed = [x ^ 3 | x <- [1 ..]]
