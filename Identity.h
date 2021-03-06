#pragma once
#include <iostream>
#include<string>
using namespace std;

//身份基类——纯虚抽象类不能够被实例化的（只能被继承）https://blog.csdn.net/FX677588/article/details/77727110
class Identity {
public:
	//操作菜单 纯虚函数——————————————————————父类只提供声明，不提供实现，实现由子类去完成。
	//每个子类都有自己单独的操作菜单
	virtual void operMenu() = 0;

	string m_Name;//密码
	string m_Password;//密码
};
