{-
    COMP0002 2016B Q6
-}

{-
    Q6(a)

    recursive variant:
        Some data that changes with each recursive call
    lambda abstraction:
        Anonymous function (without a name)
    partial application:
        A new function created from the original function with some of its 
        parameters filled in via currying.
    type class:
        An interface which defines some operations available
-}

-- Q6(b)
mergeEqualFirst :: Eq a => (a, Float) -> [(a, Float)] -> [(a, Float)]
mergeEqualFirst (a, w) [] = [(a, w)]
mergeEqualFirst (a, w) ((b, x) : pairs)
    | a == b = (a, (w + x)) : pairs
    | otherwise = (b, x) : (mergeEqualFirst (a, w) pairs)

coalesce :: Eq a => [(a, Float)] -> [(a, Float)]
coalesce [] = []
coalesce pairs = foldr mergeEqualFirst [] pairs

