#include "PID.h"
#include <algorithm>

PID::PID()
{
    
}

PID::~PID()
{
    
}

void PID::Init(double inKp, double inKi, double inKd)
{
    Kp = inKp;
    Ki = inKi;
    Kd = inKd;
    
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
    
    // Previous CTE
    previous_cte = 0.0;
    
    // Error counters
    counter = 0;
    errorSum = 0.0;
    minError = std::numeric_limits<double>::max();
    maxError = std::numeric_limits<double>::min();
}

void PID::UpdateError(double cte)
{
    // Proportional error
    p_error = cte;
    
    // Integral error
    i_error += cte;
    
    // Diferential error
    d_error = cte - previous_cte;
    previous_cte = cte;
    
    errorSum += cte;
    counter++;
    
    if (cte < minError)
    {
        minError = cte;
    }
    
    if (cte > maxError)
    {
        maxError = cte;
    }
}

double PID::GetTotalError()
{
    return p_error * Kp + i_error * Ki + d_error * Kd;
}

/**
 * Get the max error
 */
double PID::GetMaxError()
{
    return maxError;
}

/**
 * Get the min error
 */
double PID::GetMinError()
{
    return minError;
}

/**
 * Get the average error
 */
double PID::GetAverageError()
{
    return errorSum / counter;
}
