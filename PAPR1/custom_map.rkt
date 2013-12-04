(define my-map
  (lambda (proc list)
    (build-list (length list) (lambda (x)
                                (- (list-ref list x))))))
(my-map - '(1 2 3 4 2 1 3))

(define map3
  (lambda (proc l1 l2 l3)
    (build-list (min (length l1) (length l2) (length l3))
                (lambda (x)
                  (proc (list-ref l1 x) (list-ref l2 x) (list-ref l3 x))))))
(map3 + '(1 2 3 4) '(5 2) '(2 3 3))


;(define multi-map
;  (lambda (proc . lists)
;    lists))

;(multi-map + '(1 2 3 4) '(5 2) '(2 3 3))