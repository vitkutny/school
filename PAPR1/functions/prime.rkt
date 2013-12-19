(define prime?
  (lambda (x)
    (let iter ((i 2))
      (or (= i x)
          (and (>= x 2) 
               (> (modulo x i) 0)
               (iter (+ i 1)))))))