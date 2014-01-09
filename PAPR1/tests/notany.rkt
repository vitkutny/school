(include "../functions/notany.rkt")

(notany? even? '(1 2 3 4))
(notany? even? '(1 3))
(notany? even? '())