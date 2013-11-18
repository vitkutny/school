(require srfi/25)

(define lbm-height 30)
(define lbm-width 30)

(define bnot
  (lambda (b)
    (- 1 b)))

(define band
  (lambda (b1 b2)
    (if (= b1 b2 1) 1 0)))

(define bor
  (lambda (b1 b2)
    (if (= b1 b2 0) 0 1)))

(define lbm-bitmap-bits
  (lambda (lbm)
    (do ((result (make-array (shape 0 lbm-width 0 lbm-height)))
         (y 0 (+ y 1)))
      ((= y lbm-width) result)
      (do ((x 0 (+ x 1)))
        ((= x lbm-height))
        (array-set! result x y (lbm x y))))))

(define black-lbm
  (lambda ()
    (lambda (x y) 0)))

(define white-lbm
  (lambda ()
    (lambda (x y) 1)))

(define square-lbm
  (lambda (relative-size)
    (let ((border-relative-size (/ (- 1 relative-size) 2)))
      (lambda (x y)
        (if (and (<= (* lbm-width border-relative-size) x)
                 (< x (* lbm-width (- 1 border-relative-size)))
                 (<= (* lbm-height border-relative-size) y)
                 (< y (* lbm-height (- 1 border-relative-size))))
            1
            0)))))

(define lbm-array->bitmap 
  (lambda (arr)
    (lambda (x y)
      (array-ref arr x y))))

(define lbm-not
  (lambda (lbm)
    (lambda (x y)
      (bnot (lbm x y)))))

(define lbm-and-2
  (lambda (lbm1 lbm2)
    (lambda (x y)
      (band (lbm1 x y) (lbm2 x y)))))

(define lbm-and
  (lambda (lbm1 . more-lbms)
    (foldl lbm-and-2 lbm1 more-lbms)))

(define lbm-or-2
  (lambda (lbm1 lbm2)
    (lambda (x y)
      (bor (lbm1 x y) (lbm2 x y)))))

(define lbm-or
  (lambda (lbm1 . more-lbms)
    (foldl lbm-or-2 lbm1 more-lbms)))

(define lbm-diff
  (lambda (lbm1 lbm2)
    (lbm-and lbm1 (lbm-not lbm2))))

(define lbm-shift 
  (lambda (lbm dx dy)
    (lambda (x y)
      (let ((old-x (- x dx))
            (old-y (- y dy)))
        (if (and (< -1 old-x lbm-width)
                 (< -1 old-y lbm-height))
            (lbm old-x old-y)
            1)))))

(define lbm-top-edge 
  (lambda (lbm)
    (lbm-diff lbm (lbm-shift lbm 0 5))))

(define lbm-edges 
  (lambda (lbm)
    (lbm-or (lbm-diff lbm (lbm-shift lbm 0 5))
            (lbm-diff lbm (lbm-shift lbm 0 -5))
            (lbm-diff lbm (lbm-shift lbm 5 0))
            (lbm-diff lbm (lbm-shift lbm -5 0)))))
  
(define lbm-display-bitmap
  (lambda (lbm)
    (let ((bm (lbm-bitmap-bits lbm)))
      (do ((y 0 (+ y 1)))
        ((= y lbm-width))
        (do ((x 0 (+ x 1)))
          ((= x lbm-height))
          (display (array-ref bm x y)))
        (newline)))))

(lbm-display-bitmap (square-lbm 2/3))
(lbm-display-bitmap (lbm-edges (square-lbm 2/3)))