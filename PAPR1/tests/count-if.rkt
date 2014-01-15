(include "../functions/count-if.rkt")

(count-if symbol? '(1 a 2 b c))
(count-if symbol? '(1 a 2 b))
(count-if symbol? '(1 a 2))