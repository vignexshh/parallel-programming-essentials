#include<mpi.h>
#include<stdio.h>

#include<string.h>

int main(int argc, char** argv){

    int rank, size;
    MPI_Status status;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0){
        for (int i = 1; i < size; i++){
            char message[100];
            sprintf(message, "Hello from process 0 to %d process\n", i);
            MPI_Send(message, strlen(message)+1, MPI_CHAR, i, 0, MPI_COMM_WORLD);
            printf("---------- sender -----------\n");
            printf("Process 0 sent message to process %d\n", i);

        }
    } else {

        char recv_buffer[100];
        MPI_Recv(recv_buffer, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);
        printf("---------- reciever -----------\n");
        printf("Process %d recieved message %s\n", rank, recv_buffer);

    }

    MPI_Finalize();
    return 0;

}