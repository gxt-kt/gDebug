# This repository has been abandoned.
# Please see the new version v2.0 https://github.com/gxt-kt/gDebugV2.0
***
# gDebug
write a debug lib to replace the self-contained printf/cout

GXT-发送驱动包

 * 重写了printf函数--gDebug()
 * 重写了cout<<endl--gDebug()
 * 方便移植，提供重写函数

## 使用前必须做的：

由于使用gDebug()最终都会调用gDebugSendString(弱定义)发送，所以我们需要
重写函数 **void gDebugSendString(const char *str, int num)**

例：

```c++
void gDebugSendString(const char *str, int num)
{
     // C/C++
     printf("%.*s", num, str);
     
     // stm32
     CDC_Transmit_FS((uint8_t*)str,num); // 调用 USB CDC函数发送数据
     HAL_UART_Transmit(&huart1,(uint8_t *)str,num,0xFFFF);//hal库发送数据

     // Arduino
     Serial.write(str,num);
}
```

##  使用示例

```c++
 void loop()
 {
     gDebug("hello world\n");
     gDebug()<< "hello" << "world" <<endl;
     delay(500);
 }
```

## 额外的：

当我们想要禁用debug时，可以定义宏`G_NO_DEBUG_OUTPUT`
