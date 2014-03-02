(define (make-queue)
  (let ((queue '()))
    
    (define (is-empty?)
      (null? queue))
    
    (define (push value)
      (set! queue (append queue (list value))))
    
    (define (pop)
      (let ((value (car queue)))
        (set! queue (cdr queue))
        value))
    
    (lambda (signal . args)
      (cond ((equal? signal 'empty?) (is-empty?)) 
            ((equal? signal 'push) (push (car args)))
            ((equal? signal 'pop) (if (is-empty?) 'NULL (pop)))
            (else (error "unkown signal"))))))