#include <iostream>
#include <chrono>
#include "thread_pool.h"

void fun1()
{
	std::cout << "working in thread " << std::this_thread::get_id() << std::endl;
}

void fun2(int x)
{
	std::cout << "task " << x << " working in thread " << std::this_thread::get_id() << std::endl;
}

int main(int argc, char* argv[])
{
	ThreadPool thread_pool(3);
	thread_pool.start();
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	for (int i = 0; i < 6; i++)
	{
		thread_pool.appendTask(fun1);
		thread_pool.appendTask(std::bind(fun2, i));
		// std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	thread_pool.stop();

	// getchar();
	return 0;
}