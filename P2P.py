import time

import mpi4py.MPI
from mpi4py import MPI

comw = MPI.COMM_WORLD
coms = MPI.COMM_SELF
rank = comw.Get_rank()
size = comw.Get_size()

comm1, comm2 = None, None
port1, port2 = None, None

print("Rank " + str(rank) + " is executed!!!")

# if size < 3:
#     print("Size must > 3")
#     MPI.Finalize()

if rank == 0:
    port1 = MPI.Open_port()
    port2 = MPI.Open_port()
    print("sever open 2 port")
    comw.send(port1, dest=1, tag=10)
    comw.send(port2, dest=2, tag=11)

    comm1 = coms.Accept(port1, MPI.INFO_NULL, root=0)
    comm2 = coms.Accept(port2, MPI.INFO_NULL, root=0)
    comm1.send(2, dest=0, tag=100)
    comm2.send(1, dest=0, tag=111)
    MPI.Close_port(port1)
    MPI.Close_port(port2)
    comm1.Disconnect()
    comm2.Disconnect()
elif rank == 1:
    port_name = comw.recv(source=0, tag=10)
    print("Rank 1, port = ", port_name)
    port1 = coms.Connect(port_name, MPI.INFO_NULL, 0)
    des = port1.recv(source=0, tag=100)

    if des is not None:
        # print("Rank 1 send to rank ", str(des))
        mess = "Hello"
        comw.send(mess, dest=des, tag=22)
        data_recv = comw.recv(source=des, tag=33)
        print("Rank 2 said to rank 1", data_recv)
    port1.Disconnect()
elif rank == 2:
    port_name = comw.recv(source=0, tag=11)
    print("Rank 2, port = " + str(port_name))
    port2 = coms.Connect(port_name, MPI.INFO_NULL, 0)
    des = port2.recv(source=0, tag=111)

    if des is not None:
        # print("Rank 2 send to rank ", str(des))
        mess = "Good byeeeee"
        comw.send(mess, dest=des, tag=33)
        data_recv = comw.recv(source=des, tag=22)
        print("Rank 1 said to rank 2", data_recv)
    port2.Disconnect()

MPI.Finalize()
# comm.Disconnect()
