(define faktorial
  (lambda (x)
    (if (> x 1) (* x (faktorial (- x 1))) 1)))

(faktorial 5)