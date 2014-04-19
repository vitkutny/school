(include "../functions/slambda.rkt")

(equal? ((slambda () 10)) 10)
(equal? ((slambda (x) (+ x 1)) 10) 11)
(equal? ((slambda () self)) '(slambda () self))
(equal? ((slambda (x) (list (+ x 1) self))10) '(11 (slambda (x) (list (+ x 1) self))))
(equal? ((slambda () (slambda () self) self)) '(slambda () (slambda () self) self))