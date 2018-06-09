#/usr/bin/env python3
# (c) 2018 Frans Schippers f.h.schippers@hva.nl
# Packet decoder
import struct

class MacAddress:
    def __init__(self, data):
        if isinstance(data, bytes):
            assert len(data) == 6
            self.data = data
        elif isinstance(data, str):
            assert len(data) == 17
            self.data = struct.pack('!BBBBBB', *[ int(i, 16) for i in data.split(':')])
        else:
            assert False, repr(data)

    def __str__(self):
        # Note: type(b) == int
        return ':'.join([ '{0:02x}'.format(b) for b in self.data ])

class IpAddress:
    def __init__(self, data):
        if isinstance(data, bytes):
            assert len(data) == 4, repr(data)
            self.data = data
        elif isinstance(data, str):
            assert 7 <= len(data) <= 15
            self.data = struct.pack('!BBBB', *[ int(i) for i in data.split('.')])
        elif isinstance(data, int):
            self.data = struct.pack('!I', data)
        else:
            assert False, repr(data)

    def __str__(self):
        # Note: type(b) == int
        return '.'.join([ '{0:d}'.format(b) for b in self.data ]) 

    def __int__(self):
        return struct.unpack('!I', self.data)[0]

    def __lt__(self, other):
        return self.data < other.data

    def __eq__(self, other):
        return self.data == other.data

    def __le__(self, other):
        return self.data <= other.data

class IpPort:
    pass # TODO

class Eth:
    @classmethod
    def decode(cls, data):
        self = Eth()
        _eth = struct.unpack('!6s6sH', data[:14])
        if len(_eth) != 3:
            raise Exception('Eth: unable to decode {}'.format(repr(data[:14])))
        self.smac = MacAddress(_eth[0])
        self.dmac = MacAddress(_eth[1])
        self.typ = _eth[2]
        self.pl = data[14:]
        if self.typ not in [ 0x0800 ]: return None
        return self

    def __str__(self):
        return '<Eth smac=%s, dmac=%s, typ=%04x, len=%d>'%(self.smac, self.dmac, self.typ, len(self.pl))


class Ip:
    kProto_TCP = 0x06 #  6
    kProto_UDP = 0x11 # 17
    @classmethod
    def decode(cls, data):
        self = Ip()
        _ip = struct.unpack('!BBHHHBBH4s4s', data[:20])
        if len(_ip ) != 10:
            raise Exception('Ip: unable to decode {}'.format(repr(data[:20])))
        self.vrs = (_ip[0] >> 4) & 0x0F
        self.hdrlen = ((_ip[0] >> 0) & 0x0F) * 4
        self.dscp = (_ip[1] >> 0) & 0x3F
        self.ecn = (_ip[1] >> 6)& 0x03
        self.pcklen = _ip[2]
        self.id = _ip[3]
        self.flgs = (_ip[4] >> 13) & 0x07
        self.frgoff = _ip[4] & 0x1FFF
        self.ttl = _ip[5]
        self.proto = _ip[6]
        self.hdrcksm = _ip[7]
        self.saddr = IpAddress(_ip[ 8])
        self.daddr = IpAddress(_ip[ 9])
        self.opts = data[20:self.hdrlen-20]
        self.pl = data[self.hdrlen:]
        if self.vrs != 4: return None
        return self

    def __str__(self):
        return '<Ip vrs=%d, hdrlen=%d, dscp=0x%02x, ecn=0x%1x, pcklen=%d, id=%d, flgs=0x%1x, frgoff=%d, ttl=%d, proto=%d, hdrcksm=%d, saddr=%s, daddr=%s, optlen=%d, len=%d>'%(
                self.vrs, self.hdrlen, self.dscp, self.ecn, self.pcklen,
                self.id, self.flgs, self.frgoff,
                self.ttl, self.proto, self.hdrcksm,
                self.saddr, self.daddr, len(self.opts), len(self.pl))


class Tcp:
    kFlags_FIN = 0x001
    kFlags_SYN = 0x002
    kFlags_RST = 0x008
    kFlags_PSH = 0x008
    kFlags_ACK = 0x010
    kFlags_URG = 0x020
    kFlags_ECE = 0x040
    kFlags_CWR = 0x080
    kFlags_NS  = 0x180
    @classmethod
    def decode(cls, data):
        self = Tcp()
        _tcp = struct.unpack('!HHIIHHHH', data[:20])
        if len(_tcp ) != 8:
            raise Exception('Tcp: unable to decode {}'.format(repr(data[:20])))
        self.sport = _tcp[0]
        self.dport = _tcp[1]
        self.seq =_tcp[2]
        self.ack =_tcp[3]
        self.hdrlen = ((_tcp[4] >> 12) & 0x000F) * 4    # Todo Check
        self.flgs = _tcp[4] & 0x01FF                    # Todo Check
        self.winsiz = _tcp[5]
        self.cksm = _tcp[6]
        self.urg = _tcp[7]
        self.opts = data[20:self.hdrlen]
        self.pl = data[self.hdrlen:]
        return self

    def __str__(self):
        return '<Tcp sport=%d, dport=%d, seq=%d, ack=%d, hdrlen=%d, flgs=0x%03x, winsiz=%d, cksm=%d, urg=%d, optlen=%d, len=%d>'%(
                self.sport, self.dport,
                self.seq, self.ack, self.hdrlen, self.flgs,
                self.winsiz, self.cksm, self.urg,
                len(self.opts), len(self.pl))


class Udp:
    pass # TODO


if __name__ == '__main__':
    import hva_pcap as pcap

    rdr = pcap.open_offline('xsupport.pcap')
    for hdr, data in rdr:
        print(hdr)
        eth = Eth.decode(data)
        if eth is None: continue
        print(str(eth))
        ip = Ip.decode(eth.pl)
        if ip is None: continue
        print(str(ip))
        tcp = Tcp.decode(ip.pl)
        if tcp is None: continue
        print(str(tcp))
        print(repr(tcp.pl))
        break
