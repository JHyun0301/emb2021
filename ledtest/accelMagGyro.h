#ifndef _ACCELMAGGYRO_H_
#define _ACCELMAGGYRO_H_

#define ACCELPATH "/sys/class/misc/FreescaleAccelerometer/"
#define MAGNEPATH "/sys/class/misc/FreescaleMagnetometer/"
#define GYROPATH "/sys/class/misc/FreescaleGyroscope/"

void Accelerometer(void);
void Magnetometer(void);
void Gyroscope(void);

#endif
