(include "../functions/make-rand.rkt")

(define rand (make-rand 0))
(equal? (rand 'generate) 0)
(equal? (rand 'generate) 21468)
(equal? (rand 'generate) 9988)
(rand 'seed 12)
(equal? (rand 'generate) 5451)