(include "../functions/for-let.rkt")

(define result (list))

(for-let ((i 1)) ((<= i 10)) ((+ i 1))
         (cond ((even? i) (continue))
               ((= i 5) (continue-to 11)))
         (for-let ((j 1)) ((<= j 10)) ((+ j 1))
                  (cond ((= j 4) (break)))
                  (set! result (cons (* i j) result))))

(equal? result '(9 6 3 3 2 1))