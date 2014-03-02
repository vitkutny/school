(define (fibonacci value)
  (if (< value 2)
      value
      (+ (fibonacci (- value 1)) (fibonacci (- value 2)))))