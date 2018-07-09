:::::::::::::::::::::::
:  First Order Logic  :
:::::::::::::::::::::::


: the logical identity operator

(x) := table(
 1 1
 0 0
)

: the logical not operator

¬x := table(
 1 0 
 0 1
)

: the logical and operator
x∧x := table(
   1 0
 1 1 0
 0 0 0
)
  
: the logical or operator

x∨x := table(
   1 0
 1 1 1
 0 1 0
)

: the logical implication operator

x→x := table(
   1 0
 1 1 0
 0 1 1
)

: the logical bidirectional implication operator

x↔x := table(
   1 0
 1 1 0
 0 0 1
)








: (A ∨ B) ↔ ¬(¬A ∧ ¬B)

