(define occurences
  (lambda (search source)
    (if (null? search)
        search
        (cons (let iter ((source source) (count 0))
                (if (null? source)
                    count
                    (if (equal? (car search) (car source))
                        (iter (cdr source) (+ count 1))
                        (iter (cdr source) count))))
              (occurences (cdr search) source)))))