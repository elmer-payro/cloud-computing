#include <iostream>

#ifdef _OPENMP
    #include <omp.h>
#else
    #define omp_get_thread_num() 0
#endif

#define N 24
using namespace std;
int tid;
int main()
{
    cout << "Estableciendo cantidad de hilos\n";
    int nHilos;
    cout << "Cuantos hilos quieres trabajar: ";
    cin >> nHilos;

    #ifdef _OPENMP
        omp_set_num_threads(nHilos);
    #endif

    #pragma omp parallel private(tid)
    {
        tid = omp_get_thread_num();
        cout << "El thread: " << tid << "esta en marcha" << std::endl;
        cout << "El thread: " << tid << "ha terminado" << std::endl;
        
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
