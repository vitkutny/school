(include "../functions/atleast.rkt")

(atleast? 'a 0 '(a b c a d))
(atleast? 'a 1 '(a b c a d))
(atleast? 'a 2 '(a b c a d))
(atleast? 'a 3 '(a b c a d))