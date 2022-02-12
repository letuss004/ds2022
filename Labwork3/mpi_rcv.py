import os
import time
from mpi4py import MPI

comm = MPI.COMM_SELF

if __name__ == '__main__':
    dest_p = os.getcwd() + "/rcv.txt"

    while True:
        rank = comm.Get_rank()
        if rank == 1:
            data = comm.recv()
            with open(dest_p, 'w') as f:
                f.write(data)
                f.close()
            print("SV received file. Die")
            break
        else:
            print("SV is listening")
            time.sleep(0.1)
        pass
