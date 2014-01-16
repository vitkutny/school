(define find-values
  (lambda (symbol list)
    (if (null? list)
        list
        (if (equal? (car list) symbol)
            (cons (cadr list) (find-values symbol (cddr list)))
            (find-values symbol (cddr list))))))