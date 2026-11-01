Algorithm – GRIDWATCH
1. Start.
2. Declare a 2D array riskscore[6][6] and required variables.
3. Read the grid size N and validate that it is between 3 and 6.
4. Read the risk scores of the grid and validate each score is between 0 and 100.
5. Read the minimum risk threshold T and validate that it is between 1 and 100.
6. Calculate the sum of each row and identify all rows having the highest sum.
7. Calculate the sum of each column and identify all columns having the highest sum.
8. Find the highest individual risk score and display all positions where it occurs.
9. Count the number of cells whose scores are greater than or equal to T.
10. Calculate the main diagonal and secondary diagonal sums. If both sums are equal, report that the diagonals are balanced.
11. Calculate the sum of all boundary elements, counting each element only once.
12. Check all interior cells to identify hotspots. A cell is a hotspot if its value is greater than its four adjacent neighbours and greater than or equal to T.
13. Count and display all identified hotspots. If none exist, display a suitable message.
14. If at least one hotspot exists, display CRITICAL.
15. Otherwise, if the number of cells meeting the threshold is greater than or equal to N, display WARNING.
16. Otherwise, display NORMAL.
17. Stop.
