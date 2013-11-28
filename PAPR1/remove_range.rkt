(define remove-range
  (lambda (list from to)
    (build-list (- (length list) (+ (- to from) 1))
                (lambda (x)
                  (if (>= x from) 
                      (list-ref list (+ x (- to from) 1)) (list-ref list x))))))
(remove-range '(10 20 30 40 50) 1 2)