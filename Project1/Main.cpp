#include <iostream>
#include <future>
#include <thread>
#include <chrono>
using namespace std;

int asyncTask(int delay)
{
	this_thread::sleep_for(chrono::seconds(delay)); // �Ű�������ŭ �����Ѵ�.
	cout << "�и��� ������ ����! ";
	cout << "�����ð� : " << delay << endl;
	return delay * delay;
}

int main()
{
	int input;
	cin >> input;
	
	future<int> result = async(launch::async, asyncTask, input);
	cout << "�񵿱� �۾� ������. ���ÿ� ���� ������ ����" << endl;

	for (int i = 0; i < input; ++i)
	{
		cout << i + 1 << "�� ���" << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}

	cout << "���� ������ ����!" << endl;
	int resultNum = result.get();
	cout << "����� " << resultNum << endl;
	
	return 0;
}