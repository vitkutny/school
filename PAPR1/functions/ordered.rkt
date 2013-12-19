(define ordered?
  (lambda (proc . values)
    (or (null? values)
        (null? (cdr values))
        (and (proc (car values) (car (cdr values)))
             (apply ordered? proc (cdr values))))))