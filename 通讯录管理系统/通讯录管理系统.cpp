#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

//������ϵ�˽ṹ��
struct Person {
	string m_Name;		//����
	int m_Sex;			//�Ա�   1��  2Ů
	int m_Age;			//����
	string m_Phone;		//�绰
	string m_Addr;		//��ַ

};
//����ͨѶ¼�ṹ��
struct Addressbooks {
	struct Person personArray[MAX]; //ͨѶ¼�б������ϵ������
	int m_Size; //ͨѶ¼����Ա����
};




//�˵�����
//��װ������ʾ�ý���
//��main���÷�װ�õĺ���
void showMenu()
{
	cout << "*******************************" << endl;
	cout << "*******************************" << endl;
	cout << "*****    1�������ϵ��    *****" << endl;
	cout << "*****    2����ʾ��ϵ��    *****" << endl;
	cout << "*****    3��ɾ����ϵ��    *****" << endl;
	cout << "*****    4��������ϵ��    *****" << endl;
	cout << "*****    5���޸���ϵ��    *****" << endl;
	cout << "*****    6�������ϵ��    *****" << endl;
	cout << "*****    0���˳�ͨѶ¼    *****" << endl;
	cout << "*******************************" << endl;
	cout << "*******************************" << endl;
}

//�����ϵ��
void addPerson(Addressbooks *abs)
{
	//�жϵ�ǰͨѶ¼�Ƿ�����
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else {
		//��ʼ�����ϵ��
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1-��" << endl;
		cout << "2-Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			
			cout << "������������������" << endl;
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//�绰
		cout<< "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;


		//��ͥ��ַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼�е�ǰ��Ա����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		//��������
		system("pause");
		system("cls");
	}
}

//��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�е�ǰ��Ա�����Ƿ�Ϊ0
	if (abs->m_Size == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex==1?"��":"Ů" )<< "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "��ϵ�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "��ͥסַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//ɾ����ϵ��
//���ͨѶ¼���Ƿ���ڸ���ϵ��
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
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;

	//���ret==-1����û�в��ҵ���Ҫɾ������ϵ��
	//���ret��=-1�����ҵ�����Ҫɾ������ϵ��
	int ret = isExist(abs, name);
	if (ret!=-1)
	{
		//������������ԣ���ɾ��һ����������Ҫ������ļ���ǰ��
		for (int i = ret; i < abs->m_Size; i++)
		{
			//��ַ�е�����ǰ��
			//�����һ����ַ������ ��ֵ ��ǰ��һ����ַ
			abs->personArray[i] = abs->personArray[i + 1];
		}
		//����ͨѶ¼�е�ǰ��Ա����
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "��ǰͨѶ¼��û�и���ϵ��" << endl;
	}
	//��������
	system("pause");
	system("cls");


}


//������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	
	//�жϴ����Ƿ����
	int ret = isExist(abs, name);
	//���ret==-1����û�в��ҵ���Ҫ���ҵ���ϵ��
	//���ret��=-1�����ҵ�����Ҫ���ҵ���ϵ��
	if (ret!=-1)
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "��ϵ�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "��ͥסַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "��ǰͨѶ¼��û�и���ϵ��" << endl;
	}
	//��������
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	
	//�жϴ����Ƿ����
	int ret = isExist(abs, name);
	//���ret==-1����û�в��ҵ���Ҫ���ҵ���ϵ��
	//���ret��=-1�����ҵ�����Ҫ���ҵ���ϵ��
	if (ret!=-1)
	{
		//�޸�����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//�޸��Ա�
		cout << "�������Ա�" << endl;
		cout << "1-��" << endl;
		cout << "2-Ů" << endl;
		int sex = 0;
		
		while (true)
		{	
			cin >> sex;
			if (sex==1||sex==2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;

		}

		//�޸�����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//�޸���ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = name;

		//�޸ļ�ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "�޸ĳɹ�" << endl;

		
	}
	else
	{
		cout << "��ǰͨѶ¼��û�и���ϵ��" << endl;

	}
	//��������
	system("pause");
	system("cls");
	

}

//�����ϵ��
void cleanPerson(Addressbooks* abs)
{
	if (abs->m_Size>0)
	{
		//����ǰͨѶ¼�е���Ա������Ϊ0
		abs->m_Size = 0;
		cout << "ͨѶ¼�����" << endl;
	}
	else
	{
		cout << "ͨѶ¼��δ�����ϵ�ˣ����ʧ��" << endl;

	}
	//��������
			system("pause");
			system("cls");
}

//�˳�ͨѶ¼


int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;
	int select = 0;//�����û�ѡ������ı���
	
	while (true)
	{
		//�˵�����
		showMenu();

		cin >> select;

		switch (select)
		{
			case 1:  //�����ϵ��
				addPerson(&abs);//���õ�ַ���ݿ��������β�
				break;
			case 2:  //��ʾ��ϵ��
				showPerson(&abs);
				break;
			case 3:  //ɾ����ϵ��
				deletePerson(&abs);
			/*{	
				cout << "��������Ҫɾ����ϵ�˵�������" << endl;
				string name;
				cin >> name;
				if (isExist(&abs, name) == -1)
				{
					cout << "��ǰͨѶ¼��û�и���ϵ��" << endl;
				}
				else
				{
					cout << "�ҵ�" << endl;
				}
				break;
			}*/
			case 4:  //������ϵ��
				findPerson(&abs);
				break;
			case 5:  //�޸���ϵ��
				modifyPerson(&abs);
				break;
			case 6:  //�����ϵ��
				cleanPerson(&abs);
				break;
			case 0:  //�˳�ͨѶ¼
				cout << "��ӭ�´�ʹ��" << endl;
				system("pause");
				return 0;
				break;
			default:
				break;
		}
	
	}
	

	return 0;
}