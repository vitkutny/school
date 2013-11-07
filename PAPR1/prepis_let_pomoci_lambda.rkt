(display "LET")(newline)

(let ((x 1) (y 2))
  (+ x y))

(display "LET pomoci λ")(newline)
((lambda (x y)
   (+ x y))
 1 2)

(display "LET*")(newline)
(let* ((x 1) (y 2) (z 3))
  (+ x y z))

(display "LET* pomoci LET")(newline)
(let ((x 1))
  (let ((y 2))
    (let ((z 3))
      (+ x y z))))

(display "LET* pomocí λ")(newline)
((lambda (x)
   ((lambda (y)
      ((lambda (z)
         (+ x y z))
       3))
    2))
 1)