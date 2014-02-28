(define make-queue
  (lambda ()
    (let ((queue '()))
      
      (define is-empty?
        (lambda ()
          (null? queue)))
      
      (define push
        (lambda (value)
          (set! queue (append queue (list value)))))
      
      (define pop
        (lambda ()
          (let ((value (car queue)))
            (set! queue (cdr queue))
            value)))
      
      (lambda (signal . args)
        (cond ((equal? signal 'empty?) (is-empty?)) 
              ((equal? signal 'push) (push (car args)))
              ((equal? signal 'pop) (if (is-empty?) 'NULL (pop)))
              (else (error "unkown signal")))))))