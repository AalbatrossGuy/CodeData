// #[derive(Debug)] is known as attributes. Putting it above a struct defines the attribute of that
// struct. It essentially gives the rust compiler some extra info.
// "derive" is called the derive attribute. It specifies which 'trait' to automatically implement
// for this struct.
// "Debug" is called the "Debug trait". It sets a group of functions for the struct.
// A package in rust is known as crates.
// Every crate in rust has a root module that consists of functions, structs, etc. Root modules MAY
// have additional submodules. Each submodule can further have more functions, structs, etc.
// In order to use a function,struct, etc. in a crate, use the syntax = crate_name::root_module();
// In order to use a function, struct, etc. in a submodule in a crate, use the syntax =
// crate_name::sub_module::method();
// When using custom modules in the project, the module needs to be imported at the top with the
// syntax "mod <module_name>;" unlike simply calling external crates.
// When using external crates and accessing them, instead of repeatedly calling the whole root +
// submodule + method, use the sytax "use crate_name::root_module_function;" or "use
// crate_name::submodule::function();" at the top of the file to just call "root_module_function()"
// or "function()" while writing the code. Similar to "from <package> import <method>" in python.
// If importing multiple methods from the same external crate, use the syntax "use
// crate_name::{root_module_function, submodule::function};".

use rand::{rng, seq::SliceRandom};

#[derive(Debug)]
struct Deck {
    // names of struct always starts with capital letter.
    // "cards" is the piece of data struct Deck will contain.
    // Vec<> are like arrays that can grow/shrink in size. Syntax: Vec<data-type>
    // Arrays in rust are lists that have fixed length.
    cards: Vec<String>,
}

// Inherent Implementation
// Inherent Implementation should have the same name as the struct. It's a fancy term for "add a
// function to a struct". It is used to define methods & associated functions.
// associated functions == class methods (bruh :/ )
// In the below example, new() doesn't have &self as it's first parameter, hence, it's not a
// method. It's an associated function. In rust, functions that have &self as their first parameter
// are called methods. The ones that do not, are called associated function.
// An associated function is defined when the functionality is not tied a specific instance.
// Something like __self__() in python that defines the parameters global to the class, in this
// case, impl Deck.
impl Deck {
    fn new() -> Self {
        // Self basically tells to return whatever the impl Deck() returns
        let suits = vec!["Hearts", "spades", "Diamonds"];
        let values = vec!["Ace", "Two", "Three"];

        let mut cards = Vec::new();
        for suit in &suits {
            for value in &values {
                let card = format!("{value} of {suit}");
                cards.push(card);
            }
        }
        // If you println!(Deck), it'll give something similar to __repr__ in python's class.
        // If you do Deck.cards, it'll return the value.
        Deck { cards: cards } // Example of implicit return. Rust will return the last executed
                              // expression as long as it doesn't have a semi colon at the end of
                              // it.
                              // return num%2 == 0; is the same as num%2==0
    }
    fn shuffle(&mut self) {
        // &mut self basically means the instance that self gets, can be
        // mutable, i.e, the data inside deck binding, can and would change.
        let mut rng = rng();
        self.cards.shuffle(&mut rng);
    }
    fn deal(&mut self, num_cards: usize) -> Vec<String> {
        // usize data type is used to denote a size or capacity or
        // index into a vector to pull out some particular
        // element. Something like a vector's "limits".
        // This function uses type annotation to tell rust what type of data type is to be
        // returned.
        self.cards.split_off(self.cards.len() - num_cards)
        // the split_off(index) function breaks a vector starting from "index" and returns the new
        // splitted vector. The old vector consists of everything before "index".
        // self.cards.len() gives the total length of the Vec<String> array and subtracts num_cards from it.
        // This gives the position from where the Vec<String> would be splitted. If the array has 0 1 2 3 4 5
        // elements and the last two are desired, we subtract, 6 - 2, which will give the position 4. Since split_off splits
        // from "index" till the end, it'll return a new Vec<String> consisting of elements 4 and 5.
    }
}

fn main() {
    // '!' denotes a macro
    // "" defines a string
    // '' defines a char
    // struct is basically a type of class
    // variables in rust are called bindings
    // "let" is used to declare a new binding
    // deck: Deck is basically type annotation
    // "Deck { cards: vec![] }" creates an empty vector. The "!" indicates it's a macro
    // "vec![]" and "Vec::new()" are used to define empty vectors
    // ":?" is a formatter. It customizes the way values are formatted. It's a Debug formatter
    // ":#?" formats the string by putting array/vector elements in new line for better visibility
    // since no formatted print method is defined in Deck, the attribute gives the formatter a
    // pretty print way to display text
    // Bindings in rust are immutable by default. You've to make them mutable to read/write data.

    let mut deck = Deck::new();
    let example_array = [1, 2, 3, 4, 5];

    let cards = deck.deal(3);

    println!("Deck: {:#?}", deck.cards);
    println!("Hand: {:#?}", cards);
    deck.shuffle();
    println!("Hello World");
    println!("{:?}", example_array);
}
