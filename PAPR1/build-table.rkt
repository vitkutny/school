(define build-table
  (lambda (proc x y)
    (build-list x (lambda (x)
                    (build-list y (lambda (y)
                                    (proc x y)))))))

(build-table + 3 4)