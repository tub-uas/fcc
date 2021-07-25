#ifndef LOWPASS_H
#define LOWPASS_H

class Lowpass 
{
public:
    Lowpass() {};
    ~Lowpass() {};
    bool init(double tau, double delta_t);
    double update(double u);
    void reset();
private:
    
    bool _is_init{false};

    double _alpha{0.0};
    double _tau{1.0};
    double _delta_t{0.0};
    double _y_last{0.0};
    double _y{0.0};
};




#endif