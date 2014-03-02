(define (make-rand seed)
  (let ((next seed))
    
    (define (generate)
      (set! next (+ (* next 1103515245) 12345))
      (modulo (numerator (/ next 65536)) 32768))
    
    (define (seed seed)
      (set! next seed))
    
    (lambda (signal . args)
      (cond ((equal? signal 'generate) (generate))
            ((equal? signal 'seed) (seed (car args)))
            (else (error "unkown signal"))))))