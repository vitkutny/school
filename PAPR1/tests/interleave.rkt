(include "../functions/interleave.rkt")

(interleave '(1 2) '(a))
(interleave '(1 2) '(a b))
(interleave '(1 2) '(a b c))
(interleave '(1 2) '())
(interleave '() '(a b c))