
# https://stackoverflow.com/questions/5619685/conversion-from-ip-string-to-integer-and-backward-in-python

#!/usr/bin/env python
import socket
import struct


def ip2int(addr):
    return struct.unpack("!I", socket.inet_aton(addr))[0]


def int2ip(addr):
    return socket.inet_ntoa(struct.pack("!I", addr))


print(int2ip(0xc0a80164)) # 192.168.1.100
print(ip2int('10.0.0.1')) # 167772161


