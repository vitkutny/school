(define list-pref
  (lambda (list max)
    (if (> max 0)
        (cons (car list) (list-pref (cdr list) (- max 1)))
        ())))