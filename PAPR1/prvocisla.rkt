(define prime?
  (lambda (x)
    (let iter ((i 2))
      (or (= i x)
          (and (> (modulo x i) 0)
               (iter (+ i 1)))))))

(define primes
  (lambda (max)
    (filter prime? (build-list (- max 1) (lambda (x) (+ x 2))))))

(primes 50)