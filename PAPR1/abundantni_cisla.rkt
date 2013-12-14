(define divisors-sum
  (lambda (x)
    (let iter ((i x))
      (if (> i 0)
          (if (= (modulo x i) 0)
              (+ i (iter (- i 1)))
              (iter (- i 1)))
          i))))

(define abundant?
  (lambda (x)
    (< (* x 2) (divisors-sum x))))

(define abundant-list
  (lambda (max)
    (filter abundant? (build-list (+ max 1) (lambda (x) x)))))

(abundant-list 75)