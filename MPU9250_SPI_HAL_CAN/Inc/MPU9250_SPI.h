
#ifndef __MPU9250_SPI
#define __MPU9250_SPI

#include "stm32f1xx_hal.h"
#define NSS_HIGH 		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,1)
#define NSS_LOW 		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,0)

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
		
		


extern SPI_HandleTypeDef hspi1;

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

int mpuBegin(void);

int whoAmI(void);

int whoAmIAK8963(void);

int mpuReadSensor(struct mpuSensorData *data);

int enableDataReadyInterrupt(void);

int disableDataReadyInterrupt(void);

int setAccelRange(enum AccelRange range);

int setGyroRange(enum GyroRange range);

int setDlpfBandwidth(enum DlpfBandwidth bandwidth) ;

int setSrd(uint8_t srd) ;

int mpuMyCustomConfig(void);




#endif
