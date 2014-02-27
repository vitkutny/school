(include "../functions/ackermann.rkt")

(equal? (ackermann 3 3) 61)
(equal? (ackermann 2 3) 9)
(equal? (ackermann 3 2) 29)