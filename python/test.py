#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import os
import glob
import datetime
import hashlib
import time
import subprocess


def parseStdout(data):
    print('{} parseStdout {}'.format('-'*5, '-'*5))
    for line in data.split(os.linesep):
        checksum = line.split(' ')[0]
        print(checksum)


def subprocessSample(cmd):
    print("start cmd: %s" % cmd)
    proc = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    print("waiting...")
    stdout_data, stderr_data = proc.communicate()
    print("finish: %d %d" % (len(stdout_data), len(stderr_data)))
    print(proc.returncode)
    print(stdout_data)      # added extra blank line at the end
    print(stderr_data)      # added extra blank line at the end
    return proc.returncode, stdout_data, stderr_data

def dictSample():
    print('{} dictSample {}'.format('-'*5, '-'*5))
    ### Test data
    history = [
        ['4.4' , 'KitKat'      , '19'],
        ['5.0' , 'Lollipop'    , '21'],
        ['6.0' , 'Marshmallow' , '23'],
        ['7.0' , 'Nougat'      , '24'],
        ['8.0' , 'Oreo'        , '26'],
    ]
    fields = ['version', 'code_name', 'api_level']

    ### Convert tuple to dict - a simple way
    history1 = []
    for entry in history:
        history1.append({'version':entry[0], 'code_name':entry[1], 'api_level':entry[2]})
    print(history1)

    ### Convert tuple to dict - use zip()
    history2 = []
    for entry in history:
        history2.append(dict(zip(fields, entry)))
    print(history2)


def stopWatch():
    print('{} stopWatch {}'.format('-'*5, '-'*5))
    start = time.time()
    ### Processing very long time.
    for i in range(0, 10000):
        hashlib.sha256("Processing very long time.").hexdigest()
    giffy = time.time() - start
    print('Elapsed time: %0.3f milli-seconds' % (giffy * 1000))


#
# Compute checksum.
#
"""
How to confirm results:
$ echo -n "admin@example.com1234" | md5sum
50d8328dd1d8542850492f6502d59708 *-

$ echo -n "admin@example.com1234" | sha224sum
ef935acf20d9de055dde7ab243051beee54183885fb739d71974f50a *-

$ echo -n "admin@example.com1234" | sha256sum
da46735281d3d5602d62b2749a1f4ef96cebfd34f774f2c1ffc4924055fb1f49 *-
"""
def calcHash():
    print('{} hash {}'.format('-'*5, '-'*5))
    email = "admin@example.com"
    passw = "1234"
    print("Original string: " + email + passw)

    _md5 = hashlib.md5()
    _md5.update(email)
    _md5.update(passw)

    print("MD5.digest: " + _md5.digest())
    print("MD5   : " + _md5.hexdigest())

    checksum = hashlib.sha224(email + passw).hexdigest()
    print("SHA224: " + checksum)

    checksum = hashlib.sha256(email + passw).hexdigest()
    print("SHA256: " + checksum)


def showToday():
    print('{} today {}'.format('-'*5, '-'*5))
    print(datetime.date.today())

    print(datetime.datetime.now())
    print(datetime.datetime.today())
    print(datetime.datetime.today().isoformat())
    print(datetime.datetime.today().strftime("%Y-%m-%d %H:%M:%S"))


def testPathSeparator():
    entries1 = glob.glob(os.path.join('.git', 'hooks', 'pre*')) # work both cygwin and msys
    print(entries1)

    entries2 = glob.glob('.git/hooks/pre*')      # work both cygwin and msys
    print(entries2)

    entries3 = glob.glob('.git\hooks\pre*')      # NOT work cygwin, work msys
    print(entries3)

    entries4 = glob.glob('.git\\hooks\\pre*')     # NOT work cygwin, work msys
    print(entries4)

    entries5 = glob.glob('.git/hooks/pre*'.replace('/', os.sep))  # work both cygwin and msys
    print(entries5)


if __name__ == '__main__':
    print('{} start {}'.format('-'*5, '-'*5))
    testPathSeparator()
    showToday()
    calcHash()
    stopWatch()
    dictSample()
    ret, stdout_data, stderr_data = subprocessSample("md5sum *")
    parseStdout(stdout_data)
    ret, stdout_data, stderr_data = subprocessSample("echo -n 'admin@example.com1234' | md5sum")
    parseStdout(stdout_data)


