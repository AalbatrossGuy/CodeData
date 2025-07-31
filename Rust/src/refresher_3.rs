#[derive(Debug)]
struct Account {
    id: u32,
    balance: i32,
    holder: String,
}

#[derive(Debug)]
struct Bank {
    accounts: Vec<Account>,
}

impl Bank {
    fn new() -> Self {
        Bank {
            accounts: Vec::new(),
        }
    }
    fn add_account(&mut self, account: Account) {
        self.accounts.push(account);
    }
    fn total_balance(&self) -> i32 {
        self.accounts.iter().map(|account| account.balance).sum()
    }
    fn summary(&self) -> Vec<String> {
        self.accounts
            .iter()
            .map(|account| account.summary())
            .collect::<Vec<String>>()
    }
}

impl Account {
    fn new(id: u32, holder: String) -> Self {
        Account {
            id,
            holder,
            balance: 0,
        }
    }
    fn deposit(&mut self, amount: &i32) -> i32 {
        self.balance += amount;
        self.balance
    }
    fn withdraw(&mut self, amount: i32) -> i32 {
        self.balance -= amount;
        self.balance
    }
    fn summary(&self) -> String {
        format!("{} has a balance of {}", self.holder, self.balance)
    }
}

// With every function, we need to think about whether we are receiving values or references.
// with every data structure, we need to think about whether we are storing values or references.
// fn make_and_print_account() -> Account {
//     let account = Account::new(1, String::from("Mooda"));
//     println!("{:#?}", account);
//     // After println!() is called on account, the value of account binding, i.e., the 'Account'
//     // object's ownership goes to println!(). So there's no way to use the account binding anymore
//     // since it points to nothing now. This means, the owner went out of scope and hence the owned
//     // by it was dropped.
//     &account
// }

fn main() {
    // Every value is owned by a single variable, argument, struct, vector, etc. at a time.
    // when an owner goes out of scope, the value owned by it is dropped, i.e., cleaned up.
    // There can't be references to a value when its owner goes out of scope.
    // References to a value can't outlive the value they refer to.
    // make_and_print_account();
    // let account_ref = make_and_print_account();
    // println!("{:#?}", account_ref.balance);
    let mut bank = Bank::new();
    let mut account = Account::new(2, String::from("Mooda"));
    account.deposit(&500);
    account.withdraw(150);
    bank.add_account(account);
    println!("{:#?}", bank.summary());
    println!("{}", bank.total_balance());
    // println!("{}", account.summary());
}
