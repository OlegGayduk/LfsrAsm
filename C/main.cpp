#include <iostream>
using namespace std;

#include <string>

extern "C" int lfsr(void);

extern "C" int num = 0;
extern "C" int sizen = 0;
extern "C" int lengthn = 0;

int main(){
	
	string str;// вывод строки в консоль 
	register int key = 0;
	register int key2 = 0;

	cout << "Enter the string: " << endl;// считывание строки из консоли в переменную 
	getline(cin, str);

	// далее вычисляем 2 ключа с помощью двух регистров и объединяем в один 

	num = 2;
	sizen = (pow(2, 2) - 1);
	lengthn = 1;

	key = lfsr(); // первый ключ
	key <<= 7; // сдвигаем 11 (3) на 7 влево и получаем 110000000

	num = 5;
	sizen = (pow(2, 3) - 1);
	lengthn = 2;

	key2 = lfsr(); // второй ключ
	key |= key2; // затем с помощью ИЛИ(|) добавляем к первому ключу 1011100 (92), получается 111011100 (476)
	key <<= 3; // кол-во единиц на 3 больше чем нулей, поэтому для балансировки сдвигаем последовательность влево еще на 3 позиции для получение трех нулей и получаем 111011100000

	cout << endl << "cipher: ";

	for (int i = 0; i < str.length(); i++) {
		str[i] ^= key; // xor каждого символа с ключем
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