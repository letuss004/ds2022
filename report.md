<div align="center">

##### Distributed System

# **Report Project: Hybrid centralized and peer-to-peer chat system using MPI**

&nbsp;

**Group: 12**

**University of Science and Technology of Hanoi**

**Lecturer: Dr.Tran Giang Son**

Feb 2022

&nbsp; &nbsp;

## **Group members**

```
Le Anh Tu | BA9-067

Le Duy | BA9-075

Nguyen Ngoc Khiem | 

Ly Anh Kiet | 

Nguyen Van Cuong |
```  

 </div>

## **TABLE OF CONTENTS**

- [I/ Introduction](#intro)
    + [1. What is Flickr](#intro1)
    + [2. Approaches](#intro2)
    + [3. Preparations](#intro3)
        * [a) Software and tools](#intro31)
        * [b) Library](#intro32)

- [II/ Implementation](#implementation)
    + [1. Planing](#implementation1)
    + [2. Database schema](#implementation2)
        * [a) Relationship between tables](#implementation21)
        * [b) Tables functions](#implementation22)
    + [3. Project Architecture](#implementation3)
    + [4. Classes and Packages](#implementation4)

- [III/ Results](#results)
    + [1. Login](#results1)
    + [2. Sign Up](#results2)
    + [3. Hyper Link](#results3)
    + [4. Newsfeed](#results4)
    + [5. Search](#results5)
    + [6. Profile](#results6)

- [IV/ Conclusion](#conclusion)
    + [1. Contribution](#con1)
    + [2. What we have not done](#con2)
    + [3. What we have done](#con3)

## II/ Analysis and Design<a name="anlynsis"></a>

First, we have to do a system analysis because the various tasks involved in conducting the analysis provide an avenue
for finding solutions in the system The overall quality of a system can be easily modified or improved through these
various tasks, and the number of errors can be reduced as a result.<br>
Then the system should satisfy the requirement:

- At least three nodes:
    - One for server
    - Two for client
- A good network
- The port quantity corresponds to the client quantity

With MPI, we can have as many nodes as we want depending on how big our network is. However, there is always a node
whose function is to control all messages from the rest of the nodes and that is the central node or server. The
remaining nodes of the system must be run on different computers or processors connected through a network. Each node (
including the server) must be run as a separate program on different terminal tabs or devices. As is obvious the nodes
must be connected in a stable way.

A port is a virtual point where network connections start and end. Ports are software-based and managed by a computer's
operating system. Each port is associated with a specific process or service. Each port acts as a secure channel so that
the server and client can communicate securely because the port address is randomly generated and sent to the client
very securely via special tags. These ports can be the foundation for later advanced functions such as 1vs1 chat,
private chat, ...


<div align="center">
<img src="images/MIP-P2P-Des.drawio.png" alt="Design"><br>
Figure 1: System Design
</div>

## III/ Implementation <a name="implementation"></a>

### 1. Server side

<div align="center">
<img src="images/MIP-Flowchart.drawio.png" alt="Design"><br>
Figure 2: Server flowchart 
</div>

As for the server, it was born as a central processor of this system. First, the server will randomly open different
ports and send it to a every specific client. Through that address the client can connect to the server and send
information on a secure separate channel. After that, the message will be sent to all clients that have been accepted by
the server

### 2. Client side

<div align="center">
<img src="images/MIP-Flowchart-Client.drawio.png" alt="Design"><br>
Figure 3: Client flowchart 
</div>

Clients or nodes need to connect to the server using the address that was sent at start. A client has two main tasks
executed in parallel. First, the client must be able to send messages and be able to receive messages from other nodes
in parallel.

## IV/ Result

<div align="center">
<img src="images/Screenshot_2022-03-01_01_30_50.png" alt="Design"><br>
Figure 4: Result
</div>

In this project we were not able to execute all of the ideas that were planned in advance because of a number of reasons
that we will clarify in section V. Basically, we have almost done it. As the requirements, the server opens the
ports and the client connects to them. Functions such as receiving messages, sending messages are met.
