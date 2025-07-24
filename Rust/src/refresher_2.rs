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
    let bank = Bank::new();
    let myaccount = Account::new(253, String::from("Mooda"));

    println!("{:#?}", bank);
    print_acc(myaccount);
}
