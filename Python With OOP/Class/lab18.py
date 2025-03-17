class Bank:
    def __init__(self, account_name, initial_balance=0):
        self.account_name = account_name
        self.balance = initial_balance

    def deposit(self, amount):
        self.balance += amount
        print(f"Deposited {amount} Tk. Current balance of Account-> {self.account_name}: {self.balance} Tk")

    def withdraw(self, amount):
        if self.balance >= amount:
            self.balance -= amount
            print(f"Withdrawn {amount} Tk. Current balance of Account-> {self.account_name}: {self.balance} Tk")
        else:
            print("Insufficient funds.")

class Accounts(Bank):
    def apply_loan(self, loan_type, loan_amount):
        print(f"Applying for a {loan_type} loan of {loan_amount} Tk")
        Loan.add_loan(self.account_name, loan_type, loan_amount)

class Loan:
    loan_accounts = []

    @classmethod
    def add_loan(cls, account_name, loan_type, loan_amount):
        cls.loan_accounts.append((account_name, loan_type, loan_amount))
        print(f"Loan Accepted- Current Balance of {account_name} is {Accounts(account_name).balance + loan_amount}")

# Example usage:
shahadat_account = Accounts("Shahadat")
shahadat_account.deposit(100000)
shahadat_account.withdraw(50000)
shahadat_account.apply_loan("Home", 2000000)

mamun_account = Accounts("Mamun", initial_balance=50000)
mamun_account.deposit(10000)
mamun_account.withdraw(50000)
mamun_account.apply_loan("SME", 100000)
