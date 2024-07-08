#include <iostream>
#include <future>
#include <thread>
#include <chrono>
using namespace std;

int asyncTask(int delay)
{
	this_thread::sleep_for(chrono::seconds(delay)); // 매개변수만큼 지연한다.
	cout << "분리된 스레드 종료! ";
	cout << "지연시간 : " << delay << endl;
	return delay * delay;
}

int main()
{
	int input;
	cin >> input;
	
	future<int> result = async(launch::async, asyncTask, input);
	cout << "비동기 작업 실행중. 동시에 메인 쓰레드 진행" << endl;

	for (int i = 0; i < input; ++i)
	{
		cout << i + 1 << "초 경과" << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}

	cout << "메인 쓰레드 종료!" << endl;
	int resultNum = result.get();
	cout << "결과값 " << resultNum << endl;
	
	return 0;
}