import unittest
import service
from service import Transaction


class TestServerGetPositiveTransactions(unittest.TestCase):

    def runTest(self):
        transactions = [Transaction(152.5), Transaction(-26.1), Transaction(-2.0)]
        expected_result = [Transaction(152.5)]
        positive_transactions = service.get_positive_transactions(transactions)
        self.assertEqual(len(positive_transactions), len(expected_result))
        for transaction, expected_transaction in zip(positive_transactions, expected_result):
            self.assertAlmostEqual(expected_transaction.total, transaction.total, places=7)


# Test fixture example, not advised in this case
class ServerTestCase(unittest.TestCase):
    def setUp(self):
        self.transactions = [Transaction(152.5), Transaction(-26.1), Transaction(-2.0)]

    def tearDown(self):
        pass  # Useless to override, do not do this unless you need tearDown

    def test_get_positive_transactions(self):
        expected_result = [Transaction(152.5)]
        positive_transactions = service.get_positive_transactions(self.transactions)
        self.assertEqual(len(positive_transactions), len(expected_result))
        for transaction, expected_transaction in zip(positive_transactions, expected_result):
            self.assertAlmostEqual(expected_transaction.total, transaction.total, places=7)
