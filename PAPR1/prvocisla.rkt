(define prime?
  (lambda (x)
    (let iter ((i 2))
      (if (= i x) #t
          (if (= (modulo x i) 0) #f
              (iter (+ i 1)))))))

(define primes
  (lambda (max)
    (filter prime? (build-list (- max 1) (lambda (x)
                     (+ x 2))))))

(primes 30)