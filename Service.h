#ifndef OOP_PREZENTACE_SERVICE_H
#define OOP_PREZENTACE_SERVICE_H

#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>

struct Transaction {
    double total{0};
};

class Database {
public:
    virtual std::vector<Transaction> getTransactions() const = 0;
};

//Just an example
class SQLDatabase : public Database {
public:
    //Slow!!
    std::vector<Transaction> getTransactions() const override {
        //Never define in header file (unless necessary - templates)
        std::this_thread::sleep_for(std::chrono::seconds (5));
        return {Transaction{2156.4}, Transaction{-36.5}};
    }
};

class MongoDB : public Database {
public:
    std::vector<Transaction> getTransactions() const override {
        std::this_thread::sleep_for(std::chrono::seconds (6));
        return {Transaction{156.4}, Transaction{-3601.5}};
    }
};


class Server {
public:
    explicit Server(const Database *database) : database(*database) {}

    std::vector<Transaction> getPositiveTransactions() const {
        std::vector<Transaction> result;
        auto transactions = database.getTransactions();
        std::copy_if(
                std::begin(transactions),
                std::end(transactions),
                std::back_inserter(result),
                [](const auto &transaction) {
                    return transaction.total > 0;
                }
        );
        return result;
    }

private:
    const Database &database;
};


#endif //OOP_PREZENTACE_SERVICE_H
