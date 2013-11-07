; ekvivalentní s for(i=10;i>=0;i--){ printf("%i\n",i); }
(define rercursive-function
  (lambda (i) (display i) (newline) (if (> i 0) (rercursive-function (- i 1)))))

(rercursive-function 10)