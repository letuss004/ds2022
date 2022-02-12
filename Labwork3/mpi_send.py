import os

from mpi4py import MPI

comm = MPI.COMM_SELF

if __name__ == '__main__':
    fp = os.getcwd() + "/transfer.txt"

    with open(fp, 'r') as f:
        data = f.read()
        comm.sendrecv(data, 1)
        f.close()
