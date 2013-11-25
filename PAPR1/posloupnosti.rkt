(define posl
  (lambda (od do vzorec)
    (let ((vzorec (lambda (x) (vzorec (+ x od)))))
    (build-list (+ (- do od) 1) vzorec))))

(posl 9 10 (lambda (x) (* x x)))