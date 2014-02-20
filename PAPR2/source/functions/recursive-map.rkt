(define recursive-map
  (lambda (function list)
    (if (null? list)
        list
        (if (pair? list)
            (cons
             (recursive-map function (car list))
             (recursive-map function (cdr list)))
            (function list)))))