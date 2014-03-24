(include "../functions/for.rkt")

(define i 'NULL)
(define j 'NULL)

(define result (list))

(for (set! i 1) (<= i 10) (set! i (+ i 1))
  (cond ((even? i) (continue))
        ((= i 5) (break)))
  (for (set! j 1) (<= j 10) (set! j (+ j 1))
    (cond ((= j 4) (break)))
    (set! result (cons (* i j) result))))

(equal? i 5)
(equal? j 4)
(equal? result '(9 6 3 3 2 1))