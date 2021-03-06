/*
              FRONT
              CW (0)
                
                O
                |
                |
                |
  CCW (3) O-----#-----O CCW (1)
    LEFT        |       RIGHT
                |
                |
                O
                
              CW (2)
               BACK
*/

#define MOTORS 4
uint16_t MotorOut[MOTORS] = {1000, 1000, 1000, 1000}; 

void updateMotorsMix() {
    // Limit YAW to +- 200 (20%)
    YawMotorSpeed = constrain(YawMotorSpeed, -200, 200);
    
    // All of the motor outputs are constrained to standard 1000 - 2000 us PWM
    // Minimum Armed Throttle variable was added to prevent motors stopping during flight (in extreme "stabilization" behaviours)
    MotorOut[0] = constrain(throttle + PitchMotorSpeed + YawMotorSpeed, CONFIG.data.minimumArmedThrottle, 2000);
    MotorOut[1] = constrain(throttle - RollMotorSpeed  - YawMotorSpeed, CONFIG.data.minimumArmedThrottle, 2000);
    MotorOut[2] = constrain(throttle - PitchMotorSpeed + YawMotorSpeed, CONFIG.data.minimumArmedThrottle, 2000);
    MotorOut[3] = constrain(throttle + RollMotorSpeed  - YawMotorSpeed, CONFIG.data.minimumArmedThrottle, 2000); 
}