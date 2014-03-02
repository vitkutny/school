(define (recursive-map function list)
  (if (null? list)
      list
      (if (pair? list)
          (cons
           (recursive-map function (car list))
           (recursive-map function (cdr list)))
          (function list))))