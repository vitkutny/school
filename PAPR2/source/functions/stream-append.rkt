(require racket/stream)

(define stream-append
  (lambda streams
    (or (and (or (null? streams) (stream-empty? (car streams))) (stream))
        (let ((first-stream (car streams)))
          (stream-cons (stream-first first-stream)
                       (apply stream-append (stream-rest first-stream) (cdr streams)))))))