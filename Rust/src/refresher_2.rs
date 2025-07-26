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

fn print_acc(account: Account) {
    println!("{:#?}", account);
}

fn main() {
    // The goal of ownership is to limit the ways data can be referenced and changed. This
    // limitation reduces the number of bugs and increases legibility of code.
    // Rust avoids "unexpected updates" and expects programmers to do so too.
    // Every value is "owned" by a single variable at a time. Reassigning the value to another
    // variable moves the value. The old variable can't be used to access the value anymore.

    // At first, the bank object that gets created by "Bank::new()" is owned by "bank". When we put
    // bank inside "steal_bank", the bank object is now owned by steal_bank and bank has no
    // ownership of it anymore. Essentially, the bank binding is now empty and hence printing bank
    // will return an error as it contains nothing.
    let bank = Bank::new();
    let steal_bank = bank;
    // let myaccount = Account::new(253, String::from("Mooda"));
    // println!("{:#?}", bank);
    // print_acc(myaccount);
}
