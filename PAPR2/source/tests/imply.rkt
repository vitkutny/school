(include "../macros/imply.rkt")

(equal? (imply #t 'true (print 'false)) 'true)
(equal? (imply #f (print 'true) 'false) 'false)
(equal? (imply (< (* 3 2) 1) (print 'here) 2) 2)
(equal? (imply (* 3 2) $result xD) 6)

(define a 5)
(equal? (imply (equal? 2 (set! a (+ a 15))) $result $result) #f)
(equal? a 20)