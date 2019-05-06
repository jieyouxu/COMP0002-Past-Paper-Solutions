{-
    COMP0002 2016B Q2
-}

{-
    Q2(a)

    1.  > 1.0 / 3 + (-1)
        = 0.33333 - 1
        = -0.6666
    2.  > "Abe" < "Abbey"
        = False
    3.  > 12 /= 12.00000000001
        True
    4.  > 7 * -4
        Error: infix operator (*) and (-)
    5.  > 'a' < "apple"
        Error: type mismatch between Char and [Char]
-}

{-
    Q2(b)
    Given

    1. maximum' :: Ord a => [a] -> [a]
    2. maximum' [] = error 'maximum of empty list'
    3. maximum' [x] = [x]
    4. maximum' (y:xs)
    5.     | x < maxTail = x
    6.     | else = maxTail
    7.     | where maxTail = maximum (x:xs)

    1. Should be
        maximum' :: Ord a => [a] -> a
        Since it is supposed to find one maximum element
    2. Should be
        maximum' [] = error "maximum of empty list"
        As the error message is [Char] not Char
    3. Should be
        maximum' [x] = x
        Since maximum' finds an element
    4. Should be
        maximum' (x:xs)
        Since definition refers to `x`, the head of the input list
    6. Should be
        | otherwise = maxTail
        Since pattern matching uses `otherwise` for catch
    7. Should be
        where maxTail = maximum' xs
        Firstly, where is not part of the pattern guard definition
        Secondly, should be maximum' not maximum
        Thirdly, shpuld be maximum' xs, which is the tail of the input list
-}

-- Q2(c)
intersect :: Int -> Int
intersect n = (n * (n - 1)) `div` 2

-- Q2(d)
reverse' :: [a] -> [a]
reverse' [] = []
reverse' (x:xs) = (reverse' xs) ++ [x]

allReverse :: [[a]] -> [[a]]
allReverse [[]] = [[]]
allReverse xss = reverse' (map reverse' xss)
