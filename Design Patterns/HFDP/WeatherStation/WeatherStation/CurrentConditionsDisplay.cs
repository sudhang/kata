using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WeatherStation
{
    class CurrentConditionsDisplay : DisplayElement, Observer
    {
        private float temperature;
        private float humidity;
        private Subject weatherData;

        public CurrentConditionsDisplay(Subject weatherData)
        {
            this.weatherData = weatherData;
            weatherData.registerObserver(this);
        }

        public void update(float temperature, float humidity, float pressure)
        {
            this.temperature = temperature;
            this.humidity = humidity;
            display();
        }

        public void display()
        {
            Console.WriteLine("Current conditions: " + temperature + " F degrees and " + humidity + " % humidity");
        }
    }
}
