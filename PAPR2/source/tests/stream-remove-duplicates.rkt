(include "../functions/stream-remove-duplicates.rkt")

(equal? (stream->list (stream-remove-duplicates (stream))) (list))
(equal? (stream->list (stream-remove-duplicates (stream 1 2 2 3 4 5 1 6 5 7 2))) (list 1 2 3 4 5 6 7))