using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;

namespace WeatherStation
{
    class WeatherData : Subject
    {
        private ArrayList observers;
        private float temperature;
        private float humidity;
        private float pressure;

        public WeatherData()
        {
            observers = new ArrayList();
        }

        public void registerObserver(Observer o)
        {
            observers.Add(o);
        }

        public void unRegisterObserver(Observer o)
        {
            int idx = observers.IndexOf(o);
            if ( idx >= 0)
            {
                observers.Remove(o);
            }
        }

        public void notifyObservers()
        {
            foreach (Observer item in observers)
            {
                item.update(temperature, humidity, pressure);
            }
        }

        public void measurementsChanged()
        {
            notifyObservers();
        }

        public void setMeasurements(float temperature, float humidity, float pressure)
        {
            this.temperature = temperature;
            this.humidity = humidity;
            this.pressure = pressure;
            measurementsChanged();
        }
    }
}
