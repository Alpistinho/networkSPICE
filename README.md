# networkSPICE
A distributed SPICE circuit simulator

Just a simple app to do distributed Monte Carlo circuit simulations

Using ZeroMQ, Protocol Buffer and my own SPICE library

## Compiling

Clone the repository

```
$ cmake CMakeLists.txt
$ make
```

## Dependencies

It depends on zeromq and the Protocol Buffer libraries.

Protobuf compiler (protoc) needs to be installed.
