#!/usr/bin/env python
# -*- coding: utf-8 -*-

import datetime
import time
import calendar


def showTimezone():
    # TOOD:: You need to implement subclass of datetime.tzinfo for handling timezone
    # With python 3, you can do this using the built-in datetime.timezone object
    pass

def showToday():
    print('{} showToday {}'.format('-'*5, '-'*5))

    print('Unix Time1: %f' % time.time())
    print('Unix Time2: %d' % int(time.time()))
    #print('Unix Time3: %s' % datetime.datetime.now().strftime("%s"))  # python3??


    print(datetime.datetime.now())
    print(datetime.datetime.today())
    print(datetime.datetime.today().isoformat())
    print(datetime.datetime.today().strftime("%Y-%m-%d %H:%M:%S"))

    print("UTC: %s" % datetime.datetime.utcnow().ctime())
    print("JST: %s" % datetime.datetime.today().ctime())
    print("JST: %s" % datetime.datetime.today().strftime("%Y-%m-%d %H:%M:%S"))


"""
@brief Convert from Unix Time to local time.
@param[in] unixtime  A Unix Time
@return              A local time converted from unixtime
"""
def from_unix_time(unixtime):
    return datetime.datetime.fromtimestamp(unixtime)


"""
@brief Convert from local time to Unix Time.
@param[in] localtime  A local time
@return               A Unix Time converted from localtime
"""
def to_unix_time(localtime):
    return int(time.mktime(localtime.timetuple()))


"""
@brief Convert from UTC time to Unix Time.
@param[in] utctime    A local time
@return               A Unix Time converted from UTC time
"""
def to_unix_time_utc(utctime):
    return calendar.timegm(utctime.timetuple())




if __name__ == '__main__':
    print('{} start {}'.format('-'*5, '-'*5))
    showToday()
    showTimezone()

    print('{} Test case 1 {}'.format('-'*5, '-'*5))
    origtime = 1511333444       # 2017-11-22 15:50:44
    ptm = from_unix_time(origtime)
    converted = to_unix_time(ptm)
    if origtime == converted:
        print("Success: %ld = %s" % (origtime, ptm.strftime("%Y-%m-%d %H:%M:%S")))
    else:
        print("Failure: %ld != %s" % (origtime, ptm.strftime("%Y-%m-%d %H:%M:%S")))

