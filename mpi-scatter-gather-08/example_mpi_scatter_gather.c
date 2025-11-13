#include<mpi.h>
#include<stdio.h>


int main(int argc, char** argv){

    int rank, size;
    int data[100];
    int recv_val;
    int gathered[100];


    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank==0){

        for (int i=0; i<size; i++){
            data[i] = i*10;
        }

        printf("Process 0 initialized data :");
        for(int i =0; i<size; i++){
            printf("\t%d", data[i]);
        }

        printf("\n");
    }

    MPI_Scatter(data, 1, MPI_INT, &recv_val, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("process %d recieved value %d from Scatter\n", rank, recv_val);

    recv_val += rank;

    MPI_Gather(&recv_val, 1, MPI_INT, gathered, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0){
        printf("Process 0 gathered data:");
        for (int i=0; i<size; i++){
            printf("%d\t", gathered[i]);
        }
        printf("\n");
    }

    MPI_Finalize();
    return 0;

}