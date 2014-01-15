(define count-if
  (lambda (proc list)
    (let iter ((i 0) (count 0))
      (if (>= i (length list))
          count
          (iter (+ i 1) (if (proc (list-ref list i))
                            (+ count 1)
                            count))))))