{-
    COMP0002 2017 Q6

    Given `map`, `filter`, `foldr`
-}
{-
    Q6(a)

    lazy evaluation:
        Only compute result of expression until absolutely nececessary.
    tail recursive function:
        When the function calls itself at its logical end(s).
    polymorphic types:
        When a function can work on multiple types via type parameters.
    lambda abstraction:
        Anonymous functions, function expressions without a name.
-}
-- Q6(b)
prop_emptyList :: [a] -> Int -> Bool
prop_emptyList [] = length [] == 0

prop_concatList :: [a] -> [a] -> Int -> Bool
prop_concatList xs ys = length (xs ++ ys) == length xs + length ys

main :: IO ()
main = do
  quickCheck prop_emptyList
  quickCheck prop_concatList
