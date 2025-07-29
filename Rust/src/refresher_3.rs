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
}

impl Account {
    fn new(id: u32, holder: String) -> Self {
        Account {
            id,
            holder,
            balance: 0,
        }
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
    let account = Account::new(2, String::from("Mooda"));
    bank.add_account(account);
    println!("{:#?}", bank);
}
