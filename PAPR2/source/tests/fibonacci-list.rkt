(include "../functions/fibonacci-list.rkt")

(equal? (fibonacci-list 0) '())
(equal? (fibonacci-list 10) '(0 1 1 2 3 5 8 13 21 34))