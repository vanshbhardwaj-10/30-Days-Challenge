# Algorithm – TICKET TRACE

## Main Function
1. Start 
2. Call `ticketinput()` to take the number of tickets, ticket IDs and registration number.
3. Display the original ticket sequence.
4. Call `duplicatemissing()` to find the duplicate and missing IDs.
5. If the log is valid, call `outordercnt()` to count the out-of-order pairs.
6. If the log is valid, call `targetticket()` to find the target ID, its positions and occurrence count.
7. Stop 

## Function 1: ticketinput()
1. Ask the user to enter N.
2. If N is less than 5 or greater than 15, ask the user to enter it again.
3. Take N ticket IDs as input.
4. If any ticket ID is less than 1 or greater than N, ask the user to enter it again.
5. Ask the user to enter the last two digits of the registration number.

## Function 2: duplicatemissing()
1. Set the duplicate ID and missing ID to 0.
2. Check each ID from 1 to N and count its occurrences in the sequence.
3. If an ID occurs twice, store it as the duplicate ID.
4. If an ID does not occur, store it as the missing ID.
5. Count the number of duplicate IDs and missing IDs.
6. If there is exactly one duplicate ID and one missing ID, display both IDs.
7. Otherwise, display "Invalid log" and mark the log as invalid.

## Function 3: outordercnt()
1. Set the out-of-order pair count to 0.
2. Compare each ticket ID with every ID that comes after it.
3. If the first ID is greater than the second ID, increase the count by 1.
4. Display the total number of out-of-order pairs.

## Function 4: targetticket()
1. Calculate the target ID using `(Regno % N) + 1`.
2. Display the target ID.
3. Check each ticket ID in the sequence.
4. If a ticket ID matches the target ID, display its position and increase the occurrence count by 1.
5. Display the total occurrence count.


Stop 
