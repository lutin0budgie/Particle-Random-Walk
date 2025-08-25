#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

int main() {
  int Ns[5] = {10, 100, 1000, 10000, 100000};
  int M = 10;


  std::srand(std::time(nullptr)); //random seed


  for ( int i = 0; i < 5; ++i){
    int N = Ns[i];

      for (int trial = 1; trial <= M; ++trial){
        int pos = 0;

        //timer starts 

        auto start = std::chrono::high_resolution_clock::now();

        for (int step = 0; step < N ; ++step){
          int coin = std::rand() % 2;
          if (coin == 0){
            pos--;
          }else{
            pos++;
          }
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        auto timeTaken = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();

        std::cout<<"Steps (N): "<< N
        << " | Trial (M): " << trial
        << " | Final Position (D): " << pos
        << " | Time (nanoseconds): " << timeTaken << std::endl;

      }
  }

  return 0;


}
