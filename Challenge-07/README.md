## Algorithm – TICKET TRACE

1. Start 
2. Enter the number of tickets. If it is not between 5 and 15, enter it again.
3. Enter the ticket IDs one by one. If an ID is not between 1 and N, enter it again.
4. Enter the last two digits of the registration number.
5. Print all the ticket IDs in the same order as entered.
6. Check every ID from 1 to N and count its occurrences.
7. If an ID occurs twice, store it as the duplicate ID. If an ID does not occur, store it as the missing ID.
8. If the log does not contain exactly one duplicate ID and one missing ID, print “Invalid Log”.
9. Otherwise, print the duplicate ID and the missing ID.
10. Compare each ticket with the tickets after it. If the first ticket is greater than the second, increase the out-of-order count.
11. Print the total number of out-of-order pairs.
12. Calculate the target ID using (Regno % N) + 1.
13. Print all positions where the target ID is found and count how many times it occurs.
14. Stop 
