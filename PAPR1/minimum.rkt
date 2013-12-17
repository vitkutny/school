(define minimum
  (lambda (min . list)
    (if (null? list)
        min
        (if (< (car list) min)
            (apply minimum (car list) (cdr list))
            (apply minimum min (cdr list))))))

(minimum 1 2 -10 20)