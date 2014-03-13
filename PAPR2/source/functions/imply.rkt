(define-macro (imply cond first second)
  (quasiquote
   (let (($result (unquote cond)))
     (if $result
         (unquote first)
         (begin (unquote first)
                (unquote second))))))