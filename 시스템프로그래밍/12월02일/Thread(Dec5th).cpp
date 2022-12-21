#include <vector>
#include <iostream>
#include <chrono> //타임관련 함수 크로노
#include <thread>
#include <memory>
#include <mutex>
#include <algorithm>

using namespace std;
mutex lk;
vector<int>primes;

bool IsPrimeNumber(int number) {
	if (number == 0 || number == 1)
		return false;
	if (number == 2 || number == 3)
		return true;
	for (int i = 2; i < number - 1; i++)
	{
		if ((number % i) == 0)
			return false;
	}
	return true;
}

void PrintNumbers(const vector<int>& primes) {
	for (auto prime : primes)
		cout << prime << " ";
	cout << endl;
}

void computePrimeNumbers(int offset, int maxCount, int maxThreads)
{
	int count = 0;
	for (int i = offset; i < maxCount; count++)
	{
		if (IsPrimeNumber(i))
		{
			lk.lock();
			primes.push_back(i);
			lk.unlock();
		}
		i = (count + 1) * maxThreads + (offset + count + 1) % maxThreads;
	}
}

int main(void) {
	const int maxCount = 400000;
	const int maxThread = 16;
	auto start = chrono::system_clock::now();

	vector<thread> threads;

	for (int i = 0; i < maxThread; i++)
	{
		threads.push_back(thread(computePrimeNumbers, i, maxCount, maxThread));
	}

	for (int i = 0; i < maxThread; i++)
	{
		threads[i].join();
		auto end = chrono::system_clock::now();
		auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
		cout << "Took " << duration << " milliseconds." << endl;
	}

	sort(primes.begin(), primes.end(), [](auto a, auto b) {return a < b; });
	PrintNumbers(primes);

	return 0;
}