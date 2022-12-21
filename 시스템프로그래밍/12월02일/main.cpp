#include <vector>
#include <iostream>
#include <chrono> //타임관련 함수 크로노
#include <thread>
#include <memory>
#include <mutex>

using namespace std;
const int MaxCount = 400000;
const int ThreadCount = 4;
mutex lk;
vector<int>primes;

bool IsPrimeNumber(int number) {
	if (number == 1)
		return false;
	if (number == 2 || number == 3)
		return true;
	for (int i = 2; i < number - 1; i++){
		if ((number % i) == 0)
			return false;
	}
	return true;
}

void PrintNumbers(const vector<int>& primes) {
	for (auto prime : primes) {
		cout << prime << " ";
		cout << endl;
	}
}

void func() {
	for (int i = 0; i < MaxCount; i++) {
		if (IsPrimeNumber(i)) {
			lk.lock();
			primes.push_back(i);
			lk.unlock();
		}
	}
}

void func1() {
	for (int i = 0; i < MaxCount; i += 4){
		if (IsPrimeNumber(i)) {
			lk.lock();
			primes.push_back(i);
			lk.unlock();
		}
	}
}

void func2() {
	for (int i = 1; i < MaxCount; i += 4){
		if (IsPrimeNumber(i)) {
			lk.lock();
			primes.push_back(i);
			lk.unlock();
		}
	}
}

void func3() {
	for (int i = 2; i < MaxCount; i += 4){
		if (IsPrimeNumber(i)) {
			lk.lock();
			primes.push_back(i);
			lk.unlock();
		}
	}
}

void func4() {
	for (int i = 3; i < MaxCount; i += 4){
		if (IsPrimeNumber(i)) {
			lk.lock();
			primes.push_back(i);
			lk.unlock();
		}
	}
}

//void func1() {
//	for (int i = 0; i < MaxCount/4; i++){
//		//if (i % 4 == 0)
//			if (IsPrimeNumber(i));
//				//primes.push_back(i);
//	}
//}
//
//void func2() {
//	for (int i = MaxCount/4; i < MaxCount/2; i++){
//		//if (i % 4 == 1)
//			if (IsPrimeNumber(i));
//				//primes.push_back(i);
//	}
//}
//
//void func3() {
//	for (int i = MaxCount/2; i < MaxCount*3/4; i++){
//		//if (i % 4 == 2)
//			if (IsPrimeNumber(i));
//				//primes.push_back(i);
//	}
//}
//
//void func4() {
//	for (int i = MaxCount * 3 / 4; i < MaxCount; i++){
//		//if (i % 4 == 3)
//			if (IsPrimeNumber(i));
//				//cout << i << endl;
//				//primes.push_back(i);
//	}
//}

void main() {
	
	//vector<shared_ptr<thread>>threads;
	auto start = chrono::system_clock::now();

	thread t1(func1);
	thread t2(func2);
	thread t3(func3);
	thread t4(func4);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	/*thread t1(func);
	t1.join();*/

	auto end = chrono::system_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "Took " << duration << " milliseconds." << endl;
	//PrintNumbers(primes);
}