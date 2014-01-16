(define mlist
  (lambda (list)
    (if (null? list) '()
        (cons (apply * list) (cdr list)))))