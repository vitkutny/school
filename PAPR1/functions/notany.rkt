(define notany?
  (lambda (proc list)
    (or (null? list)
        (and (not (proc (car list)))
             (notany? proc (cdr list))))))

;iterative
;(define notany?
;  (lambda (proc list)
;    (let iter ((list list))
;      (or (null? list)
;          (and (not (proc (car list)))
;               (iter (cdr list)))))))