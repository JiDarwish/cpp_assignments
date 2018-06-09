import sys
import logging
import getopt

def raiser(n):
    if n > 0: raiser(n-1)
    raise Exception()

def tester(name):
    log = logging.getLogger(name)
    log.info('Info notice')
    log.debug('Debug notice')
    log.error('Error notice')
    # TODO When an exception is logged, the stack-trace should be printed
    try:
        raiser(3)
    except:
        log.exception('Exception notice')
    log.warning('Warning, all ends')

if __name__ == '__main__':

    name = 'main'
    logfile = '-'
    log = logging.getLogger()
    opts, args = getopt.getopt(sys.argv[1:], '?VDEn:', [ 'logfile=' ])
    for opt, arg in opts:
        if opt == '-?':
            print('Usage: {} -[?VDE] [-n <name>] [--logfile <file.log>]'.format(sys.argv[0]))
            sys.exit()
        elif opt == '-V':
            log.setLevel(logging.INFO)
        elif opt == '--logfile':
            logfile = arg
        # TODO Add options D, e & n
        elif opt == '-D':
            log.setLevel(logging.DEBUG)
        elif opt == '-E':
            log.setLevel(logging.ERROR)
	elif opt == '-n':
	    logfile = arg

    lh = logging.StreamHandler() if logfile == '-' else logging.FileHandler(logfile)
    # TODO Add time to the logformat
    lh.setFormatter(logging.Formatter('%(asctime)s %(name)s  %(message)s'))
    log.addHandler(lh)

    tester(name)
