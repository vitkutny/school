(include "multi-ref.rkt")

(define multi-merge
  (lambda lists
    (let iter ((i 0))
      (let ((list (apply multi-ref i lists)))
        (if (null? list)
            list
            (append list (iter (+ i 1))))))))