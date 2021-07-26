#ifndef HIGHPASS_H
#define HIGHPASS_H

class Highpass 
{
public:
    Highpass() {};
    ~Highpass() {};
    bool init(double tau, double delta_t);
    double update(double u);
    void reset();
	bool get_init_state() { return _is_init; }
private:
    
    bool _is_init{false};

    double _alpha{0.0};
    double _tau{1.0};
    double _delta_t{0.0};
    double _y_last{0.0};
    double _u_last{0.0};
    double _y{0.0};
};



#endif // HIGHPASS_H