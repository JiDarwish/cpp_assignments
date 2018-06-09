# /usr/bin/env python3
# (c) 2018 Frans Schippers f.h.schippers@hva.nl

import csv

import unittest


class BankException(Exception):
    pass


class HvaBank:
    def __init__(self):
        self._accounts = {}

    def save(self, fname):
        with open(fname, 'w') as fp:
            wtr = csv.writer(fp, delimiter=' ',
                             quotechar='|', quoting=csv.QUOTE_MINIMAL)
            for name, amount in self._accounts.items():
                wtr.writerow((name, amount))

    def load(self, fname):
        with open(fname, 'r') as fp:
            rdr = csv.reader(fp, delimiter=' ',
                             quotechar='|', quoting=csv.QUOTE_MINIMAL)
            for row in rdr:
                self._accounts[row[0]] = int(row[1])

    def openAccount(self, name):
        """ Open in rekening met naam <name>, het begin saldo is 0. """
        if name in self._accounts:
            raise BankException("Account exists")
        self._accounts[name] = 0

    def checkAccount(self, name):
        """ Geeft aan hoeveel op de rekening staat. """
        if name not in self._accounts:
            raise BankException("Account doesn't exist")
        return self._accounts[name]

    def closeAccount(self, name):
        """ Sluit in rekening met naam <name>, het saldo moet 0 zijn. """
        if name not in self._accounts:
            raise BankException("Account doesn't exist")
        if self._accounts[name] != 0:
            raise BankException("Account is not empty")
        del self._accounts[name]

    def deposit(self, name, amount):
        """ Stort geld op de rekening """
        if name not in self._accounts:
            raise BankException("Account doesn't exist")
        if amount < 0:
            raise BankException("Amount must be positive")
        self._accounts[name] += amount

    def withdraw(self, name, amount):
        """ Neem geld op van de rekening """
        if name not in self._accounts:
            raise BankException("Account doesn't exist")
        if amount > self._accounts[name]:
            raise BankException("WithDraw not allowed")
        self._accounts[name] -= amount

    def transfer(self, name1, name2, amount):
        """ Maak geld over naar een ander """
        if name1 not in self._accounts:
            raise BankException("Account doesn't exist")
        if name2 not in self._accounts:
            raise BankException("Account doesn't exist")
        if amount > self._accounts[name2] + 50:
            raise BankException("Transfer not allowed")
        self._accounts[name1] -= amount
        self._accounts[name2] += amount

    def balance(self):
        """ Hulp routine print overzicht """
        for name in self._accounts.keys():
            print('{0:10s}: {1:4d}'.format(name, self._accounts[name]))
        print('-'*16)


# Hier komen de unittest

class bankTest(unittest.TestCase):
    ################## Helpers ###################################################
    def createAccountAddMoney(self, bank, name, money):
        bank.openAccount(name)
        bank.deposit(name, money)
    ##############################################################################

    def setUp(self):
        self.bank = HvaBank()

    def tearDown(self):
        del self.bank

    # Test 1
    def test_openAccount(self):
        '''
            Openaccount test
            1- Can open an account with a specific name
            2- Initial balance 0
            3- Trying to create more than one account with same name raises BankException
        '''
        self.bank.openAccount('Ji')

        try:
            self.assertEqual(self.bank.checkAccount('Ji'), 0)
        except BankException:
            self.fail('Test threw an exception')

        with self.assertRaises(BankException):
            self.bank.openAccount('Ji')

    # Test 2
    def test_deposit(self):
        '''
            deposit test:
            1- Raises BankException if no account associated with the name exists
            2- Raises BankException if depositing a negative number
            3- Able to deposit money normally
        '''
        # 1
        with self.assertRaises(BankException):
            self.bank.deposit('Ji', 100)

        self.bank.openAccount('Ji')

        # 2
        with self.assertRaises(BankException):
            self.bank.deposit('Ji', -100)

        self.bank.deposit('Ji', 100)
        # 3
        self.assertEqual(self.bank.checkAccount('Ji'), 100)

    # Test 2
    def test_withdraw(self):
        '''
            withdraw test:
            1- Raises BankException if no account associated with the name exists
            2- Raises BankException if withdrawing a number greater than balance in account
            3- Able to withdraw money normally
        '''
        # 1
        with self.assertRaises(BankException):
            self.bank.withdraw('Ji', 1000)

        self.bank.openAccount('Ji')

        # 2
        with self.assertRaises(BankException):
            self.bank.withdraw('Ji', 1000)

        self.bank.deposit('Ji', 100)  # add money
        # 3
        self.bank.withdraw('Ji', 60)
        self.assertEqual(self.bank.checkAccount('Ji'), 40)

    def test_transfer(self):
        '''
        Transfer test:
        1- Cannot make transfer if any of the names has no account yet
        2- Cannot make a transfer if the initiating account doesn't have enough balance
        3- expect money to be taken from initiating account
        4- expect moeny to be added to receiving account
        '''
        # 1
        with self.assertRaises(BankException):
            self.bank.transfer('Ji', 'Emeri', 10)

        self.createAccountAddMoney(self.bank, 'Ji', 100)
        self.createAccountAddMoney(self.bank, 'Emeri', 1000)

        # 2
        with self.assertRaises(BankException):
            self.bank.transfer('Ji', 'Emeri', 1000000)

        self.bank.transfer('Ji', 'Emeri', 10)

        # 3
        self.assertEqual(self.bank.checkAccount('Ji'), 100 - 10)
        # 4
        self.assertEqual(self.bank.checkAccount('Emeri'), 1000 + 10)

    def test_closeAccount(self):
        '''
            Close account test:
            1- Trying to close an unexisting account raises a BankException
            2- Trying to close an account with balance higher than 0 raises a BankException
            3- Closing an account with balance of 0 works fine
        '''
        with self.assertRaises(BankException):
            self.bank.closeAccount('Ji')

        self.createAccountAddMoney(self.bank, 'Ji', 100)

        with self.assertRaises(BankException):
            self.bank.closeAccount('Emeri')

        self.bank.openAccount('Emeri')
        self.bank.closeAccount('Emeri')

        with self.assertRaises(BankException):
            self.bank.checkAccount('Emeri')  # Account does not exist

    def test_save(self):
        self.createAccountAddMoney(self.bank, 'Ji', 1000)
        self.createAccountAddMoney(self.bank, 'Emeri', 2000)

        self.bank.save('bank.csv')

        with open('bank.csv') as file:
            content = file.read()
            self.assertTrue('Emeri 2000' in content)
            self.assertTrue('Ji 1000' in content)

    def test_load(self):
        self.createAccountAddMoney(self.bank, 'Ji', 1000)
        self.createAccountAddMoney(self.bank, 'Emeri', 2000)

        self.bank.save('testLoading.csv')

        bank2 = HvaBank()
        bank2.load('testLoading.csv')

        self.assertEqual(bank2.checkAccount('Ji'), 1000)
        self.assertEqual(bank2.checkAccount('Emeri'), 2000)


if __name__ == '__main__':
    unittest.main()
    # Onderstaande mag weg
    # hb = HvaBank()
    # hb.openAccount('frans')
    # hb.deposit('frans', 100)
    # hb.withdraw('frans', 50)
    # hb.openAccount('Ji')
    # hb.transfer('frans', 'Ji', 10)
    # hb.save('bank.csv')
    # hb.balance()
    # hb.load('bank.csv')
    # hb.transfer('frans', 'Ji', 10)
    # hb.balance()
