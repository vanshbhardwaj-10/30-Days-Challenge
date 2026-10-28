# Algorithm – TICKET TRACE

1. Start

2. Enter the number of tickets N. If N is less than 5 or greater than 15, ask for the input again.

3. Enter all the ticket IDs. If any ID is outside the range 1 to N, ask for that ID again.

4. Enter the last two digits of the registration number.

5. Display the original sequence of ticket IDs.

6. Check each ID from 1 to N and count how many times it appears in the sequence. If an ID appears twice, it is the duplicate ID. If an ID does not appear, it is the missing ID.

7. If the log does not have exactly one duplicate ID and one missing ID, display “Invalid Log” and stop further calculations.

8. Compare each ticket ID with the IDs that come after it. If the first ID is greater than the second ID, increase the out-of-order pair count by 1. Display the total count.

9. Calculate the target ticket ID using the formula:

   Target = (Regno % N) + 1

10. Find and display all the positions where the target ID appears. Also display its total occurrence count.

11. Stop.
