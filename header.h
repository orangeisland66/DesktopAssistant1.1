#pragma once
#pragma warning(disable:4267)
#pragma warning(disable:4244)

#ifdef UNICODE
#undef UNICODE
#endif

#include<Windows.h>
#include<fstream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<iostream>
#include<sstream>
#include"Template.hpp"
#include<conio.h>
#include<easyx.h>
#include<stdlib.h>
#include<map>
#include<io.h>
using namespace std;//由于没有使用重名变量或函数，就直接把命名空间和所有头文件放在一起了