#include <stdio.h>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int turn = 1; 

void thread1 (){
	 {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return turn == 1; });
        printf("thread1\n");
        turn = 2;
    }
    cv.notify_all();

}
void thread2 (){

	 {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return turn == 2; });
        printf("thread2\n");
        turn = 3;
    }
    cv.notify_all();
}
void thread3 (){

	{
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return turn == 3; });
        printf("thread3\n");
    }
    cv.notify_all();
}
int main(){

	std::thread th1(thread1);
	std::thread th2(thread2);
	std::thread th3(thread3);

	th1.join();
	th2.join();
	th3.join();

	return 0;
}