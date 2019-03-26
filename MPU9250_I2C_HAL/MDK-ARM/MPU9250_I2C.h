
#ifndef __MPU9250_I2C
#define __MPU9250_I2C

#include "stm32f1xx_hal.h"

enum GyroRange
    {
      GYRO_RANGE_250DPS,
      GYRO_RANGE_500DPS,
      GYRO_RANGE_1000DPS,
      GYRO_RANGE_2000DPS
    };
    enum AccelRange
    {
      ACCEL_RANGE_2G,
      ACCEL_RANGE_4G,
      ACCEL_RANGE_8G,
      ACCEL_RANGE_16G    
    };
    enum DlpfBandwidth
    {
      DLPF_BANDWIDTH_184HZ,
      DLPF_BANDWIDTH_92HZ,
      DLPF_BANDWIDTH_41HZ,
      DLPF_BANDWIDTH_20HZ,
      DLPF_BANDWIDTH_10HZ,
      DLPF_BANDWIDTH_5HZ
    };
    enum LpAccelOdr
    {
      LP_ACCEL_ODR_0_24HZ = 0,
      LP_ACCEL_ODR_0_49HZ = 1,
      LP_ACCEL_ODR_0_98HZ = 2,
      LP_ACCEL_ODR_1_95HZ = 3,
      LP_ACCEL_ODR_3_91HZ = 4,
      LP_ACCEL_ODR_7_81HZ = 5,
      LP_ACCEL_ODR_15_63HZ = 6,
      LP_ACCEL_ODR_31_25HZ = 7,
      LP_ACCEL_ODR_62_50HZ = 8,
      LP_ACCEL_ODR_125HZ = 9,
      LP_ACCEL_ODR_250HZ = 10,
      LP_ACCEL_ODR_500HZ = 11
    };
		
		

#define chipAddr 0x68*2

extern I2C_HandleTypeDef hi2c1;

struct mpuSensorData{
    int16_t ax,ay,az;
    int16_t gx,gy,gz;
    int16_t hx,hy,hz;
    int16_t t;
};

int mpu9250WriteReg(uint8_t regAddr, uint8_t regVal);

int mpu9250ReadReg( uint8_t regAddr, uint8_t *regVal , uint16_t count) ;

int readRegisters(uint8_t subAddress, uint8_t count, uint8_t* dest);
  
int writeRegister(uint8_t subAddress, uint8_t data);
		
int writeAK8963Register(uint8_t subAddress, uint8_t data);
		
int readAK8963Registers(uint8_t subAddress, uint8_t count, uint8_t* dest);

int mpuBegin();

int whoAmI();

int whoAmIAK8963();

int mpuReadSensor(struct mpuSensorData *data);




#endif
