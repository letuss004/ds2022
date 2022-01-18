<div align="center">

Distributed System

# **Labwork 1 Report**

&nbsp;

**Group: 12**

**University of Science and Technology of Hanoi**

Lecturer: Dr.Tran Giang Son

## **Group members**

```
Lê Anh Tú

Lý Anh Kiệt

Nguyễn Ngọc Khiêm

Nguyễn Văn Cường

Lê Duy
```

 </div>

## 1/ System design

### 1.1/ Client

#### 1.1.1/ Create socket

&ensp;&ensp;&ensp;In client, I have declared socket as ss variable by call function socket (sys/socket.h lib).

```c
int server = socket(AF_INET, SOCK_STREAM, 0);
```

With AF_INET, SOCK_STREAM and 0 as parameters corresponding to domain, type, protocol:

- **AF_INET** is an address family that is used to communicate with Internet Protocol v4 addresses
- **SOCK_STREAM** this means connection oriented TCP protocol
- **0** Protocol value for Internet Protocol(IP), which is 0

#### 1.1.2/ Initialize address

```c
address.sin_family = AF_INET;
address.sin_addr = *(struct in_addr *) hep->h_addr_list[0];
address.sin_port = htons(12345);
```

The address is an instance "sockaddr_in" of describing an Internet socket address:

- **address.sin_addr** is used to locate internet address
- **address.sin_port** define port which server use

#### 1.1.3/ Connecting

```c
connect(server, (struct sockaddr *) &address, address_length);
```

Simply connect client to server by calling connect()

#### 1.1.4/ Sending

```c
    send_file(file, server);
```

Use file and server variable to send the file (currently named file.txt) to server by a method call send_file()

### 1.2/ Server side

#### 1.2.1/ Preparing

&ensp;&ensp;&ensp;Socket and address are required to be the same with client.

### 1.2.2/ Listening

```c
listen(ss, 0);
```

Prepare to accept connections on server. With N=0, no connection requests will be queued before further requests are
refused.

### 1.2.3/ Receiving

```c
    while (1) {
cli = accept(ss, (struct sockaddr *) &ad, &ad_length);
pid = fork();
if (pid == 0) {
printf("client connected\n");
write_file(cli);
return 0;
} else {
continue;
}
}
```

Accept function is called to receive connection from client whenever the cline is turn on. To let server can receive
anytime I put accept() on an infinity loop. Then an if statement will consider whether the file is written or not.

### 2/ Figure
