(define position-if
  (lambda (proc list)
    (let iter ((i 0))
      (and (< i (length list))
           (if (proc (list-ref list i))
               i
               (iter (+ i 1)))))))