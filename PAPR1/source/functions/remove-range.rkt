(define remove-range
  (lambda (list from to)
    (define diff (+ (abs (- to from)) 1))
    (build-list (- (length list) diff)
                (lambda (x)
                  (if (>= x (min from to)) 
                      (list-ref list (+ x diff)) (list-ref list x))))))