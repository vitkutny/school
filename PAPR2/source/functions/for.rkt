(define-macro (for before condition after . body)
  (quasiquote
   (let ()
     ,before
     (define (continue) ,after #f)
     (define break
       (let ((state #f))
         (lambda args
           (cond ((null? args) (begin (set! state #t) #f))
                 (else state)))))
     (do () ((not (and (not (break #t)) ,condition)))
       (and ,@body (continue))))))