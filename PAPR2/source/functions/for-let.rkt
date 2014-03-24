(define-macro (for-let before conditions after . body)
  (quasiquote
   (begin
     (let continue-to ,before
       (define (break) #f)
       (define (continue)
         (continue-to ,@after)
         (break))
       (and ,@conditions ,@body (continue)))
     (void))))