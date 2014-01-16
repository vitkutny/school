(define atleast?
  (lambda (symbol count list)
    (let iter ((i count) (list list))
      (or (= i 0) 
          (and (not (null? list))
               (if (equal? symbol (car list))
                   (iter (- i 1) (cdr list))
                   (iter i (cdr list))))))))