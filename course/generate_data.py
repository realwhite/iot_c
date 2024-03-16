import csv
import datetime
import random
import numpy as np
import matplotlib.pyplot as plt

START_DATE = '2021-01-01'
FINISH_DATE = '2022-01-01'


def generate_temperatures(size):
    # https://stackoverflow.com/questions/72722387/generate-time-series-for-day-year-fluctuations-using-python


    # parameters
    MeanTemp = 13          # Average temperature in the country
    DailyAmpl = 10          # Amplitude of the daily cycle
    YearlyAmpl = 8         # Amplitude of the yearly cycle
    NoiseStd = 1.1         # Standard deviation of normally distributed error term

    # Total hours in year
    TotalMinutes = size

    # Generate the frequency components of the data
    x = np.arange(0, TotalMinutes)
    DailyCycle = -DailyAmpl*np.cos( (2*np.pi)*x/(24*60) )
    YearlyCycle = -YearlyAmpl*np.cos( (2*np.pi)*x/TotalMinutes )
    Noise = np.random.normal(5,NoiseStd, TotalMinutes)

    # Final series
    y = MeanTemp + DailyCycle + YearlyCycle + Noise

    # Visualise result
    fig, axs = plt.subplots(2, 1)
    axs[0].plot(y)
    axs[0].set_title('Complete series')
    plt.show()

    return y


def main():
    current_dt = datetime.datetime.strptime(START_DATE, '%Y-%m-%d')
    finish_dt = datetime.datetime.strptime(FINISH_DATE, '%Y-%m-%d')
    temperature_data = generate_temperatures(60 * 24 * 365)

    
    
    count = 0
    rows = []
    while current_dt < finish_dt:
        current_dt = current_dt + datetime.timedelta(minutes=1)
        rows.append((current_dt.year, current_dt.month, current_dt.day, current_dt.hour, current_dt.minute, int(temperature_data[count])))
        count += 1

    # random.shuffle(rows)

    with open('temperature_real.csv', 'w') as f:
        w = csv.writer(f, delimiter=';')
        w.writerows(rows)


if __name__ == '__main__':
    main()