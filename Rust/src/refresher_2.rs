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
    // The same happens for print_acc(myaccount). The first print statement moves the myaccount
    // value into it so when the second print statement fetches myaccount's value, it's empty since
    // the value is currently stored in the first print statement.
    let bank = Bank::new();

    // similar to C. & gets a reference to the value of bank. A system of "borrowing"
    // it is basically a read-only reference that creates a "copy" of the original variable, i.e.,
    // bank in this case. & operator used on a parameter means "The argument needs to be a
    // reference to a value", i.e., it only takes values which are reference to another value.
    // & operator used on a value means "create a reference to the value its used on".
    let bank_reference = &bank;
    // let steal_bank = bank;
    // let myaccount = Account::new(253, String::from("Mooda"));
    println!("{:#?}", bank_reference);
    println!("{:#?}", &bank); // Directly passing value as a reference to a value.
    println!("{:#?}", bank);
    // println!("{:#?}", bank.accounts);
    // print_acc(myaccount);
    // print_acc(myaccount);
}
