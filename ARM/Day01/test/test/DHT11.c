#include "lpc11xx.h"
#include "gpio.h"
#include "tools.h"
/* 原理：单总线 （单线双向）
 步骤 1) 上电后等待1s(不稳定)
      2) 主机发送开始信号（PIO1_5输出+低电平+持续大于18ms + PIO1_5输入）
      3) DHT11反馈 80us应答信号+80us准备信号
      4) DHT11发送出40位数据（低电平+高电平），主机能从PIO1_5读取到40位数据
      5）结束信号(DHT11发送50us低电平-->自动转为输入)
      6) 主机校验（前4个 8bit数据相加）== 第5个 8bit校验位 是否相等
*/
/********************************************************
 * 函数名字：DHT11
 * 功能描述：DHT11芯片采集温湿度功能函数
 * 参数：temp : 指针,指向存储温度[整数+小数]数组的首地址
 *       hump : 指针,指向存储湿度[整数+小数]数组的首地址
 * 返回值： 成功 1 ； 出错 0
 ********************************************************/
 int DHT11(uint8_t *temp, uint8_t *hump)
 {
	 uint8_t ucharFlag=2;  //防止死循环的
	 uint8_t data[5] = {0}; //存储读取的40位数据
	 int i, j; 
	 int num0, num1;  // 计数：记录低电平/高点平持续的时间  
	 //1)
	 delay_ms(1000);
	 //2) 开始信号
	 GPIOSetDir(PORT1, 5, 1); //设置PIO1_5 输出方向1
	 GPIOSetValue(PORT1, 5, 0); //低电平 
	 delay_ms(20); //延时>=18ms
	 GPIOSetValue(PORT1, 5, 1);  //高电平
	 GPIOSetDir(PORT1, 5, 0); //设置PIO1_5 输入方向	 
   //等待 拉高电平结束
	 ucharFlag=2;
	 while( GPIOGetValue(PORT1, 5) && ucharFlag++ );
	 if(ucharFlag == 1) //上面循环异常结束
		 return 0;
	 //3) 响应信号0 + 准备信号1
	 ucharFlag=2;
	 while( !GPIOGetValue(PORT1, 5) && ucharFlag++ );
	 if(ucharFlag == 1) //上面循环异常结束
		 return 0;
	 ucharFlag=2;
	 while( GPIOGetValue(PORT1, 5) && ucharFlag++ );
	 if(ucharFlag == 1) //上面循环异常结束
		 return 0;
	 //4) 循环40次读取数据
	 for(i = 0; i < 5; i++){
			for(j = 7; j >=0; j--){  //高位先接收到
					num0 = 0; 
					num1 = 0;
				  ucharFlag=2;
				  while( !GPIOGetValue(PORT1, 5) && ucharFlag++ ) num0++;
				  ucharFlag=2;
					while( GPIOGetValue(PORT1, 5)  && ucharFlag++)  num1++;
				  if(ucharFlag == 1) //上面循环异常结束
		           return 0;
				  if(num1 > num0){ 
						data[i] |= 1<<j;  //对应位-置1
					}
	    }
	 }
	 //5)结束信号
	 ucharFlag=2;
	 while( !GPIOGetValue(PORT1, 5) && ucharFlag++ );
	 //6)校验
	 if(data[0]+data[1]+data[2]+data[3] == data[4])
	 {
		  hump[0] = data[0];
		  hump[1] = data[1];
		  temp[0] = data[2];
		  temp[1] = data[3];
			return 1;
	 }
	 return 0;
 }
 