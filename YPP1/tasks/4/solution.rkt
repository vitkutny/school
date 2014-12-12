;1 a

;1 b
(define (euclid u w)
  (let iter ((u u) (w w))
    (if (= w 0)
        u
        (iter w (modulo u w)))))

(equal? (euclid 9 24) 3)
(equal? (euclid 17 25) 1)
;2
(define (remove-duplicates list)
  (foldr (lambda (x y)
           (cons x (filter (lambda (z) (not (equal? x z))) y)))
         empty list))

(define (list-count-item list item)
  (let iter ((list list) (count 0))
    (if (null? list)
        count
        (iter (cdr list) (if (equal? item (car list)) (+ count 1) count)))))

(define (list-count list)
  (remove-duplicates (foldr (lambda (item rest)
                              (cons (cons item (list-count-item list item)) rest))
                            empty list)))

(equal? (list-count '(3 1 3 2 1 2 3 3 3)) '((3 . 5) (1 . 2) (2 . 2)))
(equal? (list-count '(d b a c b b a)) '((d . 1) (b . 3) (a . 2) (c . 1)))

;3
(define (histogram pixels)
  (list-count (foldr append empty pixels)))
(equal? (histogram '((0 100 80) (255 0 255) (0 100 255) (0 0 0))) '((0 . 6) (100 . 2) (80 . 1) (255 . 3)))

;4
(define (map-index-pred condition operation list)
  (cons
   (if (condition (car list)) (operation (car list)) (car list))
   (if (empty? (cdr list))
       '()
       (map-index-pred condition operation (cdr list)))))

(equal? (map-index-pred odd? sqr '(2 3 4 5)) '(2 9 4 25))
(equal? (map-index-pred (lambda(i) (<= i 2)) - '(1 2 3 4 5)) '(-1 -2 3 4 5))

;5
(define (divided-by-three? list)
  (let ((q0 0) (q1 1) (q2 2))
    (let iter ((list list) (state q0))
      (if (empty? list)
          (= state q0)
          (iter (cdr list) (cond ((= state q0) (if (= (car list) 1) q1 (if (= (car list) 2) q2 q0)))
                                 ((= state q1) (if (= (car list) 1) q2 (if (= (car list) 2) q0 q1)))
                                 ((= state q2) (if (= (car list) 1) q0 (if (= (car list) 2) q1 q2)))))))))

(equal? (divided-by-three? '(2 0 2 1 1)) #t)
(equal? (divided-by-three? '(0 1 2 2 2 2 1)) #f)