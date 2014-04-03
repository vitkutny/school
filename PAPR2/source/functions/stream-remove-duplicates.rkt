(require racket/stream)

(define (stream-remove-duplicates stream)
  (let ((used (list)))
    (let iter ((stream stream))
      (if (stream-empty? stream)
          stream
          (if (member (stream-first stream) used)
              (iter (stream-rest stream))
              (begin (set! used (cons (stream-first stream) used))
                     (stream-cons (stream-first stream) (iter (stream-rest stream)))))))))