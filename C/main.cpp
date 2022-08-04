#include <iostream>
using namespace std;

#include <string>

extern "C" int lfsr(void);

extern "C" int num = 0;
extern "C" int sizen = 0;
extern "C" int lengthn = 0;

int main(){
	
	string str;// ����� ������ � ������� 
	register int key = 0;
	register int key2 = 0;

	cout << "Enter the string: " << endl;// ���������� ������ �� ������� � ���������� 
	getline(cin, str);

	// ����� ��������� 2 ����� � ������� ���� ��������� � ���������� � ���� 

	num = 2;
	sizen = (pow(2, 2) - 1);
	lengthn = 1;

	key = lfsr(); // ������ ����
	key <<= 7; // �������� 11 (3) �� 7 ����� � �������� 110000000

	num = 5;
	sizen = (pow(2, 3) - 1);
	lengthn = 2;

	key2 = lfsr(); // ������ ����
	key |= key2; // ����� � ������� ���(|) ��������� � ������� ����� 1011100 (92), ���������� 111011100 (476)
	key <<= 3; // ���-�� ������ �� 3 ������ ��� �����, ������� ��� ������������ �������� ������������������ ����� ��� �� 3 ������� ��� ��������� ���� ����� � �������� 111011100000

	cout << endl << "cipher: ";

	for (int i = 0; i < str.length(); i++) {
		str[i] ^= key; // xor ������� ������� � ������
		cout << str[i];
	}

	cout << endl << "decipher: ";

	for (int i = 0; i < str.length(); i++) {
		str[i] ^= key;
		cout << str[i];
	}

	cout << endl;

	system("pause");

	return 0;
}