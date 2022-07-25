#ifndef GDEBUG_H__
#define GDEBUG_H__

//CPP工程
#ifdef __cplusplus
#define G_DEBUG_CPP_EN 1    //是否支持cpp (cout << endl)
#endif

//#define G_NO_DEBUG_OUTPUT
#define G_DEBUG_CPP_EN 1

/************************************************************************/
//调试发送函数
void gDebug(const char *fmt, ...); // C版本

#if G_DEBUG_CPP_EN
#include <string>
struct gxtEndl;             //声明结构体
extern struct gxtEndl endl; //让其它文件能使用endl
class gxtCout               //实现<<运算符重载
{
 public:
  gxtCout &operator<<(gxtEndl &gendl) {
    gDebug("\r\n");
    return *this;
  }
  gxtCout &operator<<(std::string &str) {
    gDebug("%s", str.c_str());
    return *this;
  }
  gxtCout &operator<<(char c) {
    gDebug("%c", c);
    return *this;
  }
  gxtCout &operator<<(const char *str) {
    gDebug("%s", str);
    return *this;
  }
  gxtCout &operator<<(short number) {
    gDebug("%d", number);
    return *this;
  }
  gxtCout &operator<<(int number) {
    gDebug("%d", number);
    return *this;
  }
  gxtCout &operator<<(uint32_t number) {
    gDebug("%d", number);
    return *this;
  }
  gxtCout &operator<<(uint16_t number) {
    gDebug("%d", number);
    return *this;
  }
  gxtCout &operator<<(uint8_t number) {
    gDebug("%d", number);
    return *this;
  }
  gxtCout &operator<<(uint8_t *string) {
    gDebug("%s", string);
    return *this;
  }
  gxtCout &operator<<(char *string) {
    gDebug("%s", string);
    return *this;
  }
  gxtCout &operator<<(long number) {
    gDebug("%d", number);
    return *this;
  }
  gxtCout &operator<<(float number) {
    gDebug("%f", number);
    return *this;
  }
  gxtCout &operator<<(double number) {
    gDebug("%f", number);
    return *this;
  }
};
gxtCout &gDebug(void); //重载函数cpp版本

void gDebug(std::string &str);
void gDebug(char c);
void gDebug(const char *str);
void gDebug(short number);
void gDebug(int number);
void gDebug(uint32_t number);
void gDebug(uint16_t number);
void gDebug(uint8_t number);
//void gDebug(uint8_t *string);
//void gDebug(char *string);
void gDebug(long number);
void gDebug(float number);
void gDebug(double number);

#endif                 // DEBUG-CPP

/****************private*************************************/

#endif // GDEBUG_H__
