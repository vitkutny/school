(define average
  (lambda numbers
    (/ (apply + numbers) (length numbers))))

(average 1 2 3 10 20)

(define variance
  (lambda numbers
    numbers)) ;TODO
(variance 1 3 1 3)