(define par (cons "prvni" "druhy"))
par
(car par) ;prvni prvek paru
(cdr par) ;druhy prvek paru

(define abc (cons (cons 1 2) (cons 3 4)))
abc
(cdar abc) ;druhy prvek z prvniho paru
(cadr abc) ;prvni prvek z druheho paru

(cons (cons 1 (cons 3 (cons 5 6)))
      (cons (cons 4 2) (cons 1 0)))