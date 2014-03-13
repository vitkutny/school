(define (make-binary-tree)
  
  (define (make-node value . type)
    (mcons (and value (mcons value (mcons (make-node #f 'left) (make-node #f 'right)))) (or (null? type) (car type))))
  
  (define (node-value node)
    (mcar (mcar node)))
  
  (define (node-children node)
    (mcdr (mcar node)))
  
  (define (node-left node)
    (mcar (node-children node)))
  
  (define (node-right node)
    (mcdr (node-children node)))
  
  (let ((root (make-node #f 'root)))
    
    (define (find value)
      (let iter ((node root))
        (and (mcar node)
             (cond ((< value (node-value node)) (iter (node-left node)))
                   ((> value (node-value node)) (iter (node-right node)))
                   ((= value (node-value node)) node)))))
    
    (define (find-min . from)
      (let iter ((node (if (null? from) root (car from))))
        (if (mcar (node-left node))
            (iter (node-left node))
            node)))
    
    (define (find-max . from)
      (let iter ((node (if (null? from) root (car from))))
        (if (mcar (node-right node))
            (iter (node-right node))
            node)))
    
    (define (insert value)
      (let iter ((node root))
        (cond ((not (mcar node)) (set-mcar! node (mcar (make-node value))))
              ((< value (node-value node)) (iter (node-left node)))
              ((> value (node-value node)) (iter (node-right node))))))
    
    (define (delete value)
      (let ((node (find value)))
        (and node (mcar node)
             (cond ((and (mcar (node-left node)) (mcar (node-right node)))
                    (let ((max-node (find-max (node-left node))))
                      (set-mcar! (mcar node) (node-value max-node))
                      (set-mcar! max-node (mcar (node-left max-node)))))
                   ((or (mcar (node-left node)) (mcar (node-right node)))
                    (set-mcar! node (or (mcar (node-left node)) (mcar (node-right node)))))
                   (else (set-mcar! node #f))))))
    
    (define (height)
      (let iter ((node root))
        (if (mcar node) (+ 1 (max (iter (node-left node)) (iter (node-right node)))) 0)))
    
    (define (binary-tree)
      (let iter ((node root))
        (if (mcar node)
            (append (iter (node-left node))
                    (list (node-value node))
                    (iter (node-right node)))
            (list))))
    
    (lambda args
      (if (null? args)
          (binary-tree)
          (let ((signal (car args)) (args (cdr args)))
            (cond ((equal? signal 'find) (if (list? (car args)) (map find (car args)) (find (car args))))
                  ((equal? signal 'find-min) (find-min))
                  ((equal? signal 'find-max) (find-max))
                  ((equal? signal 'insert) (if (list? (car args)) (for-each insert (car args)) (insert (car args))))
                  ((equal? signal 'delete) (if (list? (car args)) (for-each delete (car args)) (delete (car args))))
                  ((equal? signal 'height) (height))
                  (else (error "unkown signal"))))))))