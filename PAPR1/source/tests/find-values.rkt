(include "../functions/find-values.rkt")

(find-values 'a '(c 1 b 4 a 2 d 2 b 3 a 0)) ;(2 0)
(find-values 'b '(c 1 b 4 a 2 d 2 b 3 a 0)) ;(4 3)
(find-values 'c '(c 1 b 4 a 2 d 2 b 3 a 0)) ;(1)
(find-values 'e '(c 1 b 4 a 2 d 2 b 3 a 0)) ;()