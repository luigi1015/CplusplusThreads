#include <iostream>
#include <thread>
#include <mutex> 

std::mutex coutMutex;

void threadFunction( int id )
{
	coutMutex.lock();
	std::cout << "Hello, World " << id << std::endl;
	coutMutex.unlock();
}

int main()
{
	int numThreads = 10;
	
	std::thread t[numThreads];

	for( int i = 0; i < numThreads; i++ )
	{
		t[i] = std::thread(threadFunction, i);
	}
	
	coutMutex.lock();
	std::cout << "Launched the threads.\n";
	coutMutex.unlock();

	for( int i = 0; i < numThreads; i++ )
	{
		t[i].join();
	}
	
	std::cout << "Joined the threads.\n";

	return 0;
}
