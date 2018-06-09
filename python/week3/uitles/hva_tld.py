import sys, os
import csv
import bisect
import logging

from hva_pckt import IpAddress

notice = \
    """ This site or product includes IP2Location LITE data available from http://www.ip2location.com."""

class TldDb:
    """ Return the toplevel domain for a ip-address """

    class TldRow:
        """ A local class to hold the row-information """
        def __init__(self, row):
            self.fst = IpAddress(int(row[0]))
            self.lst = IpAddress(int(row[1]))
            self.tld = row[2]
            self.country = row[3]

        def __lt__(self, ipOrRow):
            """ The IpAddress-case is needed for bisect """
            if isinstance(ipOrRow, IpAddress):
                return self.fst < ipOrRow
            elif isinstance(ipOrRow, TldDb.TldRow):
                return self.fst < ipOrRow.fst
            assert False

        def __str__(self):
            return '<TldRow fst={0:15s}, lst={1:15s}, tld={2:3s}, country={3:s}>'.format(
                    str(self.fst), str(self.lst), self.tld, self.country)
    
    def __init__(self, fname=None):
        self._db = []
        if fname: self.load(fname)
        self.log = logging.getLogger(__name__)

    def load(self, fname=None):
        """ Load csv-file into database """
        if fname is None: fname = "tld.csv"
        with open(fname, 'r') as fp:
            for row in csv.reader(fp):
                self._db.append(self.TldRow(row))
        self._db.sort()
        self.log.info('Load from file=%s, %d-recs', fname, len(self._db))

    def save(self, fname):
        """ Save database into csv-file """
        with open(fname, 'w') as fp:
            wtr = csv.writer(fp, quotechar='"', quoting=csv.QUOTE_ALL)
            for row in self._db:
                wtr.writerow((int(row.fst), int(row.lst), row.tld, row.country))
        self.log.info('Save to file=%s, %d-recs', fname, len(self._db))
    
    def findRow(self, ip):
        if not isinstance(ip, IpAddress): ip = IpAddress(ip)
        i = bisect.bisect_left(self._db, ip)
        if i == -1: i += 1
        elif i == len(self._db): i -= 1
        elif self._db[i].fst != ip: i -= 1
        row = self._db[i]
        self.log.debug('findRow: %5d ip=%s, row=%s', i, ip, row)
        assert row.fst <= ip <= row.lst
        return row

    def findTld(self, ip):
        row = self.findRow(ip)
        return row.tld



if __name__ == '__main__':

    logging.basicConfig()
    log = logging.getLogger()

    if sys.argv[-1] == '-D':
        log.setLevel(logging.DEBUG)

    tldDb = TldDb()
    tldDb.load()
    tldDb.save('tld2.csv')
    # NL X|support
    res = tldDb.findRow('80.127.107.107')
    print(str(res))
    res = tldDb.findRow('10.0.0.1')
    print(str(res))
    res = tldDb.findRow('10.255.255.254')
    print(str(res))
    res = tldDb.findRow('0.0.0.0')
    print(str(res))
    res = tldDb.findRow('0.0.0.1')
    print(str(res))
    res = tldDb.findRow('255.255.255.254')
    print(str(res))
    res = tldDb.findRow('255.255.255.255')
    print(str(res))
    # BE
    res = tldDb.findRow(1743020288)
    print(str(res))
    res = tldDb.findRow(1743020315)
    print(str(res))
    res = tldDb.findRow(1743020543)
    print(str(res))

