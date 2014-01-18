(define each-nth
  (lambda (list nth)
    (if (> nth (length list))
        ()
        (cons (list-ref list (- nth 1))
              (each-nth (list-tail list nth) nth)))))