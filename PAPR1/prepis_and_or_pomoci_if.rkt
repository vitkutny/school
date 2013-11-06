(define a (random 10))
(define b (random 10))
(define c #f)

(or (< a b) (and (= a 3) (> 5 b)) (or (or) c))

(if (< a b)
    #t
    (if (= a 3)
        (if (> 5 b) #t #f)
        (if c #t #f)
    )
)