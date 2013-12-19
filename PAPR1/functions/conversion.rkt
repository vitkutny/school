(define conversion
  (lambda (base list)
    (let iter ((i (- (length list) 1)) (list list))
      (if (null? list)
          0
          (+ (* (car list) (expt base i)) (iter (- i 1) (cdr list)))))))