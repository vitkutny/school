(define average
  (lambda numbers
    (/ (apply + numbers) (length numbers))))