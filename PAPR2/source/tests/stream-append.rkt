(include "../functions/stream-append.rkt")

(define l1 '(1 2 3 4))
(define l2 '(5 6 7))
(define s1 (stream 1 2 3 4))
(define s2 (stream 5 6 7))

(andmap (lambda (result) (equal? result (list)))
        (list (stream->list (stream-append))
              (stream->list (stream-append (stream)))
              (stream->list (stream-append (stream) (stream)))))
(equal? (stream->list (stream-append s1)) l1)
(equal? (stream->list (stream-append s1 s2)) (append l1 l2))