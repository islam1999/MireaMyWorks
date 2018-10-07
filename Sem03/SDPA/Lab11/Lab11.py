from pprint import pprint
from dataclasses import dataclass
from typing import List
from datetime import datetime
import sys
from bisect import bisect


@dataclass(order=True)
class Bank:
    account_number: int
    amount: float
    fullname: str
    openning_date: datetime

    @classmethod
    def from_file(cls, filename, mode=''):
        banks = []
        with open(filename, 'r' + mode) as f:
            reading_f = Bank.from_string if mode == '' else Bank.from_bytes
            for line in f:
                banks.append(reading_f(line.strip()))
        return banks

    @classmethod
    def to_file(cls, banks, filename, mode=''):
        with open(filename, 'w' + mode) as f:
            writing_f = Bank.to_string if mode == '' else Bank.to_bytes
            new_line = '\n' if mode == '' else b'\n'
            for bank in banks:
                f.write(writing_f(bank) + new_line)

    @classmethod
    def from_string(cls, s):
        s = s.split(';')
        return Bank(
            account_number=int(s[0]),
            amount=float(s[1]),
            fullname=s[2].strip(),
            openning_date=datetime(*(int(e) for e in s[3].split(','))),
        )

    def to_string(self):
        d = self.openning_date
        return '{}; {}; {}; {}'.format(
            self.account_number,
            self.amount,
            self.fullname,
            ', '.join(str(item) for item in (d.year, d.month, d.day,
                                             d.hour, d.minute, d.second, d.microsecond)),
        )

    @classmethod
    def from_bytes(cls, b):
        return cls.from_string(b.decode())

    def to_bytes(self):
        return self.to_string().encode()


def find_bank(banks, account_number):
    return bisect(banks, Bank(account_number, 0, None, None)) - 1


def main():
    banks = Bank.from_file(sys.argv[1])
    print('default:')
    pprint(banks)
    banks.sort()
    print('sorted: ')
    pprint(banks)
    account_number = int(input('bank to find: '))
    print('bank index:', find_bank(banks, account_number))
    Bank.to_file(banks, 'tmp.dat', 'b')
    pprint(Bank.from_file('tmp.dat', 'b'))


if __name__ == '__main__':
    main()
