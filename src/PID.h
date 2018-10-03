#ifndef PID_H
#define PID_H

class PID
{
public:
    
    /**
     * Constructor
     */
    PID();
    
    /**
     * Destructor
     */
    virtual ~PID();
    
    /**
     * Initialize the PID
     */
    void Init(double inKp, double inKi, double inKd);
    
    /**
     * Update the PID error variables given cross track error
     */
    void UpdateError(double cte);
    
    /**
     * Calculate the total PID error
     */
    double GetTotalError();
    
    double GetMaxError();
    double GetMinError();
    double GetAverageError();
    
private:
    
    /**
     * Errors
     */
    double p_error;
    double i_error;
    double d_error;
    double previous_cte;
    
    /**
     * Coefficients
     */
    double Kp;
    double Ki;
    double Kd;
    
    /**
     * Error counters
     */
    long counter;
    double errorSum;
    double minError;
    double maxError;
};

#endif /* PID_H */
