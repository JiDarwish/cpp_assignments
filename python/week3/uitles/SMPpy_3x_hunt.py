import sys, os
import getopt
import logging
import hva_pcap
import hva_pckt
import hva_tld

if __name__ == '__main__':
    pcapFname = 'xsupport.pcap'
    tldFname = None

    log = logging.getLogger()

    opts, args = getopt.getopt(sys.argv[1:], '?VDf:l:', ['tldCsv='])
    for opt, arg in opts:
        if opt == '-?':
            print('Usage: {} [-?VD] [-f <file.pcap> ][ --tldCsv <tld.csv ]'.format(sys.argv[0]))
            print('\t-f {}'.format(pcapFname))
            print('\t--tldCsv {}'.format(tldFname))
            sys.exit()
        elif opt == '-V': log.setLevel(logging.INFO)
        elif opt == '-D': log.setLevel(logging.DEBUG)
        elif opt == '-f': pcapFname = arg
        elif opt == '--tldCsv': tldFname = arg
        elif opt == '-l':
            if arg == '-':
                log.addHandler(logging.StreamHandler())
            else:
                log.addHandler(logging.FileHandler(arg))

    tldDb = hva_tld.TldDb()
    tldDb.load(tldFname)

    for hdr, pkt in hva_pcap.open_offline(pcapFname):
        try:
            eth = hva_pckt.Eth.decode(pkt)
            log.debug('Eth: eth=%s', eth)
            if eth:
                ip = hva_pckt.Ip.decode(eth.pl)
                if ip and ip.proto == 6:
                    tcp = hva_pckt.Tcp.decode(ip.pl)
                    if tcp and tcp.flgs == hva_pckt.Tcp.kFlags_SYN:
                        tld = tldDb.findTld(ip.daddr)
                        if tld == 'RU':
                            print('ts={0:26s}, src={1:>15s}:{2:<5d} -> dst={3:>15s}:{4:<5d} tld={5:s}'.format(
                                str(hdr.ts), str(ip.saddr), tcp.sport, str(ip.daddr),  tcp.dport, tld))
        except Exception as e:
            log.exception('Unexpected Exception')

