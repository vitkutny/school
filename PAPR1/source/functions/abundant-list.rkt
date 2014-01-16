(include "abundant.rkt")

(define abundant-list
  (lambda (max)
    (filter abundant? (build-list (+ max 1) (lambda (x) x)))))