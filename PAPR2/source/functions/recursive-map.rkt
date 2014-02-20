(define recursive-map
  (lambda (function list)
    (if (null? list)
        list
        (cons (if (pair? (car list))
                  (recursive-map function (car list))
                  (function (car list)))
              (recursive-map function (cdr list))))))