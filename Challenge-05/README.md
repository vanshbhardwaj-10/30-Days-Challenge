## Algorithm

1. Start.
2. Declare the required variables.
3. Display the menu containing Linear Equation, Factorial, Quadratic Equation, and Exit.
4. Accept the user's choice.
5. If the choice is 1, input the values of `a` and `b`.
6. If `a` is not equal to 0, calculate `x = -b/a` and display the solution.
7. Otherwise, if `b` is equal to 0, display "Infinitely many solutions"; else display "No solution".
8. If the choice is 2, input the value of `n`.
9. If `n` is less than 0 or greater than 12, display "Invalid input".
10. Otherwise, initialize `fact = 1`.
11. Use a `for` loop to multiply `fact` by each integer from 1 to `n`.
12. Display the factorial result.
13. If the choice is 3, input the values of `a`, `b`, and `c`.
14. If `a` is equal to 0, display "Not a quadratic equation".
15. Otherwise, calculate the discriminant `D = b*b - 4*a*c`.
16. If `D > 0`, calculate and display the two distinct real roots.
17. If `D == 0`, calculate and display the repeated real root.
18. If `D < 0`, display "No real roots".
19. If the choice is 4, display a closing message; otherwise, display an error for an invalid choice. Repeat the menu until the user selects 4.
20. Stop.
