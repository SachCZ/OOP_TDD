import time
from dataclasses import dataclass

@dataclass
class Transaction:
    total: float


def get_transactions():
    # Slow!!
    time.sleep(5)
    return [Transaction(152), Transaction(-26), Transaction(-2)]


def get_positive_transactions(transactions):
    return [transaction for transaction in transactions if transaction.total > 0]
