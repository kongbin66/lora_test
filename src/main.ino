#include "m_config.h"
uint32_t ADDR=0x78563421;
char DEVICE_ID[4]={};
char cmd_tab[11]={0x00,0x01,0x17,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00};
float rawtem=0;
float rawhum=0;


// struct TH_data
// {
//   /* data */
//   addr[3],

// };

//采集温湿度
void Collection_temperature_humidity()
{
    sht.read();
    rawtem=sht.getTemperature();
    rawhum=sht.getHumidity();
}
//LORA发送温湿度
void print_send()
{
      int temp =(int)(rawtem*100);
      int humi =(int)(rawhum*100);

      cmd_tab[3]=DEVICE_ID[3];
      cmd_tab[4]=DEVICE_ID[2];
      cmd_tab[5]=DEVICE_ID[1];
      cmd_tab[6]=DEVICE_ID[0];
     
      cmd_tab[7]=temp>>8;
      cmd_tab[8]=temp;
      cmd_tab[9]=humi>>8;
      cmd_tab[10]=humi;
      Serial.write(cmd_tab,11);
      Serial1.write(cmd_tab,11);
}



void setup()
{
  
  hardware_init();


    DEVICE_ID[3]=ADDR>>24;
    DEVICE_ID[2]=ADDR>>16;
    DEVICE_ID[1]=ADDR>>8;
    DEVICE_ID[0]=ADDR;
   



 
}


void loop()
{

 



   Collection_temperature_humidity();



   print_send();

 
  


  delay(5000);

}







