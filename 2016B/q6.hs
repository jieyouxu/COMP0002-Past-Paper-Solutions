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

-- Q6(c)
sum' :: [Float] -> Float
sum' xs = foldr (+) 0.0 xs

getWeights :: Eq a => [(a, Float)] -> [Float]
getWeights pairs = map snd pairs

getValidWeights :: [Float] -> [Float]
getValidWeights weights = filter (<= 1) weights

dist :: Eq a => [(a, Float)] -> Bool
dist pairs = sum' validWeights == 1
    where
        validWeights = (getValidWeights . getWeights) pairs

-- Q6(d)
allZeros :: Eq a => [(a, Float)] -> Bool
allZeros pairs = foldr (\(a, w) areZeros -> (w == 0) && areZeros) True pairs

scaleWeight :: Eq a => Float -> (a, Float) -> (a, Float)
scaleWeight total (a, w) = (a, w / total)

normalise :: Eq a => [(a, Float)] -> [(a, Float)]
normalise [] = []
normalise pairs
    | dist pairs = pairs
    | allZeros pairs = error "all weights are zero"
    | otherwise = map scaler pairs
    where 
        total = (sum' . getValidWeights . getWeights) pairs
        scaler = scaleWeight total

-- Q6(e)
distribution :: Eq a => [(a, Float)] -> [(a, Float)]
distribution pairs = (normalise . coalesce) pairs
