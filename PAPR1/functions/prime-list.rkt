(include "prime.rkt")

(define prime-list
  (lambda (max)
    (filter prime? (build-list max (lambda (x) (+ x 1))))))