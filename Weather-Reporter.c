#include <stdio.h>
#include <stdlib.h>

float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void displayTemperatureReport(float temperatures[], int days);
void checkTemperatureWarning(float temperature);

int main() {
    const int DAYS = 30;
    float temperatures[DAYS];
    float maxTemp = -100, minTemp = 100, sumTemp = 0;
    
    printf("Weather Monitoring System\n");
    printf("========================\n\n");

    for (int i = 0; i < DAYS; i++) {
        float temp;
        do {
            printf("Enter temperature for day %d (in Celsius): ", i + 1);
            if (scanf("%f", &temp) != 1) {
                printf("Invalid input. Please enter a numeric value.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
            if (temp < -50 || temp > 50) {
                printf("Temperature must be between -50°C and 50°C\n");
                continue;
            }
            break;
        } while (1);

        temperatures[i] = temp;
        sumTemp += temp;

        if (temp > maxTemp) maxTemp = temp;
        if (temp < minTemp) minTemp = temp;

        checkTemperatureWarning(temp);
    }

    float avgTemp = sumTemp / DAYS;

    printf("\nMonthly Weather Report\n");
    printf("=====================\n\n");

    displayTemperatureReport(temperatures, DAYS);

    printf("\nSummary:\n");
    printf("--------\n");
    printf("Average Temperature: %.2f°C (%.2f°F)\n", 
           avgTemp, celsiusToFahrenheit(avgTemp));
    printf("Maximum Temperature: %.2f°C (%.2f°F)\n", 
           maxTemp, celsiusToFahrenheit(maxTemp));
    printf("Minimum Temperature: %.2f°C (%.2f°F)\n", 
           minTemp, celsiusToFahrenheit(minTemp));

    return 0;
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

void displayTemperatureReport(float temperatures[], int days) {
    printf("Daily Temperature Records:\n");
    printf("-------------------------\n");
    printf("Day  | Temperature (C) | Temperature (F) | Freezing Status\n");
    printf("-----|-----------------|-----------------|----------------\n");
    for (int i = 0; i < days; i++) {
        printf("%3d  | %13.2f°C | %13.2f°F | ", 
               i + 1, temperatures[i], celsiusToFahrenheit(temperatures[i]));

        if (temperatures[i] < 0) {
            printf("!!! BELOW FREEZING !!!\n");
        } else {
            printf("Above Freezing\n");
        }
    }
}

void checkTemperatureWarning(float temperature) {
    if (temperature < 0) {
        printf("WARNING: Temperature below freezing point (0°C)!\n");
    }
}

