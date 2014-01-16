(include "../functions/multi-merge.rkt")

(multi-merge '(1 2 3 4 5 6))
(multi-merge '(1 2 3) '(a b c))
(multi-merge '(1 2 3) '(10 20 30) '(a b c))
(multi-merge '(1 2 3 4 5 6) '(10 20 30) '(a b c d e f g))
(multi-merge)