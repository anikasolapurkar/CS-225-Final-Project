#pragma once

class Route {
    public:
        Route();
        Route(int s, int d);
        Route(int s, int d, double w);

        //getters
        int getSourceId();       
        int getDestId();         
        double getWeight();
       
        //setters
        void setWeight(double w);
        void setSource(double s);
        void setDestination(double d); 

        //operator overloading
        bool operator<(const Route& other) const;
        bool operator==(Route& other) const;
    
    private:
        int sourceAirport;
        int destAirport;
        double weight;
};