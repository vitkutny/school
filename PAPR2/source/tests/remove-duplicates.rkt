(include "../functions/remove-duplicates.rkt")

(equal? (remove-duplicates '()) '())
(equal? (remove-duplicates '(a b c d)) '(a b c d))
(equal? (remove-duplicates '(a a c d d b)) '(a c d b))