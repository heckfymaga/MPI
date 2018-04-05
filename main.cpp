#include <iostream>
#include "mpi.h"

using namespace std;

void Task1(int argc, char **argv){
    int ProcNum, ProcRank, RecRank;
    MPI_Status Status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
    if(ProcRank == 0) {
        printf("Hello world from process %d\n", ProcRank);
        for (int i = 1; i<ProcNum; i++) {
            MPI_Recv(&RecRank, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &Status);
            printf("Hello world from process %d\n", RecRank);
        }
    } else{
        MPI_Send(&ProcRank, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
}
void Task2(int argc, char **argv){
    int a[100], TotalMax, ProcMax = 0;
    int ProcRank, ProcNum, N = 100;
    MPI_Status Status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);

    if(ProcRank == 0){
        for(int i=0;i<N;i++){
            a[i] = i;
        }
    }
    MPI_Bcast(a, N, MPI_INT, 0, MPI_COMM_WORLD);
    int k = N / ProcNum;
    int i1 = k * (ProcRank);
    int i2 = k * (ProcRank + 1);
    if(ProcRank == ProcNum - 1) i2 = N;
    for(int i=i1; i<i2;i++){
        if(ProcMax < a[i]) ProcMax = a[i];
    }
    if(ProcRank == 0){
        TotalMax = ProcMax;
        for(int i=1; i<ProcNum;i++){
            MPI_Recv(&ProcMax, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &Status);
            if(ProcMax > TotalMax) TotalMax = ProcMax;
        }
    }
    else{
        MPI_Send(&ProcMax, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if(ProcRank == 0){
        printf("Max = %d\n", TotalMax);
    }
}
void Task3(int argc, char **argv){

}

int main(int argc, char **argv) {
    Task2(argc, argv);
    cout << random( );
    return 0;
}