**Algorithm**

1. Start.
2. Declare all required arrays and variables.
3. Initialize `dataReady = 0`.
4. Display the menu and accept the user's choice.
5. Use a switch statement to perform the selected operation:
   - Case 1: Call `inputData()` and set `dataReady = 1`.
   - Case 2: If data is available, call `displayData()`.
   - Case 3: If data is available, call `calculateAverages()`.
   - Case 4: If data is available, call `detectRiskZones()`.
   - Case 5: If data is available, call `calculateAverages()`, `computeGreenIndex()` and `displayRanking()`.
   - Case 6: If data is available, call `calculateAverages()`, `detectRiskZones()` and `displayRecommendations()`.
   - Case 7: Exit the program.
   - Default: Display an invalid choice message.
6. If data is not available for options 2–6, display a message.
7. Repeat the menu until the user selects Exit.
8. Stop.
