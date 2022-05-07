#!/usr/bin/env python3

from subprocess import Popen, PIPE
from os import urandom
from random import randrange
import hashlib

def sha1(data):
    p = Popen('./sha1', stdin=PIPE, stdout=PIPE)
    return p.communicate(data)[0].decode()

def rdata():
    return bytearray(urandom(randrange(1000)))

def test():
    data = rdata()
    print(len(data))
    print(data)
    hash = sha1(data)
    hash_ = hashlib.sha1(data).hexdigest()
    print(hash)
    print(hash_)
    assert hash == hash_

for _ in range(1000): test()
