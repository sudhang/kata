using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WeatherStation
{
    class WeatherStation
    {
        static void Main(string[] args)
        {
            WeatherData weatherData = new WeatherData();

            CurrentConditionsDisplay currentDisplay = new CurrentConditionsDisplay(weatherData);

            weatherData.setMeasurements(90, 34, 13.5f);
            weatherData.setMeasurements(92, 35, 16.2f);
            weatherData.setMeasurements(89, 33, 14.5f);
        }
    }
}
