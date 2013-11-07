(define x 6)
(define vyska 10)
(define strana 5)

(define trojuhelnik_obsah
  (lambda (a vyska_a)
    (/ (* a vyska_a) 2)))

(define obdelnik_obsah
  (lambda (a b)
    (* a b)))

(define hranol_objem
  (lambda (strana vyska x)
     (* (trojuhelnik_obsah strana strana) x vyska)))

(define hranol_povrch
  (lambda (strana vyska x)
    (+ (* (trojuhelnik_obsah strana strana) x 2) (* (obdelnik_obsah strana vyska) x))))

(display "Pravidelný ")(display x)(display "-boký hranol")(newline)
(display "Výška hranolu: ")(display vyska)(newline)
(display "Strana hranolu: ")(display strana)(newline)
(newline)
(display "Objem: ")(display (hranol_objem strana vyska x))(newline)
(display "Povrch: ")(display (hranol_povrch strana vyska x))(newline)