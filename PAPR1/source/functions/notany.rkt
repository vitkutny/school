(define notany?
  (lambda (proc list)
    (or (null? list)
        (and (not (proc (car list)))
             (notany? proc (cdr list))))))