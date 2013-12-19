(define divisors-sum
  (lambda (x)
    (let iter ((i x))
      (if (> i 0)
          (if (= (modulo x i) 0)
              (+ i (iter (- i 1)))
              (iter (- i 1)))
          i))))