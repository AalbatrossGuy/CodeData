#[derive(Debug)]

struct Deck {
    // names of struct always starts with capital letter.
    // "cards" is the piece of data struct Deck will contain.
    // Vec<> are like arrays that can grow/shrink in size. Syntax: Vec<data-type>
    // Arrays in rust are lists that have fixed length.
    cards: Vec<String>,
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
    let deck = Deck { cards: vec![] };
    println!("Deck: {:?}", deck);
    println!("Hello World");
}
