using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WeatherStation
{
    public interface Subject
    {
         void registerObserver(Observer o);
         void unRegisterObserver(Observer o);
         void notifyObservers();
    }
}
