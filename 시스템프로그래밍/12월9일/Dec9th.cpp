#include <vector>
#include <iostream>
#include <chrono> 
#include <thread>
#include <memory>
#include <mutex>
#include <algorithm>

using namespace std;

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

//void computePrimeNumbers(int offset, int maxCount, int maxThreads, vector<int>* primes, mutex* lk)
//{
//	int count = 0;
//	for (int i = offset; i < maxCount; count++)
//	{
//		if (IsPrimeNumber(i))
//		{
//			lk->lock();
//			primes->push_back(i);
//			lk->unlock();
//		}
//		i = (count + 1) * maxThreads + (offset + count + 1) % maxThreads;
//	}
//}

void computePrimeNumbers(int offset, int maxCount, int maxThreads, vector<int> &primes, mutex &lk)
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

void thread_main(int val1, int val2) {
	cout << "[" << this_thread::get_id() << "]" << val1 << ", " << val2 << endl;
}

void simple_counter(int* count) {
	for (int i = 0; i < 10000; i++)
	{
		*count = *count + 1;
	}
}
int main(void) {

	//vector<thread> ts;
	//int counts[5];
	//for (auto& count : counts) count = 0;

	//for (int i = 0; i < 5; i++)
	//	//ts.push_back(thread(thread_main, i, i + 20));
	//	ts.push_back(thread(simple_counter, &counts[i]));


	//for (int i = 0; i < 5; i++)
	//	ts[i].join();

	//int totalCounts = 0;
	//for (auto count : counts) totalCounts += count;

	//cout << totalCounts << endl;

	const int maxCount = 400000;
	const int maxThread = 16;
	auto start = chrono::system_clock::now();

	vector<thread> threads;
	vector<int> primes;
	mutex lk;

	for (int i = 0; i < maxThread; i++)
	{
		//threads.push_back(thread(computePrimeNumbers, i, maxCount, maxThread, &primes, &lk));
		threads.push_back(thread(computePrimeNumbers, i, maxCount, maxThread, ref(primes), ref(lk)));
	}

	for (int i = 0; i < maxThread; i++)
	{
		threads[i].join();
		auto end = chrono::system_clock::now();
		auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
		cout << "Took " << duration << " milliseconds." << endl;
	}

	sort(primes.begin(), primes.end(), [](auto a, auto b) {return a < b; });
	//PrintNumbers(primes);

	return 0;
}