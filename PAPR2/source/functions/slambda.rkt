(define-macro (slambda args . body)
  (quasiquote
   (let ((self (quote (slambda ,args ,@body))))
     (lambda ,args ,@body))))