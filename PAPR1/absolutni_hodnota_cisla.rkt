(define absolutni_hodnota
  (lambda (x)
    (display "Absolutní hodnota čísla ")(display x)(display " je: ")
    (if (< x 0) (display (* x -1)) (display x))))

(absolutni_hodnota 2)
(newline)
(absolutni_hodnota -20)