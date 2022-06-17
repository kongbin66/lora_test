#include "m_config.h"

void hardware_init()
{
  Serial.begin(115200);
  delay(5000);
  Serial.println(__FILE__);//__FILE__路径
  Serial.print("SHT2x_LIB_VERSION: \t");//\t:水平制表符
  Serial.println(SHT2x_LIB_VERSION);

  Serial1.begin(9600, SERIAL_8N1, MODEM_RX, MODEM_TX); 
  sht.begin();

}