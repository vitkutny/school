(include "divisors-sum.rkt")

(define abundant?
  (lambda (x)
    (< (* x 2) (divisors-sum x))))