(include "../functions/recursive-map.rkt")

(recursive-map (lambda (x) (* 10 x)) '())
(recursive-map (lambda (x) (* 10 x)) '(1 2 3 4))
(recursive-map (lambda (x) (* 10 x)) '(1 2 (3 4 (5 6) 7) 8))
(recursive-map (lambda (x) (* 10 x)) (cons 1 (cons (list 2 3 4) 5)))