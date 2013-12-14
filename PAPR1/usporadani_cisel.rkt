(define usporadana?
  (lambda (proc . values)
    (or (null? values)
        (null? (cdr values))
        (and (proc (car values) (car (cdr values)))
             (apply usporadana? proc (cdr values))))))

(usporadana? < 1 2 3 4)
(usporadana? > 1 2 3 4)
(usporadana? <)
(usporadana? = 3 3 3 3 3)
(usporadana? = 4)
(usporadana? = 4 4 4 4 3)