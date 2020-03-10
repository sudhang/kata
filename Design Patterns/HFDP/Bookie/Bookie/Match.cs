using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;

namespace Bookie
{
    class Match : Subject
    {
        public string teamA { get; set; }
        public string teamB { get; set; }
        private float _odds;
        public float odds 
        {
            get
            {
                return this._odds;
            }
            set
            {
                this._odds = value;
                notifyObservers();
                Console.WriteLine("All Betters notified");
            }
        }

        private ArrayList observers;

        public Match(string teamA, string teamB)
        {
            this.teamA = teamA;
            this.teamB = teamB;
            observers = new ArrayList();
        }

        public void registerObserver(Observer o)
        {
            observers.Add(o);
        }

        public void unRegisterObserver(Observer o)
        {
            observers.Remove(o);
        }

        public void notifyObservers()
        {
            foreach (Observer o in observers)
            {
                o.update(odds);
            }
        }
    }
}
