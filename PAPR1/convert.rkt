(define convert
  (lambda (base list)
    (let iter ((i (- (length list) 1)) (list list))
      (if (null? list)
          0
          (+ (* (car list) (expt base i)) (iter (- i 1) (cdr list)))))))

(convert 2 '(1 0 1))
(convert 10 '(1 9 8 5))