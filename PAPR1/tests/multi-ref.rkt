(include "../functions/multi-ref.rkt")

(multi-ref 0 '(1 2 3 4 5 6) '(10 20 30) '(a b c d e f g))
(multi-ref 3 '(1 2 3 4 5 6) '(10 20 30) '(a b c d e f g))
(multi-ref 4 '(1 2 3 4 5 6) '(10 20 30) '(a b c d e f g))
(multi-ref 10 '(1 2 3 4 5 6) '(10 20 30) '(a b c d e f g))
(multi-ref 0)