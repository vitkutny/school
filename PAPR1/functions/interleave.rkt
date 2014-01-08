(define interleave
  (lambda (s1 s2)
    (if (null? s1)
        (if (null? s2)
            '()
            (interleave s2 s1))
        (cons (car s1) (interleave s2 (cdr s1))))))