import logging

logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)

fileHandler = logging.FileHandler('handler.log')
fileHandler.setFormatter(logging.Formatter('%(levelname)s - %(levelno)s - %(message)s'))
logger.addHandler(fileHandler)


logger.debug('debugging')
logger.info('bla')
logger.warning('debugging')
logger.debug('debugging')
logger.debug('debugging')
logger.error('debugging')
