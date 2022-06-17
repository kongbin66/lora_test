#include "m_config.h"
/*******************************************

函数名称：Float2Byte

功 能：浮点数转换成字节型数组

参 数：入口参数floatNum，欲转换的浮点数

返 回 值：byteArry，转换后的字节数组

********************************************/

void Float2Byte(float floatNum,unsigned char* byteArry)

{

char* pchar=(char*)&floatNum;

for(int i=0;i<4;i++)

{

*byteArry=*pchar;

pchar++;

byteArry++;

}

}

/*******************************************

函数名称：Byte2Float

功 能：字节型（16进制格式）转换成浮点数

参 数：入口参数*byteArry，转换成的字节数组，每四个字节转换成一个单精度浮点数

返 回 值：转换后的浮点数

********************************************/

float Byte2Float(unsigned char* byteArry)

{

return *((float*)byteArry);

}


void test(float i)
{
  uint8_t j=0;
  float ccc;
  unsigned char array1[4];
  

  Serial.printf("value=%f\r\n",i);
  Serial.printf("size=%d\r\n",sizeof(i));

  Float2Byte(i,array1);//浮点转数组
  
  //打印数组
  for(j=0;j<4;j++)
  {
    Serial.printf("%d,",array1[j]);
    
    delay(500);
  }
  Serial.println();

  //数组转浮点
  ccc= Byte2Float(array1);
  Serial.printf("charge float=%f\r\n",ccc);

}

// //################################################################

// // 函数名：void Float2Char(float Value,char *array)

// // 描 述：将浮点数的各个位的数值转换成字符串，通过串口发送至上位机显示

// // 参 数：float Value为欲转换的正数浮点数值，转换结果保存在字符数组*array里

// //################################################################

// void Float2Char(float Value,char *array) 

// {

//  uint16_t  IntegerPart;

//  float DecimalPart;

//  uint16_t i = 0;

//  uint16_t j = 0;

//  char temp;

//  //分离整数部分与小数部分：

//  //整数部分保存在IntegerPart中

//  //小数部分保存在DecimalPart中

//  if (Value>=1)

//  {

//  IntegerPart = (uint16_t)Value;

//  DecimalPart = Value-IntegerPart;

//  }

//  else 

//  {

//  IntegerPart = 0;

//  DecimalPart = Value-IntegerPart;

 
//  //转换整数部分

//  if (IntegerPart == 0)

//  {

//  array[0] = 0+48;

//  array[1] = '.';

//  i = 1;

//  }

//  else

//  {

//  while(IntegerPart>0)

//  {

//  array[i] = IntegerPart%10+48;

//  IntegerPart = IntegerPart/10;

//  i++;

//  }

//  i--;

//  //修正转换结果的顺序

//  for (j=0;j<100;j++)

// {

// temp = array[j];

// array[j] = array[i-j];

// array[i-j] = temp;

// }

// i++;

// array[i] = '.';

// }

// //转换小数部分，此处设置最多转换到第四位小数

// i++;

// array[i++] = (uint16_t)(DecimalPart*10)%10+48;

// array[i++] = (uint16_t)(DecimalPart*100)%10+48;

// array[i++] = (uint16_t)(DecimalPart*1000)%10+48;

// if (5 == i)

// array[i++] = (uint16_t)(DecimalPart*1000)%10+48;

// array[i] = '\0'; //结束符

// }
// }
