(define (remove-duplicates list)
  (let ((used '()))
    (let iter ((list list))
      (if (null? list)
          list
          (if (member (car list) used)
              (iter (cdr list))
              (begin (set! used (cons (car list) used))
                     (cons (car list) (iter (cdr list)))))))))