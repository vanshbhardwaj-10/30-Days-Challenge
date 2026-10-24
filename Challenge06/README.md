Algorithm – Pattern Detective

1. Start.
2. Declare a one-dimensional array a[12] and the required variables.
3. Input N. If N is less than 5 or greater than 12, ask again.
4. Input N readings into the array. If any reading is less than 0 or greater than 1000, ask for that reading again.
5. Calculate the sum of all readings while entering them.
6. Display the original array.
7. Initialize min and max with the first array element. Traverse the array to find the minimum and maximum values.
8. Calculate and display the average using sum / N.
9. Find the second-largest distinct value by checking elements smaller than the maximum and keeping the largest among them. If no such value exists, display an appropriate message.
10. Count local peaks by checking whether each interior element is strictly greater than its immediate left and right neighbours.
11. Find the longest strictly increasing contiguous run by increasing the current run length when an element is greater than its previous element; otherwise, reset the run length to 1.
12. Input the rotation value K.
13. Calculate K % N. If the result is negative, add N to it.
14. Rotate the array to the right by the resulting number of positions. For each rotation, store the last element in a temporary variable, shift all elements one position right, and place the stored element at the beginning.
15. Display the rotated array.
16. Input R, the last two digits of the registration number.
17. Calculate the divisor \(D = (R \% 9) + 1\).
18. Count the elements in the rotated array that are divisible by D.
19. Display D and the count of divisible elements.
20. Stop.
