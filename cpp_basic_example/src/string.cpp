#include <cstring>
#include <iostream>

void string_example() {
  using std::cout;
  using std::endl;
  cout << "string example" << endl;

  char site[] = "RUNOOB";
  char str1[13] = "runoob";
  char str2[13] = "google";
  char str3[13];
  int len;

  // 复制 str1 到 str3
  strcpy(str3, str1);
  cout << "strcpy(str3, str1) : " << str3 << endl;

  // 连接 str1 和 str2
  strcat(str1, str2);
  cout << "strcat(str1, str2): " << str1 << endl;

  // 连接后，str1 的总长度
  len = strlen(str1);
  cout << "strlen(str1) : " << len << endl;
}