# Introduction to Socket Programming

## We want you to write code to enable a machine M1 (Server.c) to receive text messages from a machine M2 (Client.c) over TCP sockets. Server.c should print these text messages on the standard output. Server.c should then reverse the string and send it back to Client.c. Server.c should be listening for text messages on a port known to Client.c. Client.c should take a text message from stdin – transmit the message, receive the reverse message, print the reversed message on standard output and then exit. 

```
Client code will accept string from the user then it will send it to the server. Client code will also display the reversed string, which it got back from server.

Server code will receive, reverse and return back the string to the client.
```

Notes
    - Client sends to Server
    - Server receives message from client
        - To clarify that the message was received, Server will reverse the string and send it back to client