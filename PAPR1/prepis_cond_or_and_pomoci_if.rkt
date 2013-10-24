(define a 15)
(define b 10)

(cond ((or (<= a 10) (odd? b)) -5)
      ((and (> b (+ a 2)) (even? a) (odd? b)) 10)
      ((or) 25)
      (else -25))

(if
 (if (<= a 10)
    (<= a 10)
    (if (odd? b)
        (odd? b)
        #f
    )
 )
 -5
 (if
  (if (> b (+ a 2))
      (if (even? a)
          (if (odd? b)
              (odd? b)
              #f
          )
          #f
      )
      #f
  )
  10
  (if #f
      25
      -25
  )
 )
)