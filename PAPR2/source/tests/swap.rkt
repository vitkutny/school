(include "../functions/swap.rkt")

(define a 1)
(define b 2)
(swap a b)
(equal? a 2)
(equal? b 1)