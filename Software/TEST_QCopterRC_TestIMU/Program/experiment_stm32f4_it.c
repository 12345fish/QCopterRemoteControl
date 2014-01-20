/*=====================================================================================================*/
/*=====================================================================================================*/
#include "stm32f4_system.h"
#include "stm32f4_i2c.h"
#include "system_waveForm.h"
#include "module_mpu6050.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
extern WaveForm_Struct WaveForm;
/*=====================================================================================================*/
/*=====================================================================================================*/
void SysTick_Handler( void )
{
  u8 IMU_Buf[16] = {0};
  vs16 Acc[3] = {0};
  vs16 Gyr[3] = {0};

  I2C_DMA_ReadReg(MPU6050_I2C_ADDR, MPU6050_ACCEL_XOUT_H, IMU_Buf, 14);

  Acc[0]  = (s16)((IMU_Buf[0]  << 8) | IMU_Buf[1]);
  Acc[1]  = (s16)((IMU_Buf[2]  << 8) | IMU_Buf[3]);
  Acc[2]  = (s16)((IMU_Buf[4]  << 8) | IMU_Buf[5]);
  Gyr[0]  = (s16)((IMU_Buf[8]  << 8) | IMU_Buf[9]);
  Gyr[1]  = (s16)((IMU_Buf[10] << 8) | IMU_Buf[11]);
  Gyr[2]  = (s16)((IMU_Buf[12] << 8) | IMU_Buf[13]);

  WaveForm.Data[0] = Acc[0];
  WaveForm.Data[1] = Acc[1];
  WaveForm.Data[2] = Acc[2];

//  WaveForm.Data[0] = Gyr[0];
//  WaveForm.Data[1] = Gyr[1];
//  WaveForm.Data[2] = Gyr[2];
}
/*=====================================================================================================*/
/*=====================================================================================================*/
void HardFault_Handler( void )
{
  while(1);
}
void MemManage_Handler( void )
{
  while(1);
}
void BusFault_Handler( void )
{
  while(1);
}
void UsageFault_Handler( void )
{
  while(1);
}
void SVC_Handler( void )
{
  while(1);
}
void DebugMon_Handler( void )
{
  while(1);
}
void PendSV_Handler( void )
{
  while(1);
}
void NMI_Handler( void )
{
  while(1);
}
/*=====================================================================================================*/
/*=====================================================================================================*/