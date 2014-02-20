(include "fibonacci.rkt")

(define fibonacci-list
  (lambda (max)
    (build-list max fibonacci)))