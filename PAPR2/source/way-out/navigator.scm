(define (remove-duplicates list)
  (let ((used '()))
    (let iter ((list list))
      (if (null? list)
          list
          (if (member (car list) used)
              (iter (cdr list))
              (begin (set! used (cons (car list) used))
                     (cons (car list) (iter (cdr list)))))))))

(define navigator
  (let* ((visited (list (cons 0 0)))
         (excluded (list))
         (base-directions '(up right down left))
         (directions base-directions)
         (current-directions (list)))
    
    (define (current-coords)
      (car visited))
    
    (define (last-coords)
      (and (not (null? (cdr visited))) (cadr visited)))
    
    (define (coords-for direction)
      (cons (+ (car (current-coords)) (cond ((equal? direction 'right) 1) ((equal? direction 'left) -1) (else 0)))
            (+ (cdr (current-coords)) (cond ((equal? direction 'down) 1) ((equal? direction 'up) -1) (else 0)))))
    
    (define (direction-for coords)
      (and (pair? coords)
           (cond ((< (car (current-coords)) (car coords)) 'right)
                 ((> (car (current-coords)) (car coords)) 'left)
                 ((< (cdr (current-coords)) (cdr coords)) 'down)
                 ((> (cdr (current-coords)) (cdr coords)) 'up)
                 (else #f))))
    
    (define (visited? direction)
      (member (coords-for direction) visited))
    
    (define (excluded? direction)
      (member (coords-for direction) excluded))
    
    (define (go-back)
      (let ((back-direction (direction-for (last-coords))))
        (set! excluded (cons (current-coords) excluded))
        (set! visited (cdr visited))
        back-direction))
    
    (define (go-to direction)
      (set! visited (cons (coords-for direction) visited))
      direction)
    
    (define (can-go-to? direction)
      (and (member direction current-directions) (not (excluded? direction)) (not (visited? direction))))
    
    (define (direction-sort directions)
      (let iter ((base-directions base-directions))
        (if (null? base-directions)
            base-directions
            (let ((direction (car base-directions)))
              (if (member direction directions)
                  (cons direction (iter (cdr base-directions)))
                  (iter (cdr base-directions)))))))
    
    (define (select-direction)
      (let ((directions (filter can-go-to? directions)))
        (if (null? directions)
            (go-back)
            (go-to (car directions)))))
    
    (lambda (free-directions treasure-directions)
      (set! current-directions free-directions)
      (set! directions (remove-duplicates (append (direction-sort treasure-directions) directions)))
      (select-direction))))