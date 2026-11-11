#include <stdio.h>
#define ZONES 5
#define DAYS 7

void inputData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS]);
void displayData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS]);
void calculateAverages(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS], float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES]);
void detectRiskZones(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS], int riskDays[ZONES]);
void computeGreenIndex(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES], float greenIndex[ZONES]);
void displayRanking(float greenIndex[ZONES]);
void displayRecommendations(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES], int riskDays[ZONES]);

int main()
{
    float temp[ZONES][DAYS];
    float humidity[ZONES][DAYS];
    int aqi[ZONES][DAYS];

    float avgTemp[ZONES], avgHumidity[ZONES], avgAQI[ZONES];
    float greenIndex[ZONES];
    int riskDays[ZONES];

    int choice;
    int dataReady = 0;

    do
    {
        printf("1. Input / Update Data\n");
        printf("2. Display Data\n");
        printf("3. Zone-wise Averages\n");
        printf("4. Detect Risk Days\n");
        printf("5. Green Index and Ranking\n");
        printf("6. Recommendations\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                inputData(temp, humidity, aqi);
                dataReady = 1;
                break;

            case 2:
                if(dataReady == 0)
                {
                    printf("Please enter data first!\n");
                }
                else
                {
                    displayData(temp, humidity, aqi);
                }
                break;

            case 3:
                if(dataReady == 0)
                {
                    printf("Please enter data first!\n");
                }
                else
                {
                    calculateAverages(temp, humidity, aqi, avgTemp, avgHumidity, avgAQI);

                    for(int i = 0; i < ZONES; i++)
                    {
                        printf("Zone %d\n", i + 1);
                        printf("Average Temperature: %.2f\n", avgTemp[i]);
                        printf("Average Humidity: %.2f\n", avgHumidity[i]);
                        printf("Average AQI: %.2f\n", avgAQI[i]);
                    }
                }
                break;

            case 4:
                if(dataReady == 0)
                {
                    printf("Please enter data first!\n");
                }
                else
                {
                    detectRiskZones(temp, humidity, aqi, riskDays);
                }
                break;

            case 5:
                if(dataReady == 0)
                {
                    printf("Please enter data first!\n");
                }
                else
                {
                    calculateAverages(temp, humidity, aqi, avgTemp, avgHumidity, avgAQI);
                    computeGreenIndex(avgTemp, avgHumidity, avgAQI, greenIndex);
                    displayRanking(greenIndex);
                }
                break;

            case 6:
                if(dataReady == 0)
                {
                    printf("Please enter data first!\n");
                }
                else
                {
                    calculateAverages(temp, humidity, aqi, avgTemp, avgHumidity, avgAQI);
                    detectRiskZones(temp, humidity, aqi, riskDays);
                    displayRecommendations(avgTemp, avgHumidity, avgAQI, riskDays);
                }
                break;

            case 7:
                printf("Thank you for using ECOGUARD!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 7);

    return 0;
}
void inputData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS])
{
    int i,j;

    for (i = 0; i < ZONES; i++)
    {
        printf("Enter data for Zone %d\n", i + 1);

        for (j = 0; j < DAYS; j++)
        {
            printf("Day %d\n", j + 1);

            do
            {
                printf("Enter temperature (10-50): ");
                scanf("%f", &temp[i][j]);

                if (temp[i][j] < 10 || temp[i][j] > 50)
                {
                    printf("Invalid temperature! Try again.\n");
                }

            } while (temp[i][j] < 10 || temp[i][j] > 50);

            do
            {
                printf("Enter humidity (0-100): ");
                scanf("%f", &humidity[i][j]);

                if (humidity[i][j] < 0 || humidity[i][j] > 100)
                {
                    printf("Invalid humidity! Try again.\n");
                }

            } while (humidity[i][j] < 0 || humidity[i][j] > 100);

            do
            {
                printf("Enter AQI (0-500): ");
                scanf("%d", &aqi[i][j]);

                if (aqi[i][j] < 0 || aqi[i][j] > 500)
                {
                    printf("Invalid AQI! Try again.\n");
                }

            } while (aqi[i][j] < 0 || aqi[i][j] > 500);
        }
    }
}

void displayData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS])
{
    int i,j;
    printf("\n===== TEMPERATURE DATA =====\n");
    for (i = 0; i < ZONES; i++)
    {
        printf("Zone %d: ", i + 1);

        for(j = 0; j < DAYS; j++)
        {
            printf("%f ", temp[i][j]);
        }

        printf("\n");
    }

    printf("\n===== HUMIDITY DATA =====\n");
    for (i = 0; i < ZONES; i++)
    {
        printf("Zone %d: ", i + 1);

        for (j = 0; j < DAYS; j++)
        {
            printf("%f ", humidity[i][j]);
        }

        printf("\n");
    }

    printf("\n===== AQI DATA =====\n");

    for (i = 0; i < ZONES; i++)
    {
        printf("Zone %d: ", i + 1);

        for (j = 0; j < DAYS; j++)
        {
            printf("%d ", aqi[i][j]);
        }

        printf("\n");
    }
}

void calculateAverages(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS], float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES])
{
    int i,j;
    float sumTemp, sumHumidity, sumAQI;
    for (i = 0; i < ZONES; i++)
    {
        sumTemp = 0;
        sumHumidity = 0;
        sumAQI = 0;

        for (j = 0; j < DAYS; j++)
        {
            sumTemp = sumTemp + temp[i][j];
            sumHumidity = sumHumidity + humidity[i][j];
            sumAQI = sumAQI + aqi[i][j];
        }

        avgTemp[i] = sumTemp / DAYS;
        avgHumidity[i] = sumHumidity / DAYS;
        avgAQI[i] = sumAQI / DAYS;
    }
}
void detectRiskZones(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS], int riskDays[ZONES])
{
    int i,j;
    for (i = 0; i < ZONES; i++)
    {
        riskDays[i] = 0;

        printf("\nZone %d Risk Days: ", i + 1);

        for (j = 0; j < DAYS; j++)
        {
            if(aqi[i][j] > 150 || temp[i][j] > 35 || humidity[i][j] > 80)
            {
                riskDays[i]++;
                printf("%d ", j + 1);
            }
        }

        printf("\nTotal Risk Days: %d\n", riskDays[i]);

        if (riskDays[i] == 0)
        {
            printf("No risk detected.\n");
        }
    }
}
void computeGreenIndex(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES], float greenIndex[ZONES])
{
    int i;
    float aqiScore, tempScore, humidityScore;
    float difference;

    for (i = 0; i < ZONES; i++)
    {
        aqiScore = 100 - (avgAQI[i] / 5);
        difference = avgTemp[i] - 25;
        if(difference < 0)
        {
            difference = -difference;
        }
        tempScore = 100 - (4 * difference);
        difference = avgHumidity[i] - 50;
        if (difference < 0)
        {
            difference = -difference;
        }
        humidityScore = 100 - (2 * difference);
        if (aqiScore < 0)
        {
            aqiScore = 0;
        }
        if (tempScore < 0)
        {
            tempScore = 0;
        }

        if (humidityScore < 0)
        {
            humidityScore = 0;
        }
        greenIndex[i] = (0.4 * aqiScore) + (0.3 * tempScore) + (0.3 * humidityScore);
    }
}

void displayRanking(float greenIndex[ZONES])
{
    int i, j, rank, higher;
    printf("\n===== GREEN INDEX RANKING =====\n");
    for (i = 0; i < ZONES; i++)
    {
        higher = 0;
        for (j = 0; j < ZONES; j++)
        {
            if (greenIndex[j] > greenIndex[i])
            {
                higher++;
            }
        }
        rank = higher + 1;
        printf("Zone %d: Green Index = %.2f, Rank = %d\n", i + 1, greenIndex[i], rank);
    }
}
void displayRecommendations(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES], int riskDays[ZONES])
{
    int i;
    printf("\n===== ENVIRONMENTAL RECOMMENDATIONS =====\n");
    for (i = 0; i < ZONES; i++)
    {
        printf("Zone %d:\n", i + 1);
        if (avgAQI[i] > 150)
        {
            printf("Reduce vehicle idling or improve ventilation.\n");
        }
        if (avgTemp[i] > 35)
        {
            printf("Provide more shade or green cover.\n");
        }
        if (avgHumidity[i] > 80)
        {
            printf("Check ventilation or stagnant-water sources.\n");
        }
        if (avgAQI[i] <= 150 && avgTemp[i] <= 35 && avgHumidity[i] <= 80)
        {
            if(riskDays[i] > 0)
            {
                printf("Review the individual days that triggered risk.\n");
            }
            else
            {
                printf("No risk detected. Continue monitoring.\n");
            }
        }
    }
}