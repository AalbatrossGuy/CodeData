// #[derive(Debug)] is known as attributes. Putting it above a struct defines the attribute of that
// struct. It essentially gives the rust compiler some extra info.
// "derive" is called the derive attribute. It specifies which 'trait' to automatically implement
// for this struct.
// "Debug" is called the "Debug trait". It sets a group of functions for the struct.
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
        let deck = Deck { cards };
        return deck;
    }
    fn print(&self) {
        return println!("From print fn");
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

    let deck = Deck::new();
    let example_array = [1, 2, 3, 4, 5];
    println!("Deck: {:#?}", deck.cards);
    println!("Hello World");
    println!("{:?}", example_array);
    println!("{:?}", deck.print());
}
