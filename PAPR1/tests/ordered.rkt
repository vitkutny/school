(include "../functions/ordered.rkt")

(ordered? < 1 2 3 4)
(ordered? > 1 2 3 4)
(ordered? <)
(ordered? = 3 3 3 3 3)
(ordered? = 4)
(ordered? = 4 4 4 4 3)