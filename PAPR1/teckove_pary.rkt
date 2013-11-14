(define par (cons (cons 1 2)
                  (cons 3 4)))

(display "Teckovy par: ")(display par)(newline)
(display "Prvni prvek: ")(display (car par))(newline)
(display "Druhy prvek: ")(display (cdr par))(newline)
(display "Prvni prvek z druheho paru: ")(display (cadr par))(newline)
(display "Druhy prvek z prvniho paru: ")(display (cdar par))(newline)