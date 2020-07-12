# -*- coding:utf-8 -*-
from socketIO_client import SocketIO

def loop(line):
    # time.sleep(0.3)
    if not line:
        line = r.readline()
        loop(line)

socketIO = SocketIO('108.61.127.142', 8083)
lenth = 0
tmp = 0
while (1):
    r = open("pos.txt", 'r')
    str = r.readlines()
    beforelenth = lenth
    lenth = len(str)
    if (beforelenth != lenth):
        for i in range(tmp, lenth):
            tmp = i + 1
            x, y = str[i].strip().split(',')
            socketIO.emit('setPos', x + ',' + y)
            print(x, y)
    r.close()