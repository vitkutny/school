(define a (random 20))
(define b (random 20))
(define c (random 20))

(define triangle_check
  (lambda (a b c)
    (if (and (> (+ a b) c) (> (+ a c) b) (> (+ b c) a))
        (display "lze")
        (display "nelze"))))

(define triangle
  (lambda (a b c)
    (display "Trojúhelník o stranách ")
    (display a)(display ",")(display b)(display " a ")(display c)
    (display " ")
    (triangle_check a b c)
    (display " sestrojit")))

(triangle a b c)