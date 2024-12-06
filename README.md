# Weather Monitoring System | 12/01/2024

In this project, we have created a manual weather monitoring system IN C that uses
multiple vanilla implementations to allow the user to manually input their weather data for
the month and analyze it within a period of 30 days.

> Also allows users to have temperature conversion as well as warnings, and statistical analysis of the data provided.

## Approach:
Our program revolves around main components where:
```C
float celsiusToFahrenheit(float celsius);
// Maintained the value in Celsius
float fahrenheitToCelsius(float fahrenheit);
// Maintains the value for Farenheit
void displayTemperatureReport(float temperatures[], int days); // Temp
report handler.
void checkTemperatureWarning(float temperature);
// Administers temperature warnings
```

Some parts of the code design are static IE:
Temperature range is based at a 100-degree scale: -50*C to 50*C
Time period of 30 days. This can be changed in the main file incase needed:
Input of temperature: Temperature is Celsius only as the tool auto transposes it for you.
Error handing in done with a do statement where:
```C
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
```

The code above represents a small amount of if statements where it shows what occurs
when either an invalid character or a character out of range is inserted into the program, keeping it from crashing the program as a whole.

## Test scenarios:

1. Normal usage:
```
Enter temperature for day 1 (in Celsius): 25.5
Enter temperature for day 2 (in Celsius): 26.7
[...]
```

2. Error handling :
```
Enter temperature for day 1 (in Celsius): abc
Invalid input. Please enter a numeric value.
Enter temperature for day 1 (in Celsius): 25.5
```

3. Temperature warnings:
```
Enter temperature for day 1 (in Celsius): -2.5
WARNING: Temperature below freezing point (0°C)!
```

#### Additional Information:

1. Array are implemented to make it easier to output:
```C
const int DAYS = 30;
float temperatures[DAYS];
```

2. Statistical analysis implemented for average, max, and min temperature:
```C
float maxTemp = -100, minTemp = 100, sumTemp = 0;
// [...] calculation logic
float avgTemp = sumTemp / DAYS;
```

3. Conversios are done automatically to allow easy reading for the user:
```C
float celsiusToFahrenheit(float celsius) {
return (celsius * 9/5) + 32;
}
```

#### Challenges:
- Sanitizing the input of the temperature was effectively needed to keep the code running
smoothly without crashing which makes the user lose their progress when inputting the data when a mistake is made.

#### Solutions:
- Using the loop provided above and attaching to the input effectively hanbdles errors with ease and allows the data to be handled efficiently even if it takes a few Ms longer for the program to run it.

## References:
- Notes provided on Canvas
- Previous knowledge in Java (Allowing me to easily look up similar syntax to use)
- Sample code is provided for this project.
