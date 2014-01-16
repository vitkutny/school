(define sequence
  (lambda (from to proc)
    (let ((proc (lambda (x) (proc (+ x from)))))
      (build-list (+ (- to from) 1) proc))))