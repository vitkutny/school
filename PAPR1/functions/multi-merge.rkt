(include "multi-ref.rkt")

(define multi-merge
  (lambda lists
    (let iter ((i 0))
      (let ((list (multi-ref lists i)))
        (if (null? list)
            list
            (append list (iter (+ i 1))))))))