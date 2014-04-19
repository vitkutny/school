(define-macro slambda
  (lambda (args . body)
    (quasiquote
     (let ((self (quote (slambda ,args ,@body))))
       (lambda ,args ,@body)))))