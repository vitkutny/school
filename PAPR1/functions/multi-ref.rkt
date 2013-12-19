(define multi-ref
  (lambda (lists value-index)
    (let iter-lists ((list-index 0))
      (if (< list-index (length lists))
          (if (>= value-index (length (list-ref lists list-index)))
              (iter-lists (+ list-index 1))
              (cons (list-ref (list-ref lists list-index) value-index)
                    (iter-lists (+ list-index 1))))
          '()))))