#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

//创建联系人结构体
struct Person {
	string m_Name;		//姓名
	int m_Sex;			//性别   1男  2女
	int m_Age;			//年龄
	string m_Phone;		//电话
	string m_Addr;		//地址

};
//创建通讯录结构体
struct Addressbooks {
	struct Person personArray[MAX]; //通讯录中保存的联系人数组
	int m_Size; //通讯录中人员个数
};




//菜单界面
//封装函数显示该界面
//在main调用封装好的函数
void showMenu()
{
	cout << "*******************************" << endl;
	cout << "*******************************" << endl;
	cout << "*****    1、添加联系人    *****" << endl;
	cout << "*****    2、显示联系人    *****" << endl;
	cout << "*****    3、删除联系人    *****" << endl;
	cout << "*****    4、查找联系人    *****" << endl;
	cout << "*****    5、修改联系人    *****" << endl;
	cout << "*****    6、清空联系人    *****" << endl;
	cout << "*****    0、退出通讯录    *****" << endl;
	cout << "*******************************" << endl;
	cout << "*******************************" << endl;
}

//添加联系人
void addPerson(Addressbooks *abs)
{
	//判断当前通讯录是否已满
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else {
		//开始添加联系人
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1-男" << endl;
		cout << "2-女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			
			cout << "输入有误，请重新输入" << endl;
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		cout<< "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;


		//家庭地址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录中当前人员个数
		abs->m_Size++;
		cout << "添加成功" << endl;
		//清屏操作
		system("pause");
		system("cls");
	}
}

//显示联系人
void showPerson(Addressbooks* abs)
{
	//判断通讯录中当前人员个数是否为0
	if (abs->m_Size == 0)
	{
		cout << "当前通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex==1?"男":"女" )<< "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "联系电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "家庭住址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//删除联系人
//检测通讯录中是否存在该联系人
int isExist(Addressbooks* abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
	
}
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;

	//如果ret==-1就是没有查找到需要删除的联系人
	//如果ret！=-1就是找到了需要删除的联系人
	int ret = isExist(abs, name);
	if (ret!=-1)
	{
		//由于数组的特性，再删除一个检索后，需要将后面的检索前移
		for (int i = ret; i < abs->m_Size; i++)
		{
			//地址中的数据前移
			//令后面一个地址的数据 赋值 给前面一个地址
			abs->personArray[i] = abs->personArray[i + 1];
		}
		//更新通讯录中当前人员个数
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "当前通讯录中没有该联系人" << endl;
	}
	//清屏操作
	system("pause");
	system("cls");


}


//查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	
	//判断此人是否存在
	int ret = isExist(abs, name);
	//如果ret==-1就是没有查找到需要查找的联系人
	//如果ret！=-1就是找到了需要查找的联系人
	if (ret!=-1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "联系电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "家庭住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "当前通讯录中没有该联系人" << endl;
	}
	//清屏操作
	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;
	
	//判断此人是否存在
	int ret = isExist(abs, name);
	//如果ret==-1就是没有查找到需要查找的联系人
	//如果ret！=-1就是找到了需要查找的联系人
	if (ret!=-1)
	{
		//修改姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//修改性别
		cout << "请输入性别：" << endl;
		cout << "1-男" << endl;
		cout << "2-女" << endl;
		int sex = 0;
		
		while (true)
		{	
			cin >> sex;
			if (sex==1||sex==2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;

		}

		//修改年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//修改联系电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = name;

		//修改家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改成功" << endl;

		
	}
	else
	{
		cout << "当前通讯录中没有该联系人" << endl;

	}
	//清屏操作
	system("pause");
	system("cls");
	

}

//清空联系人
void cleanPerson(Addressbooks* abs)
{
	if (abs->m_Size>0)
	{
		//将当前通讯录中的人员个数置为0
		abs->m_Size = 0;
		cout << "通讯录已清空" << endl;
	}
	else
	{
		cout << "通讯录中未添加联系人，清空失败" << endl;

	}
	//清屏操作
			system("pause");
			system("cls");
}

//退出通讯录


int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;
	int select = 0;//创建用户选择输入的变量
	
	while (true)
	{
		//菜单调用
		showMenu();

		cin >> select;

		switch (select)
		{
			case 1:  //添加联系人
				addPerson(&abs);//利用地址传递可以修饰形参
				break;
			case 2:  //显示联系人
				showPerson(&abs);
				break;
			case 3:  //删除联系人
				deletePerson(&abs);
			/*{	
				cout << "请输入想要删除联系人的姓名：" << endl;
				string name;
				cin >> name;
				if (isExist(&abs, name) == -1)
				{
					cout << "当前通讯录中没有该联系人" << endl;
				}
				else
				{
					cout << "找到" << endl;
				}
				break;
			}*/
			case 4:  //查找联系人
				findPerson(&abs);
				break;
			case 5:  //修改联系人
				modifyPerson(&abs);
				break;
			case 6:  //清空联系人
				cleanPerson(&abs);
				break;
			case 0:  //退出通讯录
				cout << "欢迎下次使用" << endl;
				system("pause");
				return 0;
				break;
			default:
				break;
		}
	
	}
	

	return 0;
}