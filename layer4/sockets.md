| Feature          | `SOCK_STREAM`                   | `SOCK_DGRAM`             |
| ---------------- | ------------------------------- | ------------------------ |
| Connection type  | Connection-oriented             | Connectionless           |
| Typical protocol | TCP                             | UDP                      |
| Data type        | Continuous byte stream          | Discrete messages        |
| Delivery         | Reliable & ordered              | Unreliable, may reorder  |
| Functions        | `connect()`, `send()`, `recv()` | `sendto()`, `recvfrom()` |
