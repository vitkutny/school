(define find-value
  (lambda (value list)
    (if (null? list)
        (display "symbol not-found\n")
        (if (equal? value (car list))
            (cadr list)
            (find-value value (cddr list))))))