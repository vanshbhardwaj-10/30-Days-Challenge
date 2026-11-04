### Algorithm

1. Start the program and declare a 2D array of 5 rows and 8 columns.
2. Initialize all seats with 0, representing available seats.
3. Display the menu and ask the user to enter a choice.
4. If the user selects Display Seats, show the current status of all seats.
5. If the user selects Book a Seat, accept the row and seat number, validate the input and book the seat if it is available.
6. If the user selects Cancel Booking, check whether the selected seat is booked and change its status to available.
7. If the user selects Group Reservation, accept the group size and search for consecutive available seats in the same row. Book them if a suitable block is found.
8. If the user selects Occupancy Report, calculate the total booked seats, available seats, occupancy percentage and busiest row(s).
9. If the user enters an invalid choice or input, display an appropriate error message.
10. Repeat the menu until the user selects Exit.
11. Stop the program.
