#include <iostream>
#include <fstream>
#include <string>

//��������� �� ������ ����
void createTextFile(const std::string& stringInputToFile)
{
	std::ofstream fileOut("File.txt"); //����� ���� �� �� ������ ���� �������� �� ���������

	if (fileOut.is_open())
	{
		fileOut << stringInputToFile << std::endl; //������� ��� ����� stringInputToFile � ��������� ��������� �� ��� ���
		//����� �� �� ������� ��� ������ ��� �����
	}
	else
	{
		std::cout << "Unable to open\n";
	}

	fileOut.close();
}

//������� �� ��� �� ������� ����
const std::string getFromTextFile(const char* nameOfFile)
{
	std::string stringFromFile = "";
	std::string line = "";
	std::ifstream fileIn(nameOfFile);

	if (fileIn.is_open())
	{
		while (std::getline(fileIn, line))
		{
			std::cout << line << std::endl;
			stringFromFile = line;
		}
	}
	else
	{
		std::cout << "Unable to open\n";
	}

	fileIn.close();

	return stringFromFile; //�� ����� ���� ��������� ���(��� ��� ����� ��� ������ �� ���� ���)
}

//��������� �� ������� ���� - ���� ������� ���� �� � ������ ��� ��������� �� ������
void createBinaryFile(int number)
{
	std::ofstream fileOut("File.bin", std::ios::binary);

	if (fileOut.is_open())
	{
		fileOut.write((const char*)&number, sizeof(int));
	}
	else
	{
		std::cout << "Unable to open\n";
	}

	fileOut.close();
}

//��������� �� �������� �� ������� ���� - ���� ������� ���� �� � ������ ��� ��������� �� ������
int getFromFile(const char* nameOfFile)
{
	int number = 0;
	std::ifstream fileIn(nameOfFile, std::ios::binary);

	if (fileIn.is_open())
	{
		fileIn.read((char*)&number, sizeof(int));
	}
	else
	{
		std::cout << "Unable to open\n";
	}

	fileIn.close();

	return number;
}

//int main()
//{
//	createTextFile("file test");
//	std::string text = getFromTextFile("File.txt");
//	std::cout << text << std::endl;
//
//	createBinaryFile(8);
//	int number = getFromFile("File.bin");
//	std::cout << number << std::endl;
//
//	return 0;
//}

