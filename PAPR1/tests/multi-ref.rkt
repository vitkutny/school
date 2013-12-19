(include "../functions/multi-ref.rkt")

(define test-list '((1 2 3 4 5 6) (10 20 30) (a b c d e f g)))

(multi-ref test-list 0)
(multi-ref test-list 3)
(multi-ref test-list 4)
(multi-ref test-list 10)
(multi-ref '() 0)